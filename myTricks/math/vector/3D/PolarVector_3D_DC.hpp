#ifndef _POLARVECTOR_3D_DC_HPP_INCLUDED_
# define _POLARVECTOR_3D_DC_HPP_INCLUDED_


/**********************************************************************\
* This is an internal header file, included by other library headers.  *
* Do not attempt to use it directly.
*
* using Derived Classes.
\**********************************************************************/


# include "../PolarVector.hpp"
# include "LinearVector_3D_DC.hpp"


# if !(defined FUNC_ASIN && defined FUNC_ATAN2)
#  include <cmath>
#  ifndef FUNC_ASIN
#   define FUNC_ASIN ::std::asin
#  endif // FUNC_ASIN
#  ifndef FUNC_ATAN2
#   define FUNC_ATAN2 ::std::atan2
#  endif // FUNC_ATAN2
# endif // FUNC_ASIN FUNC_ATAN2


namespace mytricks {

namespace math {

// 定义一个通用的3D球极坐标向量类
template<typename Number>
class PolarVector3 : public PolarVector<Number, 3> {

    typedef PolarVector3<Number>    _PolarVector3;
    typedef PolarVector<Number, 3>  _Base;

#define rphithetaptr    _Base::array
#define rVal            rphithetaptr[0]
#define phiVal          rphithetaptr[1]
#define thetaVal        rphithetaptr[2]

    typedef LinearVector<Number, 3> _LinearVector3Base;
    typedef LinearVector3<Number>   _LinearVector3;

public:
    typedef Number  value_type;

// 基本功能
    PolarVector3 (void) : _Base()   // 默认构造函数 xVal = yVal = zVal = 0
    {
        ;   // no-op
    }

    PolarVector3 (Number rv, Number phiv, Number thetav)    // 构造函数
    {
        this->rVal = rv;
        this->phiVal = phiv;
        this->thetaVal = thetav;
    }

    explicit PolarVector3 (const Number* ptr) : _Base(ptr)  // Constructor
    {
        ;   // no-op
    }

    explicit PolarVector3 (const _LinearVector3Base& v) : _Base()
    {
        _LinearVector3 v1(v);
        this->rVal = v1.length();
        if (this->rVal >= EPSILON) {
            this->phiVal = Number(FUNC_ATAN2(v1.y(), v1.x()));
            this->thetaVal = Number(FUNC_ASIN(v1.z() / this->rVal));
        } else {
            this->phiVal =
            this->thetaVal = Number(0.0);
        }
    }

    // 复制构造函数
    PolarVector3 (const _Base& v) : _Base(v)
    {
        ;   // no-op
    }
/*
    // 重载赋值运算符
    PolarVector3& operator= (const PolarVector3& v)
    {
        if (&v != this) {
            this->rVal = v.rVal;
            this->phiVal = v.phiVal;
            this->thetaVal = v.thetaVal;
        }
        return *this;
    }
*/
    /*!virtual */~PolarVector3 () {}

    Number r(void) const {return this->rVal;}           // get
    Number& r(void) {return this->rVal;}
    Number phi(void) const {return this->phiVal;}       // get
    Number& phi(void) {return this->phiVal;}
    Number theta(void) const {return this->thetaVal;}   // get
    Number& theta(void) {return this->thetaVal;}
    const Number *rphitheta(void) const {return this->rphithetaptr;}    // get_ptr
/********************************/

// 线性关系
    PolarVector3& operator*= (Number value)
    {
        this->rVal *= value;
        return *this;
    }

    const PolarVector3 operator* (Number value) const   // 数乘
    {
        return PolarVector3(*this) *= value;
    }

    friend const PolarVector3 operator* (Number value, const PolarVector3& v)
    {
        return PolarVector3(v) *= value;
    }

    PolarVector3& operator/= (Number value)
    {
        if (fabs(value) >= EPSILON) {
            this->rVal /= value;
        } else {
            ;   // divided by zValero!
        }
        return *this;
    }

    const PolarVector3 operator/ (Number value) const   // 数除
    {
        return PolarVector3(*this) /= value;
    }

/********************************\

// 双线性关系
    Number dot (const PolarVector3& v) const            // dot product
    {
        ;
    }

    const PolarVector3 cross (const PolarVector3& v) const  // 矢积
    {
        ;
    }
\********************************/

/*2范数*/
    Number length (void) const                  // 返回长度
    {
        return this->rVal;
    }

    Number lengthSquared (void) const           // 返回长度的平方
    {
        return this->rVal * this->rVal;
    }

    PolarVector3& unitize (void)                // 归一化
    {
        if (this->rVal < EPSILON) {
            ;   // no-op
        }
        this->rVal = Number(1.0);
        return *this;
    }

    const PolarVector3 unit (void) const        // 返回单位向量
    {
        return PolarVector3(*this).unitize();
    }
/********************************/

#undef thetaVal
#undef phiVal
#undef rVal
#undef rphithetaptr


}; // class PolarVector3<Number>

/*
typedef PolarVector3<float> PolarVector3f;
typedef PolarVector3<double> PolarVector3d;
*/

} // namespace math

} // namespace mytricks


#endif // _POLARVECTOR_3D_DC_HPP_INCLUDED_
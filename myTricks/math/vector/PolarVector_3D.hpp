#ifndef _POLARVECTOR_3D_HPP_INCLUDED_
# define _POLARVECTOR_3D_HPP_INCLUDED_


/**********************************************************************\
*
*
\**********************************************************************/


# include "PolarVector.hpp"
# include "Vector_3D.hpp"


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
public:
    typedef PolarVector<Number, 3> _PolarVector3Base;
    typedef PolarVector3<Number> _PolarVector3;

#define rphithetaptr PolarVector<Number, 3>::array
#define rval rphithetaptr[0]
#define phival rphithetaptr[1]
#define thetaval rphithetaptr[2]

    typedef Vector3<Number> _Vector3;

// 基本功能
    PolarVector3 (void) : _PolarVector3Base()       // 默认构造函数 xval = yval = zval = 0
    {
        ;   // no-op
    }

    PolarVector3 (Number rv, Number phiv, Number thetav)        // 构造函数
    {
        this->rval = rv;
        this->phival = phiv;
        this->thetaval = thetav;
    }

    explicit PolarVector3 (const Number* ptr) : _PolarVector3Base(ptr)  // Constructor
    {
        ;   // no-op
    }

    explicit PolarVector3 (const _Vector3& v) : _PolarVector3Base()
    {
        this->rval = v.length();
        if (this->rval >= EPSILON) {
            this->phival = Number(FUNC_ATAN2(v.y(), v.x()));
            this->thetaval = Number(FUNC_ASIN(v.z() / this->rval));
        } else {
            this->phival =
            this->thetaval = Number(0.0);
        }
    }

    // 复制构造函数
    PolarVector3 (const _PolarVector3Base& v) : _PolarVector3Base(v)
    {
        ;   // no-op
    }
/*
    // 拷贝构造函数
    PolarVector3 (const _PolarVector3& v) : _PolarVector3Base(v)
    {
        ;   // no-op
    }

    // 重载赋值运算符
    _PolarVector3& operator= (const _PolarVector3& v)
    {
        if (&v != this) {
            this->rval = v.rval;
            this->phival = v.phival;
            this->thetaval = v.thetaval;
        }
        return *this;
    }
*/
    Number r(void) const {return this->rval;}           // get
    Number& r(void) {return this->rval;}
    Number phi(void) const {return this->phival;}       // get
    Number& phi(void) {return this->phival;}
    Number theta(void) const {return this->thetaval;}   // get
    Number& theta(void) {return this->thetaval;}
    const Number *rphitheta(void) const {return this->rphithetaptr;}    // get_ptr
/********************************/

// 线性关系
    _PolarVector3& operator/= (Number value)
    {
        if (fabs(value) >= EPSILON) {
            this->rval /= value;
        } else {
            ;   // divided by zvalero!
        }
        return *this;
    }

    _PolarVector3 operator/ (Number value) const    // 数除
    {
        return PolarVector3(*this) /= value;
    }

/********************************/
/*
// 双线性关系
    Number dot (const _PolarVector3& v) const           // dot product
    {
        ;
    }

    _PolarVector3 cross (const _PolarVector3& v) const  // 矢积
    {
        ;
    }*/
/********************************/

/*2范数*/
    Number length (void) const                  // 返回长度
    {
        return this->rval;
    }

    Number lengthSquared (void) const           // 返回长度的平方
    {
        return this->rval * this->rval;
    }

    _PolarVector3& unitize (void)               // 归一化
    {
        if (this->rval < EPSILON) {
            ;   // no-op
        }
        this->rval = Number(1.0);
        return *this;
    }

    _PolarVector3 unit (void) const             // 返回单位向量
    {
        return PolarVector3(*this).unitize();
    }
/********************************/

#undef thetaval
#undef phival
#undef rval
#undef rphithetaptr


}; // class PolarVector3<Number>

/*
typedef PolarVector3<float> PolarVector3f;
typedef PolarVector3<double> PolarVector3d;
*/

} // namespace math

} // namespace mytricks


#endif // _POLARVECTOR_3D_HPP_INCLUDED_
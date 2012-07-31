#ifndef _POLARVECTOR_3D_CTPS_HPP_INCLUDED_
# define _POLARVECTOR_3D_CTPS_HPP_INCLUDED_


/**********************************************************************\
* This is an internal header file, included by other library headers.  *
* Do not attempt to use it directly.
*
* using Class-Template Partial Specializations.
\**********************************************************************/


# include "../PolarVector.hpp"
# include "LinearVector_3D_CTPS.hpp"


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
class PolarVector<Number, 3> {

    typedef PolarVector<Number, 3>  _PolarVector3;

    typedef LinearVector<Number, 3> _LinearVector3;

public:
    typedef Number  value_type;

// 基本功能
    PolarVector (void)      // Default Constructor, xVal = yVal = zVal = 0
    {
        this->setZero();
    }

    PolarVector (Number rv, Number phiv, Number thetav)     // Constructor
    {
        this->rVal = rv;
        this->phiVal = phiv;
        this->thetaVal = thetav;
    }

    explicit PolarVector (const Number* ptr)    // Constructor
    {
        if (NULL != ptr) {
            this->rVal = ptr[0];
            this->phiVal = ptr[1];
            this->thetaVal = ptr[2];
        } else {
            this->setZero();
        }
    }

    explicit PolarVector (const _LinearVector3& v)
    {
        this->rVal = v.length();
        if (this->rVal >= EPSILON) {
            this->phiVal = Number(FUNC_ATAN2(v.y(), v.x()));
            this->thetaVal = Number(FUNC_ASIN(v.z() / this->rVal));
        } else {
            this->phiVal =
            this->thetaVal = Number(0.0);
        }
    }

    // Copy Constructor
    PolarVector (const PolarVector& v)
    {
        this->rVal = v.rVal;
        this->phiVal = v.phiVal;
        this->thetaVal = v.thetaVal;
    }

    // Assignment Operator
    PolarVector& operator= (const PolarVector& v)
    {
        if (&v != this) {
            this->rVal = v.rVal;
            this->phiVal = v.phiVal;
            this->thetaVal = v.thetaVal;
        }
        return *this;
    }

    /*!virtual */~PolarVector () {}

    void setZero (void)
    {
        this->rVal = this->phiVal = this->thetaVal = Number(0);
        return;
    }

    _LinearVector3 toLinear (void) const
    {
        Number tmp[3] = {0};
        tmp[0] = this->array[0];
        for (unsigned int i = 2; i > 0; --i) {
            tmp[i] = tmp[0] * Number(FUNC_SIN(this->array[i]));
            tmp[0] *= Number(FUNC_COS(this->array[i]));
        }
        return _LinearVector3(tmp);
    }

    Number r(void) const {return this->rVal;}           // get
    Number& r(void) {return this->rVal;}
    Number phi(void) const {return this->phiVal;}       // get
    Number& phi(void) {return this->phiVal;}
    Number theta(void) const {return this->thetaVal;}   // get
    Number& theta(void) {return this->thetaVal;}
    const Number *rphitheta(void) const {return this->rphithetaVal;}    // get_ptr
/********************************/

// 线性关系
    PolarVector& operator*= (Number value)
    {
        this->rVal *= value;
        return *this;
    }

    const PolarVector operator* (Number value) const    // 数乘
    {
        return PolarVector(*this) *= value;
    }

    friend const PolarVector operator* (Number value, const PolarVector& v)
    {
        return PolarVector(v) *= value;
    }

    PolarVector& operator/= (Number value)
    {
        if (fabs(value) >= EPSILON) {
            this->rVal /= value;
        } else {
            ;   // divided by zValero!
        }
        return *this;
    }

    const PolarVector operator/ (Number value) const    // 数除
    {
        return PolarVector(*this) /= value;
    }

/********************************\

// 双线性关系
    Number dot (const PolarVector& v) const         // dot product
    {
        ;
    }

    const PolarVector cross (const PolarVector& v) const    // 矢积
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

    PolarVector& unitize (void)                 // 归一化
    {
        if (this->rVal < EPSILON) {
            ;   // no-op
        }
        this->rVal = Number(1.0);
        return *this;
    }

    const PolarVector unit (void) const         // 返回单位向量
    {
        return PolarVector(*this).unitize();
    }
/********************************/

protected:
    union {
        struct {
            Number  rVal, phiVal, thetaVal;
        };
        Number  rphithetaVal[3];
        Number  array[3];               // Data Member
    };


}; // class PolarVector<Number, 3>

/*
typedef PolarVector<float, 3> PolarVector3f;
typedef PolarVector<double, 3> PolarVector3d;
*/


template<typename Number>
class PolarVector3 : public PolarVector<Number, 3> {

    typedef PolarVector<Number, 3>  _Base;

    typedef LinearVector<Number, 3> _LinearVector3;

public:
    typedef Number  value_type;

// 基本功能
    PolarVector3 (void) : _Base()       // 默认构造函数 xVal = yVal = zVal = 0
    {
        ;   // no-op
    }

    PolarVector3 (Number rv, Number phiv, Number thetav) : _Base(rv, phiv, thetav)      // 构造函数
    {
        ;   // no-op
    }

    explicit PolarVector3 (const Number* ptr) : _Base(ptr)  // Constructor
    {
        ;   // no-op
    }

    explicit PolarVector3 (const _LinearVector3& v) : _Base(v)
    {
        ;   // no-op
    }

    // 复制构造函数
    PolarVector3 (const _Base& v) : _Base(v)
    {
        ;   // no-op
    }


}; // class PolarVector3<Number>

} // namespace math

} // namespace mytricks


#endif // _POLARVECTOR_3D_CTPS_HPP_INCLUDED_
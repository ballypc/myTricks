#ifndef _LINEARVECTOR_3D_DC_HPP_INCLUDED_
# define _LINEARVECTOR_3D_DC_HPP_INCLUDED_ 1


/**********************************************************************\
* This is an internal header file, included by other library headers.  *
* Do not attempt to use it directly.
*
* using Derived Classes.
\**********************************************************************/


# include "../LinearVector.hpp"


# ifndef FUNC_SQRT
#  include <cmath>
#  define FUNC_SQRT ::std::sqrt
# endif // FUNC_SQRT

# ifndef EPSILON
#  define EPSILON   1.0e-10
# endif // EPSILON


namespace mytricks {

namespace math {

// 定义一个通用的3D向量类
template<typename Number>
class LinearVector3 : public LinearVector<Number, 3> {

    typedef LinearVector3<Number>   _LinearVector3;
    typedef LinearVector<Number, 3> _Base;

#define xyzptr  _Base::array
#define xVal    xyzptr[0]
#define yVal    xyzptr[1]
#define zVal    xyzptr[2]

public:
    typedef Number  value_type;

// 基本功能
    LinearVector3 (void) : _Base()      // 默认构造函数 xVal = yVal = zVal = 0
    {
        ;   // no-op
    }

    LinearVector3 (Number xv, Number yv, Number zv)     // 构造函数
    {
        this->xVal = xv;
        this->yVal = yv;
        this->zVal = zv;
    }

    LinearVector3 (const Number* ptr) : _Base(ptr)      // Constructor
    {
        ;   // no-op
    }

    // 复制构造函数
    LinearVector3 (const _Base& v) : _Base(v)
    {
        ;   // no-op
    }
/*
    // 重载赋值运算符
    LinearVector3& operator= (const _Base& v)
    {
        if (&v != this) {
            this->xVal = v.xVal;
            this->yVal = v.yVal;
            this->zVal = v.zVal;
        }
        return *this;
    }
*/
    /*!virtual */~LinearVector3 () {}

    Number x(void) const {return this->xVal;}       // get
//    Number& x(void) {return this->xVal;}
    Number y(void) const {return this->yVal;}       // get
//    Number& y(void) {return this->yVal;}
    Number z(void) const {return this->zVal;}       // get
//    Number& z(void) {return this->zVal;}
    const Number *xyz(void) const {return this->xyzptr;}    // get_ptr
/********************************/

// 线性关系
/*
    LinearVector3& operator+= (const LinearVector3& v)
    {
        xVal += v.xVal;
        yVal += v.yVal;
        zVal += v.zVal;
        return *this;
    }

    LinearVector3& operator-= (const LinearVector3& v)
    {
        xVal -= v.xVal;
        yVal -= v.yVal;
        zVal -= v.zVal;
        return *this;
    }

    const LinearVector3 operator- (void) const
    {
        return Vector3(-xVal, -yVal, -zVal);
    }

    LinearVector3& operator*= (Number value)
    {
        xVal *= value;
        yVal *= value;
        zVal *= value;
        return *this;
    }
*/
    LinearVector3& operator+= (const _Base& v)
    {
        this->_Base::operator+=(v);
        return *this;
    }

    const LinearVector3 operator+ (const _Base& v) const    // 加
    {
        return LinearVector3(*this) += v;
    }

    LinearVector3& operator-= (const _Base& v)
    {
        this->_Base::operator-=(v);
        return *this;
    }

    const LinearVector3 operator- (const _Base& v) const    // 减
    {
        return LinearVector3(*this) -= v;
    }

    const LinearVector3 operator- (void) const
    {
        return this->_Base::operator-();
    }

    LinearVector3& operator*= (Number value)
    {
        this->_Base::operator*=(value);
        return *this;
    }

    const LinearVector3 operator* (Number value) const      // 数乘
    {
        return LinearVector3(*this) *= value;
    }

    friend const LinearVector3 operator* (Number value, const LinearVector3& v)
    {
        return LinearVector3(v) *= value;
    }

    LinearVector3& operator/= (Number value)
    {
        if (fabs(value) >= EPSILON) {
            this->xVal /= value;
            this->yVal /= value;
            this->zVal /= value;
        } else {
            ;   // divided by zero!
        }
        return *this;
    }

    const LinearVector3 operator/ (Number value) const      // 数除
    {
        return LinearVector3(*this) /= value;
    }
/********************************/

// 双线性关系
    Number dot (const _Base& v) const       // dot product
    {
        return this->innerProduct(v);
    }

    const LinearVector3 cross (const LinearVector3& v) const    // 矢积
    {
        return LinearVector3(
            this->yVal * v.zVal - this->zVal * v.yVal,
            this->zVal * v.xVal - this->xVal * v.zVal,
            this->xVal * v.yVal - this->yVal * v.xVal   );
    }
/********************************/

/*2范数*/
    Number lengthSquared (void) const           // 返回长度的平方
    {
        return this->dot(*this);
    }

    Number length (void) const                  // 返回长度
    {
        return Number(FUNC_SQRT(this->lengthSquared()));
    }

    LinearVector3& unitize (void)               // 归一化
    {
        Number length = this->length();

        if (length >= EPSILON) {
            this->xVal /= length;
            this->yVal /= length;
            this->zVal /= length;
        } else {
            this->xVal = Number(1.0);
            this->yVal = this->zVal = Number(0.0);
        }

        return *this;
    }

    const LinearVector3 unit (void) const       // 返回单位向量
    {
        return LinearVector3(*this).unitize();
    }
/********************************/

#undef zVal
#undef yVal
#undef xVal
#undef xyzptr


}; // class LinearVector3<Number>

/*
typedef LinearVector3<float> LinearVector3f;
typedef LinearVector3<double> LinearVector3d;
*/

} // namespace math

} // namespace mytricks


#endif // _LINEARVECTOR_3D_DC_HPP_INCLUDED_
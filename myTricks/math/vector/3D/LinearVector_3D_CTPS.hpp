#ifndef _LINEARVECTOR_3D_CTPS_HPP_INCLUDED_
# define _LINEARVECTOR_3D_CTPS_HPP_INCLUDED_ 1


/**********************************************************************\
* This is an internal header file, included by other library headers.  *
* Do not attempt to use it directly.
*
* using Class-Template Partial Specializations.
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

// ����һ��ͨ�õ�3D������
template<typename Number>
class LinearVector<Number, 3> {

    typedef LinearVector<Number, 3> _LinearVector3;

public:
    typedef Number  value_type;

// ��������
    LinearVector (void)     // Default Constructor, xVal = yVal = zVal = 0
    {
        this->setZero();
    }

    LinearVector (Number xv, Number yv, Number zv)  // ���캯��
    {
        this->xVal = xv;
        this->yVal = yv;
        this->zVal = zv;
    }

    LinearVector (const Number* ptr)    // Constructor
    {
        if (NULL != ptr) {
            this->xVal = ptr[0];
            this->yVal = ptr[1];
            this->zVal = ptr[2];
        } else {
            this->setZero();
        }
    }

    // Copy Constructor
    LinearVector (const LinearVector& v)
    {
        xVal = v.xVal;
        yVal = v.yVal;
        zVal = v.zVal;
    }

    // Assignment Operator
    LinearVector& operator= (const LinearVector& v)
    {
        if (&v != this) {
            xVal = v.xVal;
            yVal = v.yVal;
            zVal = v.zVal;
        }
        return *this;
    }

    /*!virtual */~LinearVector () {}

    void setZero (void)
    {
        this->xVal = this->yVal = this->zVal = Number(0);
        return;
    }


    Number x(void) const {return this->xVal;}       // get
//    Number& x(void) {return this->xVal;}
    Number y(void) const {return this->yVal;}       // get
//    Number& y(void) {return this->yVal;}
    Number z(void) const {return this->zVal;}       // get
//    Number& z(void) {return this->zVal;}
    const Number *xyz(void) const {return this->xyzVal;}    // get_ptr
/********************************/

// ���Թ�ϵ
// Linear Functions
    Number sum (void) const
    {
        return Number(xVal + yVal + zVal);
    }

    LinearVector& operator+= (const LinearVector& v)
    {
        xVal += v.xVal;
        yVal += v.yVal;
        zVal += v.zVal;
        return *this;
    }

    const LinearVector operator+ (const LinearVector& v) const  // ��
    {
        return LinearVector(*this) += v;
    }

    LinearVector& operator-= (const LinearVector& v)
    {
        xVal -= v.xVal;
        yVal -= v.yVal;
        zVal -= v.zVal;
        return *this;
    }

    const LinearVector operator- (const LinearVector& v) const  // ��
    {
        return LinearVector(*this) -= v;
    }

    const LinearVector operator- (void) const
    {
        return LinearVector(-xVal, -yVal, -zVal);
    }

    LinearVector& operator*= (Number value)
    {
        xVal *= value;
        yVal *= value;
        zVal *= value;
        return *this;
    }

    const LinearVector operator* (Number value) const   // ����
    {
        return LinearVector(*this) *= value;
    }

    friend const LinearVector operator* (Number value, const LinearVector& v)
    {
        return LinearVector(v) *= value;
    }

    LinearVector& operator/= (Number value)
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

    const LinearVector operator/ (Number value) const   // ����
    {
        return LinearVector(*this) /= value;
    }
/********************************/

// ˫���Թ�ϵ
// Bilinear Functions
    LinearVector& scale (const LinearVector& v)
    {
        xVal *= v.xVal;
        yVal *= v.yVal;
        zVal *= v.zVal;
        return *this;
    }

    const LinearVector directProduct (const LinearVector& v) const
    {
        return LinearVector(*this).scale(v);
    }

    Number innerProduct (const LinearVector& v) const
    {
        return Number(  xVal * v.xVal +
                        yVal * v.yVal +
                        zVal * v.zVal   );
//        return (this->directProduct(v).sum());
    }

    Number dot (const LinearVector& v) const            // dot product
    {
        return this->innerProduct(v);
    }

    const LinearVector cross (const LinearVector& v) const  // ʸ��
    {
        return LinearVector(
            this->yVal * v.zVal - this->zVal * v.yVal,
            this->zVal * v.xVal - this->xVal * v.zVal,
            this->xVal * v.yVal - this->yVal * v.xVal   );
    }
/********************************/

/*2����*/
    Number lengthSquared (void) const           // ���س��ȵ�ƽ��
    {
        return this->dot(*this);
    }

    Number length (void) const                  // ���س���
    {
        return Number(FUNC_SQRT(this->lengthSquared()));
    }

    LinearVector& unitize (void)                // ��һ��
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

    const LinearVector unit (void) const        // ���ص�λ����
    {
        return LinearVector(*this).unitize();
    }
/********************************/


protected:
    union {
        struct {
            Number  xVal, yVal, zVal;
        };
        Number  xyzVal[3];
        Number  array[3];               // Data Member
    };


}; // class LinearVector<Number, 3>

/*
typedef LinearVector<float, 3> LinearVector3f;
typedef LinearVector<double, 3> LinearVector3d;
*/


template<typename Number>
class LinearVector3 : public LinearVector<Number, 3> {

    typedef LinearVector<Number, 3> _Base;

public:
    typedef Number  value_type;

// ��������
    LinearVector3 (void) : _Base()  // Ĭ�Ϲ��캯�� xVal = yVal = zVal = 0
    {
        ;   // no-op
    }

    LinearVector3 (Number xv, Number yv, Number zv) : _Base(xv, yv, zv) // ���캯��
    {
        ;   // no-op
    }

    LinearVector3 (const Number* ptr) : _Base(ptr)  // Constructor
    {
        ;   // no-op
    }

    // ���ƹ��캯��
    LinearVector3 (const _Base& v) : _Base(v)
    {
        ;   // no-op
    }


}; // class LinearVector3<Number>

} // namespace math

} // namespace mytricks


#endif // _LINEARVECTOR_3D_CTPS_HPP_INCLUDED_
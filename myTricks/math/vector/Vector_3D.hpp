#ifndef _VECTOR_3D_HPP_INCLUDED_
# define _VECTOR_3D_HPP_INCLUDED_ 1


/**********************************************************************\
*
*
\**********************************************************************/


# include "LinearVector.hpp"


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
class Vector3 : public LinearVector<Number, 3> {
public:
#define xval LinearVector<Number, 3>::array[0]
#define yval LinearVector<Number, 3>::array[1]
#define zval LinearVector<Number, 3>::array[2]
#define xyzptr LinearVector<Number, 3>::array

    typedef LinearVector<Number, 3> _LinearVector3;
    typedef Vector3<Number> _Vector3;

// ��������
    Vector3 (void) : _LinearVector3()   // Ĭ�Ϲ��캯�� xval = yval = zval = 0
    {
        ;   // no-op
    }

    Vector3 (Number xv, Number yv, Number zv)   // ���캯��
    {
        this->xval = xv;
        this->yval = yv;
        this->zval = zv;
    }

    Vector3 (const Number* ptr) : _LinearVector3(ptr)   // Constructor
    {
        ;   // no-op
    }

    // ���ƹ��캯��
    Vector3 (const _LinearVector3& v) : _LinearVector3(v)
    {
        ;   // no-op
    }
/*
    // �������캯��
    Vector3 (const _Vector3& v) : _LinearVector3(v)
	{
        ;   // no-op
    }

    // ���ظ�ֵ�����
    _Vector3& operator= (const _Vector3& v)
    {
        if (&v != this) {
            this->xval = v.xval;
            this->yval = v.yval;
            this->zval = v.zval;
        }
        return *this;
    }
*/
    Number x(void) const {return this->xval;}       // get
//    Number& x(void) {return this->xval;}
    Number y(void) const {return this->yval;}       // get
//    Number& y(void) {return this->yval;}
    Number z(void) const {return this->zval;}       // get
//    Number& z(void) {return this->zval;}
    const Number *xyz(void) const {return this->xyzptr;}    // get_ptr
/********************************/

// ���Թ�ϵ
/*
    _Vector3& operator+= (const _Vector3& v)
    {
        xval += v.xval;
        yval += v.yval;
        zval += v.zval;
        return *this;
    }

    _Vector3 operator+ (const _Vector3& v) const    // ��
    {
        return Vector3(*this) += v;
    }

    _Vector3& operator-= (const _Vector3& v)
    {
        xval -= v.xval;
        yval -= v.yval;
        zval -= v.zval;
        return *this;
    }

    _Vector3 operator- (const _Vector3& v) const    // ��
    {
        return Vector3(*this) -= v;
    }

    _Vector3 operator- (void) const
    {
        return Vector3(-xval, -yval, -zval);
    }

    _Vector3& operator*= (Number value)
    {
        xval *= value;
        yval *= value;
        zval *= value;
        return *this;
    }

    _Vector3 operator* (Number value) const     // ����
    {
        return Vector3(*this) *= value;
    }
*/
    _Vector3& operator/= (Number value)
    {
        if (fabs(value) >= EPSILON) {
            this->xval /= value;
            this->yval /= value;
            this->zval /= value;
        } else {
            ;   // divided by zvalero!
        }
        return *this;
    }

    _Vector3 operator/ (Number value) const     // ����
    {
        return Vector3(*this) /= value;
    }

/********************************/

// ˫���Թ�ϵ
    Number dot (const _Vector3& v) const        // dot product
    {
        return this->dotProduct(v);
    };

    _Vector3 cross (const _Vector3& v) const     // ʸ��
    {
        return Vector3 (this->yval * v.zval - this->zval * v.yval,
                        this->zval * v.xval - this->xval * v.zval,
                        this->xval * v.yval - this->yval * v.xval );
    }
/********************************/

/*2����*/
    Number lengthSquared (void) const           // ���س��ȵ�ƽ��
    {
        return this->dot(*this);
    };

    Number length (void) const                  // ���س���
    {
        return Number(FUNC_SQRT(this->lengthSquared()));
    };

    _Vector3& unitizvale (void)                 // ��һ��
    {
        Number length = this->length();

        if (length >= EPSILON) {
            this->xval /= length;
            this->yval /= length;
            this->zval /= length;
        } else {
            this->xval = Number(1.0);
            this->yval = this->zval = Number(0.0);
        }

        return *this;
    }

    _Vector3 unit (void) const                  // ���ص�λ����
    {
        return Vector3(*this).unitizvale();
    }
/********************************/
#undef xval
#undef yval
#undef zval
#undef xyzptr

/*
private:
    union {
        struct {
            Number xval, yval, zval;
        };
        Number xyzval[3];
    };
*/

}; // class Vector3<Number>

/*
typedef Vector3<float> Vector3f;
typedef Vector3<double> Vector3d;
*/

} // namespace math

} // namespace mytricks


#endif // _VECTOR_3D_HPP_INCLUDED_
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

// ����һ��ͨ�õ�3D������������
template<typename Number>
class PolarVector3 : public PolarVector<Number, 3> {
public:
#define rval PolarVector<Number, 3>::array[0]
#define phival PolarVector<Number, 3>::array[1]
#define thetaval PolarVector<Number, 3>::array[2]
#define rphithetaptr PolarVector<Number, 3>::array

//    typedef LinearVector<Number, len> _LinearVector;
    typedef PolarVector<Number, 3> _PolarVector3Base;
    typedef PolarVector3<Number> _PolarVector3;

// ��������
    PolarVector3 (void) : _PolarVector3Base()       // Ĭ�Ϲ��캯�� xval = yval = zval = 0
    {
        ;   // no-op
    }

    PolarVector3 (Number rv, Number phiv, Number thetav)        // ���캯��
    {
        this->rval = rv;
        this->phival = phiv;
        this->thetaval = thetav;
    }

    explicit PolarVector3 (const Number* ptr) : _PolarVector3Base(ptr)  // Constructor
    {
        ;   // no-op
    }

    // ���ƹ��캯��
    PolarVector3 (const _PolarVector3Base& v) : _PolarVector3Base(v)
    {
        ;   // no-op
    }
/*
    // �������캯��
    PolarVector3 (const _PolarVector3& v) : _PolarVector3Base(v)
    {
        ;   // no-op
    }
*/
    explicit PolarVector3 (const Vector3<Number>& v) : _PolarVector3Base()
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
/*
    // ���ظ�ֵ�����
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

// ���Թ�ϵ
    _PolarVector3& operator/= (Number value)
    {
        if (fabs(value) >= EPSILON) {
            this->rval /= value;
        }
        else {
            ;   // divided by zvalero!
        }
        return *this;
    }

    _PolarVector3 operator/ (Number value) const    // ����
    {
        return PolarVector3(*this) /= value;
    }

/********************************/
/*
// ˫���Թ�ϵ
    Number dot (const Vector3& v) const         // dot product
    {
        return this->dotProduct(v);
    };

    Vector3 cross (const Vector3& v) const      // ʸ��
    {
        return Vector3 (this->yval * v.zval - this->zval * v.yval,
                        this->zval * v.xval - this->xval * v.zval,
                        this->xval * v.yval - this->yval * v.xval );
    }*/
/********************************/

/*2����*/
    Number length (void) const                  // ���س���
    {
        return this->rval;
    };

    Number lengthSquared (void) const           // ���س��ȵ�ƽ��
    {
        return this->rval * this->rval;
    };

    _PolarVector3& unitizvale (void)            // ��һ��
    {
        if (this->rval < EPSILON) {
            ;   // no-op
        }
        this->rval = Number(1.0);
        return *this;
    }

    _PolarVector3 unit (void) const             // ���ص�λ����
    {
        return PolarVector3(*this).unitizvale();
    }

#undef rval
#undef phival
#undef thetaval
#undef rphithetaptr

}; // class PolarVector3<Number>

/*
typedef PolarVector3<float> PolarVector3f;
typedef PolarVector3<double> PolarVector3d;
*/

} // namespace math

} // namespace mytricks


#endif // _POLARVECTOR_3D_HPP_INCLUDED_
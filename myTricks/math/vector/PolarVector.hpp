#ifndef _POLARVECTOR_HPP_INCLUDED_
# define _POLARVECTOR_HPP_INCLUDED_


/**********************************************************************\
*
*
\**********************************************************************/


# include "LinearVector.hpp"


# if !(defined FUNC_SIN && defined FUNC_COS)
#  include <cmath>
#  ifndef FUNC_SIN
#   define FUNC_SIN ::std::sin
#  endif // FUNC_SIN
#  ifndef FUNC_COS
#   define FUNC_COS ::std::cos
#  endif // FUNC_COS
# endif // FUNC_SIN FUNC_COS


namespace mytricks {

namespace math {

// 定义一个通用的n维极坐标向量类
template<typename Number, unsigned int n>
class PolarVector {
/**********************************\
* Polar Vector
* Number should be float, double or sth...
\**********************************/

    typedef PolarVector<Number, n>  _PolarVector;

    typedef LinearVector<Number, n> _LinearVector;

public:
    typedef Number  value_type;

    PolarVector (void)                  // Default Constructor
    {
        this->setZero();
    }

    explicit PolarVector (const Number* ptr)    // Constructor
    {
        if (NULL != ptr) {
            for (unsigned int i = 0; i < n; ++i) {
                this->array[i] = ptr[i];
            }
        } else {
            this->setZero();
        }
    }

    // Copy Constructor
    PolarVector (const PolarVector& v)
    {
        for (unsigned int i = 0; i < n; ++i) {
            this->array[i] = v.array[i];
        }
    }

    // Assignment Operator
    PolarVector& operator= (const PolarVector& v)
    {
        if (&v != this) {
            for (unsigned int i = 0; i < n; ++i) {
                this->array[i] = v.array[i];
            }
        }
        return *this;
    }

    /*!virtual */~PolarVector () {}

    void setZero (void)
    {
        for (unsigned int i = 0; i < n; ++i) {
            this->array[i] = Number(0);
        }
        return;
    }

    const _LinearVector toLinear (void) const
    {
        Number tmp[n] = {0};
        tmp[0] = this->array[0];
        for (unsigned int i = n-1; i > 0; --i) {
            tmp[i] = tmp[0] * Number(FUNC_SIN(this->array[i]));
            tmp[0] *= Number(FUNC_COS(this->array[i]));
        }
        return _LinearVector(tmp);
    }


// Scaling Functions
    PolarVector& operator*= (Number value)
    {
        this->array[0] *= value;
        return *this;
    }

    const PolarVector operator* (Number value) const
    {
        return PolarVector(*this) *= value;
    }

    friend const PolarVector operator* (Number value, const PolarVector& v)
    {
        return PolarVector(v) *= value;
    }

protected:
    Number  array[n];               // Data Member


}; // class PolarVector<Number, n>

} // namespace math

} // namespace mytricks


#endif // _POLARVECTOR_HPP_INCLUDED_
#ifndef _LINEARVECTOR_HPP_
# define _LINEARVECTOR_HPP_ 1


/**********************************************************************\
*
*
\**********************************************************************/


# ifndef __cplusplus
#  error "Must Under C++"
# endif /* C++ */

# ifndef NULL
#  define NULL 0
# endif /* NULL */


namespace mytricks {

namespace math {

template<typename Number, unsigned int len>
class LinearVector {
/**********************************\
* Linear Vector
* Number could be int, float, double or sth...
\**********************************/

    typedef LinearVector<Number, len>   _LinearVector;

public:
    typedef Number  value_type;

    LinearVector (void)                 // Default Constructor
    {
        this->setZero();
    }

    LinearVector (const Number* ptr)    // Constructor
    {
        if (NULL != ptr) {
            for (unsigned int i = 0; i < len; ++i) {
                this->array[i] = ptr[i];
            }
        } else {
            this->setZero();
        }
    }

    // Copy Constructor
    LinearVector (const LinearVector& v)
    {
        for (unsigned int i = 0; i < len; ++i) {
            this->array[i] = v.array[i];
        }
    }

    // Assignment Operator
    LinearVector& operator= (const LinearVector& v)
    {
        if (&v != this) {
            for (unsigned int i = 0; i < len; ++i) {
                this->array[i] = v.array[i];
            }
        }
        return *this;
    }

    /*!virtual */~LinearVector () {}

    void setZero (void)
    {
        for (unsigned int i = 0; i < len; ++i) {
            this->array[i] = Number(0);
        }
        return;
    }


// Linear Functions
    Number sum (void) const
    {
        Number r(0);
        for (unsigned int i = 0; i < len; ++i) {
            r += this->array[i];
        }
        return r;
    }

    LinearVector& operator+= (const LinearVector& v)
    {
        for (unsigned int i = 0; i < len; ++i) {
            this->array[i] += v.array[i];
        }
        return *this;
    }

    const LinearVector operator+ (const LinearVector& v) const
    {
        return LinearVector(*this) += v;
    }

    LinearVector& operator-= (const LinearVector& v)
    {
        for (unsigned int i = 0; i < len; ++i) {
            this->array[i] -= v.array[i];
        }
        return *this;
    }

    const LinearVector operator- (const LinearVector& v) const
    {
        return LinearVector(*this) -= v;
    }

    const LinearVector operator- (void) const
    {
        return LinearVector() - *this;
    }

    LinearVector& operator*= (Number value)
    {
        for (unsigned int i = 0; i < len; ++i) {
            this->array[i] *= value;
        }
        return *this;
    }

    const LinearVector operator* (Number value) const
    {
        return LinearVector(*this) *= value;
    }

    friend const LinearVector operator* (Number value, const LinearVector& v)
    {
        return LinearVector(v) *= value;
    }

/********************************\
    LinearVector& operator/= (Number value)
    {
        if (fabs(value) >= EPSILON) {
            for (unsigned int i = 0; i < len; ++i) {
                this->array[i] /= value;
            }
        } else {
            ;   // divided by zvalero!
        }
        return *this;
    }

    const LinearVector operator/ (Number value) const
    {
        return LinearVector(*this) /= value;
    }
\********************************/


// Bilinear Functions
    LinearVector& scale (const LinearVector& v)
    {
        for (unsigned int i = 0; i < len; ++i) {
            this->array[i] *= v.array[i];
        }
        return *this;
    }

    const LinearVector directProduct (const LinearVector& v) const
    {
        return LinearVector(*this).scale(v);
    }

    Number innerProduct (const LinearVector& v) const
    {
        Number r(0);
        for (unsigned int i = 0; i < len; ++i) {
            r += this->array[i] * v.array[i];
        }
        return r;   // return (this->directProduct(v).sum());
    }


protected:
    Number  array[len];             // Data Member


}; // class LinearVector<Number, len>

} // namespace math

} // namespace mytricks


#endif // _LINEARVECTOR_HPP_
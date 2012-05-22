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
public:
    typedef LinearVector<Number, len> _LinearVector;

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
    LinearVector (const _LinearVector& v)
    {
        for (unsigned int i = 0; i < len; ++i) {
            this->array[i] = v.array[i];
        }
    }

    // Assignment Operator
    _LinearVector& operator= (const _LinearVector& v)
    {
        if (&v != this) {
            for (unsigned int i = 0; i < len; ++i) {
                this->array[i] = v.array[i];
            }
        }
        return *this;
    }

    virtual ~LinearVector () {}

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

    _LinearVector& operator+= (const _LinearVector& v)
    {
        for (unsigned int i = 0; i < len; ++i) {
            this->array[i] += v.array[i];
        }
        return *this;
    }

    _LinearVector operator+ (const _LinearVector& v) const
    {
        return LinearVector(*this) += v;
    }

    _LinearVector& operator-= (const _LinearVector& v)
    {
        for (unsigned int i = 0; i < len; ++i) {
            this->array[i] -= v.array[i];
        }
        return *this;
    }

    _LinearVector operator- (const _LinearVector& v) const
    {
        return LinearVector(*this) -= v;
    }

    _LinearVector operator- (void) const
    {
        return LinearVector() - *this;
    }

    _LinearVector& operator*= (Number value)
    {
        for (unsigned int i = 0; i < len; ++i) {
            this->array[i] *= value;
        }
        return *this;
    }

    _LinearVector operator* (Number value) const
    {
        return LinearVector(*this) *= value;
    }

/********************************\
    _LinearVector& operator/= (Number value)
    {
        if (fabs(value) >= EPSILON) {
            for (unsigned int i = 0; i < len; ++i) {
            this->array[i] /= value;
            }
        }
        } else {
            // divided by zvalero!
        }
        return *this;
    }

    _LinearVector operator/ (Number value) const
    {
        return LinearVector(*this) /= value;
    }
\********************************/


// Bilinear Functions
    _LinearVector& scale (const _LinearVector& v)
    {
        for (unsigned int i = 0; i < len; ++i) {
            this->array[i] *= v.array[i];
        }
        return *this;
    }

    _LinearVector directProduct (const _LinearVector& v) const
    {
        return _LinearVector(*this).scale(v);
    }

    Number dotProduct (const _LinearVector& v) const
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
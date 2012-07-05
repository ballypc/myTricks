#ifndef _LINE_HPP_INCLUDED_
# define _LINE_HPP_INCLUDED_


/**********************************************************************\
*
*
\**********************************************************************/


# include "../vector/LinearVector.hpp"
# include "Point.hpp"


namespace mytricks {

namespace math {

// 定义一个通用的n维线类
template<typename Number, unsigned int n, class _Vct = LinearVector<Number, n>, class _Pnt = Point<Number, n, _Vct> >
class Line {
/**********************************\
* Line
* Number should be float, double or sth...
\**********************************/
public:
    typedef Line<Number, n, _Vct, _Pnt> _Line;

    Line (void) : p(), t()                  // Default Constructor
    {
        ;   // no-op
    }
/*
    Line (const Number* ptr) : p(ptr), t(ptr + n)     // Constructor
    {
        ;   // no-op
    }
*/
    Line (const _Pnt& pv, const _Vct& tv) : p(pv), t(tv)     // Constructor
    {
        ;   // no-op
    }

    // Copy Constructor
    Line (const _Line& l) : p(l.p), t(l.t)
    {
        ;   // no-op
    }

    // Assignment Operator
    _Line& operator= (const _Line& l)
    {
        if (&l != this) {
            this->p = l.p;
            this->t = l.t;
        }
        return *this;
    }

    virtual ~Line () {}


    _Line& translate (const _Vct& vct)
    {
        this->p += vct;
        return *this;
    }


protected:
    _Pnt p;
    _Vct t;                     // Data Member


}; // class Line<Number, n[, _Vct[, _Pnt]]>

} // namespace math

} // namespace mytricks


#endif // _LINE_HPP_INCLUDED_
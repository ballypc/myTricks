#ifndef _POINT_HPP_INCLUDED_
# define _POINT_HPP_INCLUDED_


/**********************************************************************\
*
*
\**********************************************************************/


# include "../vector/LinearVector.hpp"


namespace mytricks {

namespace math {

// 定义一个通用的n维点类
template<typename Number, unsigned int n, class _Vct = LinearVector<Number, n> >
class Point {
/**********************************\
* Point
* Number should be float, double or sth...
\**********************************/

    typedef Point<Number, n, _Vct>  _Point;

public:
    typedef Number  value_type;

    Point (void) : pos()                    // Default Constructor
    {
        ;   // no-op
    }

    Point (const Number* ptr) : pos(ptr)    // Constructor
    {
        ;   // no-op
    }

    explicit Point (const _Vct& vct) : pos(vct)     // Constructor
    {
        ;   // no-op
    }

    // Copy Constructor
    Point (const Point& p) : pos(p.pos)
    {
        ;   // no-op
    }

    // Assignment Operator
    Point& operator= (const Point& p)
    {
        if (&p != this) this->pos = p.pos;
        return *this;
    }

    /*!virtual */~Point () {}

    void setZero (void)
    {
        this->pos.setZero();
        return;
    }


    Point& operator+= (const _Vct& vct)
    {
        this->pos += vct;
        return *this;
    }

    Point& translate (const _Vct& vct)
    {
        return this->operator+=(vct);
    }

    const Point operator+ (const _Vct& vct) const
    {
        return Point(*this) += vct;
    }

    Point& operator-= (const _Vct& vct)
    {
        /*if (&vct != &this->pos) */this->pos -= vct;
        return *this;
    }

    const Point operator- (const _Vct& vct) const
    {
        return Point(*this) -= vct;
    }
/*
    const Point operator- (void) const
    {
        return Point(-this->pos);
    }
*/
    const _Vct operator- (const Point& p) const
    {
        return this->pos - p.pos;
    }


protected:
    _Vct pos;                   // Data Member


}; // class Point<Number, n[, _Vct]>

} // namespace math

} // namespace mytricks


#endif // _POINT_HPP_INCLUDED_
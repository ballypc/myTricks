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
public:
    typedef Point<Number, n, _Vct> _Point;

    Point (void) : pos()                    // Default Constructor
    {
        ;   // no-op
    }

    Point (const Number* ptr) : pos(ptr)    // Constructor
    {
        ;   // no-op
    }

    explicit Point (const _Vct& vct) : pos(vct)      // Constructor
    {
        ;   // no-op
    }

    // Copy Constructor
    Point (const _Point& p) : pos(p.pos)
    {
        ;   // no-op
    }

    // Assignment Operator
    _Point& operator= (const _Point& v)
    {
        if (&v != this) this->pos = v.pos;
        return *this;
    }

    virtual ~Point () {}

    void setZero (void)
    {
        this->pos.setZero();
        return;
    }

    _Point& operator+= (const _Vct& vct)
    {
        /*if (&vct != this->pos) */this->pos += vct;
        return *this;
    }

    _Point operator+ (const _Vct& vct) const
    {
        return _Point(*this) += vct;
    }

    _Point& operator-= (const _Vct& vct)
    {
        this->pos -= vct;
        return *this;
    }

    _Point operator- (const _Vct& vct) const
    {
        return _Point(*this) -= vct;
    }
/*
    _Point operator- (void) const
    {
        return _Point(-this->pos);
    }
*/
    _Vct operator- (const _Point& p) const
    {
        return this->pos - p.pos;
    }

protected:
    _Vct pos;                   // Data Member

}; // class Point<Number, n[, Vct]>

} // namespace math

} // namespace mytricks


#endif // _POINT_HPP_INCLUDED_
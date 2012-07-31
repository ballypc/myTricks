#ifndef _POINT_3D_CTPS_HPP_INCLUDED_
# define _POINT_3D_CTPS_HPP_INCLUDED_


/**********************************************************************\
* This is an internal header file, included by other library headers.  *
* Do not attempt to use it directly.
*
* using Class-Template Partial Specializations.
\**********************************************************************/


# include "../Point.hpp"
# include "../../vector/3D/LinearVector_3D_CTPS.hpp"

namespace mytricks {

namespace math {

// 定义一个通用的3D点类
template<typename Number>
class Point<Number, 3, LinearVector<Number, 3> > {
/**********************************\
* Point 3
* Number should be float, double or sth...
\**********************************/

    typedef Point<Number, 3, LinearVector<Number, 3> >  _Point3;

    typedef LinearVector<Number, 3> _LinearVector3;

public:
    typedef Number  value_type;

    Point (void) : pos()                    // Default Constructor
    {
        ;   // no-op
    }

    Point (Number xv, Number yv, Number zv) : pos(xv, yv, zv)   // 构造函数
    {
        ;   // no-op
    }

    Point (const Number* ptr) : pos(ptr)    // Constructor
    {
        ;   // no-op
    }

    explicit Point (const _LinearVector3& vct) : pos(vct)   // Constructor
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

    Number x(void) const {return this->pos.x();}       // get
//    Number& x(void) {return this->xval;}
    Number y(void) const {return this->pos.y();}       // get
//    Number& y(void) {return this->yval;}
    Number z(void) const {return this->pos.z();}       // get
//    Number& z(void) {return this->zval;}
    const Number *xyz(void) const {return this->pos.xyz();}    // get_ptr

    Point& operator+= (const _LinearVector3& vct)
    {
        this->pos += vct;
        return *this;
    }

    Point& translate (const _LinearVector3& vct)
    {
        return this->operator+=(vct);
    }

    const Point operator+ (const _LinearVector3& vct) const
    {
        return Point(*this) += vct;
    }

    Point& operator-= (const _LinearVector3& vct)
    {
        /*if (&vct != &this->pos) */this->pos -= vct;
        return *this;
    }

    const Point operator- (const _LinearVector3& vct) const
    {
        return Point(*this) -= vct;
    }
/*
    const Point operator- (void) const
    {
        return Point(-this->pos);
    }
*/
    const _LinearVector3 operator- (const Point& p) const
    {
        return this->pos - p.pos;
    }


protected:
    _LinearVector3 pos;             // Data Member


}; // class Point<Number, 3>

/*
typedef Point<float, 3> Point3f;
typedef Point<double, 3> Point3d;
*/


template<typename Number>
class Point3 : public Point<Number, 3, LinearVector<Number, 3> > {
/**********************************\
* Point3
* Number should be float, double or sth...
\**********************************/

    typedef Point<Number, 3, LinearVector<Number, 3> >  _Base;

    typedef LinearVector<Number, 3> _LinearVector3;

public:
    typedef Number  value_type;

    Point3 (void) : _Base()                 // Default Constructor
    {
        ;   // no-op
    }

    Point3 (Number xv, Number yv, Number zv) : _Base(xv, yv, zv)    // 构造函数
    {
        ;   // no-op
    }

    Point3 (const Number* ptr) : _Base(ptr)     // Constructor
    {
        ;   // no-op
    }

    explicit Point3 (const _LinearVector3& vct) : _Base(vct)    // Constructor
    {
        ;   // no-op
    }

    // Copy Constructor
    Point3 (const _Base& p) : _Base(p)
    {
        ;   // no-op
    }


}; // class Point3<Number>

} // namespace math

} // namespace mytricks


#endif // _POINT_3D_CTPS_HPP_INCLUDED_
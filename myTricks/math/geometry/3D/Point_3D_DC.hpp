#ifndef _POINT_3D_DC_HPP_INCLUDED_
# define _POINT_3D_DC_HPP_INCLUDED_


/**********************************************************************\
* This is an internal header file, included by other library headers.  *
* Do not attempt to use it directly.
*
* using Derived Classes.
\**********************************************************************/


# include "../Point.hpp"
# include "../../vector/3D/LinearVector_3D_DC.hpp"

namespace mytricks {

namespace math {

// 定义一个通用的3D点类
template<typename Number>
class Point3 : public Point<Number, 3, LinearVector<Number, 3> > {
/**********************************\
* Point3
* Number should be float, double or sth...
\**********************************/

    typedef Point3<Number>  _Point3;
    typedef Point<Number, 3, LinearVector<Number, 3> >  _Base;

    typedef LinearVector<Number, 3> _LinearVector3Base;
    typedef LinearVector3<Number>   _LinearVector3;

public:
    typedef Number  value_type;

    Point3 (void) : _Base()         // Default Constructor
    {
        ;   // no-op
    }

    Point3 (Number xv, Number yv, Number zv) : _Base(_LinearVector3(xv, yv, zv))    // 构造函数
    {
        ;   // no-op
    }

    Point3 (const Number* ptr) : _Base(ptr) // Constructor
    {
        ;   // no-op
    }

    explicit Point3 (const _LinearVector3Base& vct) : _Base(vct)    // Constructor
    {
        ;   // no-op
    }

    // Copy Constructor
    Point3 (const _Base& p) : _Base(p)
    {
        ;   // no-op
    }
/*
    // Assignment Operator
    Point3& operator= (const _Base& v)
    {
        if (&v != this) this->Point.pos = v.pos;
        return *this;
    }
*/
    /*!virtual */~Point3 () {}

    Number x(void) const {return _LinearVector3(this->_Base::pos).x();}     // get
//    Number& x(void) {return this->xval;}
    Number y(void) const {return _LinearVector3(this->_Base::pos).y();}     // get
//    Number& y(void) {return this->yval;}
    Number z(void) const {return _LinearVector3(this->_Base::pos).z();}     // get
//    Number& z(void) {return this->zval;}
    const Number *xyz(void) const {return _LinearVector3(this->_Base::pos).xyz();}  // get_ptr


    Point3& operator+= (const _LinearVector3Base& vct)
    {
        this->pos += vct;
        return *this;
    }

    Point3& translate (const _LinearVector3Base& vct)
    {
        return this->operator+=(vct);
    }

    const Point3 operator+ (const _LinearVector3Base& vct) const
    {
        return Point3(*this) += vct;
    }

    Point3& operator-= (const _LinearVector3Base& vct)
    {
        /*if (&vct != &this->pos) */this->pos -= vct;
        return *this;
    }

    const Point3 operator- (const _LinearVector3Base& vct) const
    {
        return Point3(*this) -= vct;
    }
/*
    const Point3 operator- (void) const
    {
        return Point3(-this->pos);
    }
*/
    const _LinearVector3 operator- (const _Base& p) const
    {
        return _LinearVector3(this->_Base::operator-(p));
    }


}; // class Point3<Number>

/*
typedef Point3<float> Point3f;
typedef Point3<double> Point3d;
*/

} // namespace math

} // namespace mytricks


#endif // _POINT_3D_DC_HPP_INCLUDED_
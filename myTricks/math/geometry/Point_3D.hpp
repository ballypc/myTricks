#ifndef _POINT_3D_HPP_INCLUDED_
# define _POINT_3D_HPP_INCLUDED_


/**********************************************************************\
*
*
\**********************************************************************/


# include "Point.hpp"
# include "../vector/Vector_3D.hpp"

namespace mytricks {

namespace math {

// 定义一个通用的3D点类
template<typename Number>
class Point3 : public Point<Number, 3, Vector3<Number> > {
/**********************************\
* Point3
* Number should be float, double or sth...
\**********************************/
public:
    typedef Point<Number, 3, Vector3<Number> > _P3Base;
    typedef Point3<Number> _Point3;

    Point3 (void) : _P3Base()                   // Default Constructor
    {
        ;   // no-op
    }

    Point3 (Number xv, Number yv, Number zv) : _P3Base(Vector3<Number>(xv,yv,zv))    // 构造函数
    {
        ;   // no-op
    }


    Point3 (const Number* ptr) : _P3Base(ptr)   // Constructor
    {
        ;   // no-op
    }

    // Copy Constructor
    Point3 (const _P3Base& p) : _P3Base(p)
    {
        ;   // no-op
    }
/*
    // Assignment Operator
    _Point3& operator= (const _P3Base& v)
    {
        if (&v != this) this->Point.pos = v.pos;
        return *this;
    }
*/
//    virtual ~Point3 () {}
    Number x(void) const {return this->_P3Base::pos.x();}       // get
//    Number& x(void) {return this->xval;}
    Number y(void) const {return this->_P3Base::pos.y();}       // get
//    Number& y(void) {return this->yval;}
    Number z(void) const {return this->_P3Base::pos.z();}       // get
//    Number& z(void) {return this->zval;}
    const Number *xyz(void) const {return this->_P3Base::pos.xyz();}    // get_ptr
/*
protected:
    LinearVector<Number, n> pos;               // Data Member
*/
}; // class Point<Number>

} // namespace math

} // namespace mytricks


#endif // _POINT_3D_HPP_INCLUDED_
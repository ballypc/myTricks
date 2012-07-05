#ifndef _LINE_3D_HPP_INCLUDED_
# define _LINE_3D_HPP_INCLUDED_


/**********************************************************************\
*
*
\**********************************************************************/


# include "Line.hpp"
# include "../vector/Vector_3D.hpp"
# include "Point_3D.hpp"


namespace mytricks {

namespace math {

// 定义一个通用的3D线类
template<typename Number>
class Line3 : public Line<Number, 3, Vector3<Number>, Point3<Number> > {
/**********************************\
* Line3
* Number should be float, double or sth...
\**********************************/
public:
    typedef Line<Number, 3, Vector3<Number>, Point3<Number> > _L3Base;
    typedef Line3<Number> _Line3;

    typedef Point3<Number> _Point3;
    typedef Vector3<Number> _Vector3;

    Line3 (void) : _L3Base()                   // Default Constructor
    {
        ;   // no-op
    }
/*
    Line3 (Number xv, Number yv, Number zv) : _L3Base(_Vector3(xv,yv,zv))    // 构造函数
    {
        ;   // no-op
    }

    Line3 (const Number* ptr) : _L3Base(ptr)   // Constructor
    {
        ;   // no-op
    }
*/
    Line3 (const _Point3& pv, const _Vector3& tv) : _L3Base(pv, tv)      // Constructor
    {
        ;   // no-op
    }

    // Copy Constructor
    Line3 (const _L3Base& l) : _L3Base(l)
    {
        ;   // no-op
    }
/*
    // Assignment Operator
    _Line3& operator= (const _L3Base& l)
    {
        if (&l != this) this->Point.pos = v.pos;
        return *this;
    }
*/
//    virtual ~Line3 () {}

/*
protected:
    // Data Member
*/

}; // class Line3<Number>

} // namespace math

} // namespace mytricks


#endif // _LINE_3D_HPP_INCLUDED_
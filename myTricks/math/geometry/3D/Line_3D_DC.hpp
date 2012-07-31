#ifndef _LINE_3D_DC_HPP_INCLUDED_
# define _LINE_3D_DC_HPP_INCLUDED_


/**********************************************************************\
* This is an internal header file, included by other library headers.  *
* Do not attempt to use it directly.
*
* using Derived Classes.
\**********************************************************************/


# include "../Line.hpp"
# include "../../vector/3D/LinearVector_3D_DC.hpp"
# include "Point_3D_DC.hpp"


namespace mytricks {

namespace math {

// 定义一个通用的3D线类
template<typename Number>
class Line3 : public Line<Number, 3, LinearVector<Number, 3>, Point<Number, 3> > {
/**********************************\
* Line3
* Number should be float, double or sth...
\**********************************/

    typedef Line3<Number>   _Line3;
    typedef Line<Number, 3, LinearVector<Number, 3>, Point<Number, 3> > _Base;

    typedef Point<Number, 3>    _P3Base;
    typedef Point3<Number>  _Point3;
    typedef LinearVector<Number, 3> _LinearVector3Base;
    typedef LinearVector3<Number>   _LinearVector3;

public:
    typedef Number  value_type;

    Line3 (void) : _Base()      // Default Constructor
    {
        ;   // no-op
    }
/*
    Line3 (Number xv, Number yv, Number zv) : _Base(_Vector3(xv, yv, zv))   // 构造函数
    {
        ;   // no-op
    }

    Line3 (const Number* ptr) : _Base(ptr)  // Constructor
    {
        ;   // no-op
    }
*/
    Line3 (const _P3Base& pv, const _LinearVector3Base& tv) : _Base(pv, tv)     // Constructor
    {
        ;   // no-op
    }

    // Copy Constructor
    Line3 (const _Base& l) : _Base(l)
    {
        ;   // no-op
    }
/*
    // Assignment Operator
    Line3& operator= (const _Base& l)
    {
        if (&l != this) {
            this->p = l.p;
            this->t = l.t;
        }
        return *this;
    }
*/
    /*virtual */~Line3 () {}


}; // class Line3<Number>

/*
typedef Line3<float> Line3f;
typedef Line3<double> Line3d;
*/

} // namespace math

} // namespace mytricks


#endif // _LINE_3D_DC_HPP_INCLUDED_
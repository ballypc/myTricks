#ifndef _LINE_3D_CTPS_HPP_INCLUDED_
# define _LINE_3D_CTPS_HPP_INCLUDED_


/**********************************************************************\
* This is an internal header file, included by other library headers.  *
* Do not attempt to use it directly.
*
* using Class-Template Partial Specializations.
\**********************************************************************/


# include "../Line.hpp"
# include "../../vector/3D/LinearVector_3D_CTPS.hpp"
# include "Point_3D_CTPS.hpp"


namespace mytricks {

namespace math {

// 定义一个通用的3D线类
template<typename Number>
class Line<Number, 3, LinearVector<Number, 3>, Point<Number, 3> > {
/**********************************\
* Line 3
* Number should be float, double or sth...
\**********************************/

    typedef Line<Number, 3, LinearVector<Number, 3>, Point<Number, 3> > _Line3;

    typedef Point<Number, 3>    _Point3;
    typedef LinearVector<Number, 3> _LinearVector3;

public:
    typedef Number  value_type;

    Line (void) : p(), t()              // Default Constructor
    {
        ;   // no-op
    }
/*
    Line (Number xv, Number yv, Number zv)  // 构造函数
    {
        ;   // no-op
    }

    Line (const Number* ptr)    // Constructor
    {
        ;   // no-op
    }
*/
    Line (const _Point3& pv, const _LinearVector3& tv) : p(pv), t(tv)   // Constructor
    {
        ;   // no-op
    }

    // Copy Constructor
    Line (const Line& l) : p(l.p), t(l.t)
    {
        ;   // no-op
    }

    // Assignment Operator
    Line& operator= (const Line& l)
    {
        if (&l != this) {
            this->p = l.p;
            this->t = l.t;
        }
        return *this;
    }

    /*virtual */~Line () {}

    void setZero (void)
    {
        this->p.setZero();
        return;
    }


    Line& translate (const _LinearVector3& vct)
    {
        this->p += vct;
        return *this;
    }


protected:
    _Point3 p;
    _LinearVector3 t;               // Data Member


}; // class Line<Number, 3>

/*
typedef Line<float, 3> Line3f;
typedef Line<double, 3> Line3d;
*/


template<typename Number>
class Line3 : public Line<Number, 3, LinearVector<Number, 3>, Point<Number, 3> > {
/**********************************\
* Line3
* Number should be float, double or sth...
\**********************************/

    typedef Line<Number, 3, LinearVector<Number, 3>, Point<Number, 3> > _Base;

    typedef Point<Number, 3>    _Point3;
    typedef LinearVector<Number, 3> _LinearVector3;

public:
    typedef Number  value_type;

    Line3 (void) : _Base()      // Default Constructor
    {
        ;   // no-op
    }
/*
    Line3 (Number xv, Number yv, Number zv) : _Base(xv, yv, zv)     // 构造函数
    {
        ;   // no-op
    }

    Line3 (const Number* ptr) : _Base(ptr)  // Constructor
    {
        ;   // no-op
    }
*/
    Line3 (const _Point3& pv, const _LinearVector3& tv) : _Base(pv, tv)     // Constructor
    {
        ;   // no-op
    }

    // Copy Constructor
    Line3 (const _Base& l) : _Base(l)
    {
        ;   // no-op
    }


}; // class Line3<Number>

} // namespace math

} // namespace mytricks


#endif // _LINE_3D_CTPS_HPP_INCLUDED_
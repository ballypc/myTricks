#ifndef _POSITIONOBJ_3D_HPP_INCLUDED_
# define _POSITIONOBJ_3D_HPP_INCLUDED_


/**********************************************************************\
*
*
\**********************************************************************/


# include "../ObjectBase.hpp"
# include "../math/geometry/Point_3D.hpp"
# include "../math/vector/Vector_3D.hpp"
# include "../phys/Motion_3D.hpp"


namespace mytricks {

namespace world_3d {

template<typename Number>
class PositionObj : public AdvanceObj {
/**********************************\
* Virtual Class, CANNOT be instantiated.
* with Position
\**********************************/

    typedef math::Point<Number, 3>  _Point3Base;
    typedef math::Point3<Number>    _Point3;

public:
    typedef Number  value_type;

    const _Point3& position (void) const {return this->positionVal;}


protected:
    explicit PositionObj (const _Point3Base& pos) : positionVal(pos) {}
    virtual ~PositionObj () {}

    _Point3 positionVal;


}; // class PositionObj<Number>


template<typename Number>
class MovableObj : public PositionObj<Number> {
/**********************************\
* Virtual Class, CANNOT be instantiated.
* with Motion
* can be Derived into Actor\Camera\Weather
\**********************************/

    typedef PositionObj<Number> _Base;

    typedef math::Point<Number, 3>  _Point3Base;
    typedef math::Point3<Number>    _Point3;
    typedef math::LinearVector<Number, 3>   _LinearVector3Base;
    typedef math::LinearVector3<Number>     _LinearVector3;

public:
    typedef Number  value_type;

protected:
    explicit MovableObj (const _Point3Base& pos) : _Base(pos), motion() {}
    MovableObj (const _Point3Base& pos, const _LinearVector3Base& vel) : _Base(pos), motion(vel) {}
    virtual ~MovableObj () {}

    phys::Motion<Number, 3> motion;


}; // class MovableObj<Number>

} // namespace world_3d

} // namespace mytricks


#endif // _POSITIONOBJ_3D_HPP_INCLUDED_
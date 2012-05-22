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
public:
    typedef math::Point3<Number> _Point3;
    const _Point3& GETposition() {return this->position;}

protected:
    explicit PositionObj(const _Point3& pos) : position(pos) {}
    virtual ~PositionObj() {}

    _Point3 position;

}; // class PositionObj<Number>

template<typename Number>
class MovableObj : public PositionObj<Number> {
/**********************************\
* Virtual Class, CANNOT be instantiated.
* with Motion
* can be Derived into Actor\Camera\Weather
\**********************************/
public:
    typedef math::Point3<Number> _Point3;
    typedef math::Vector3<Number> _Vector3;

protected:
    explicit MovableObj(const _Point3& pos) : PositionObj<Number>/*::PositionObj*/(pos), motion(0) {}
    MovableObj(const _Point3& pos, const _Vector3& vel) : PositionObj<Number>/*::PositionObj*/(pos), motion(vel) {}
    virtual ~MovableObj() {}

    phys::Motion3<Number> motion;

}; // class MovableObj<Number>

} // namespace world_3d

} // namespace mytricks


#endif // _POSITIONOBJ_3D_HPP_INCLUDED_
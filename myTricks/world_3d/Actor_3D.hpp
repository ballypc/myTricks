#ifndef _ACTOR_3D_HPP_INCLUDED_
# define _ACTOR_3D_HPP_INCLUDED_


/**********************************************************************\
*
*
\**********************************************************************/


# include "Camera_3D.hpp"


namespace mytricks {

namespace world_3d {

template<typename Number>
class Actor : public MovableObj<Number> {
/**********************************\
* Actor
* can be Derived.
\**********************************/
public:
    typedef math::Vector3<Number> Vector3;
    typedef math::PolarVector3<Number> PolarVector3;

    Actor(void) : MovableObj<Number>/*::MovableObj*/(0), eyePos() {}
    explicit Actor(const Vector3& pos) : MovableObj<Number>/*::MovableObj*/(pos), eyePos() {}
    Actor(const Vector3& pos, const Vector3& eye) : MovableObj<Number>/*::MovableObj*/(pos), eyePos(eye) {}
    virtual ~Actor() {}

    Camera<Number> toCamera(const PolarVector3& seeing, bool isFromActor)
    {
        if (isFromActor) return Camera<Number>/*::Camera*/(this->eyePos + this->MovableObj<Number>::position, seeing);
        else return Camera<Number>/*::Camera*/(seeing, this->eyePos + this->MovableObj<Number>::position);
    }

    Camera<Number> toCamera(const Vector3& outPos, bool isFromActor)
    {
        if (isFromActor) return Camera<Number>/*::Camera*/(this->eyePos + this->MovableObj<Number>::position, outPos);
        else return Camera<Number>/*::Camera*/(outPos, this->eyePos + this->MovableObj<Number>::position);
    }

protected:
    Vector3 eyePos;

}; // class Actor<Number>

} // namespace world_3d

} // namespace mytricks


#endif // _ACTOR_3D_HPP_INCLUDED_
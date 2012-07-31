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

    typedef MovableObj<Number>  _Base;

    typedef math::Point<Number, 3>  _Point3Base;
    typedef math::Point3<Number>    _Point3;
    typedef math::LinearVector<Number, 3>   _LinearVector3Base;
    typedef math::LinearVector3<Number>     _LinearVector3;
    typedef math::PolarVector<Number, 3>	_PolarVector3Base;
    typedef math::PolarVector3<Number>		_PolarVector3;

    typedef Camera<Number>  _Camera;

public:
    typedef Number  value_type;

    Actor (void) : _Base(), eyePosition() {}
    explicit Actor (const _Point3Base& pos) : _Base(pos), eyePosition() {}
    Actor (const _Point3Base& pos, const _Point3Base& eyePos) : _Base(pos), eyePosition(eyePos) {}
    virtual ~Actor () {}

    _Camera toCamera (const _PolarVector3Base& seeing, bool isFromActor)
    {
        if (isFromActor) return _Camera(this->eyePosition + this->_Base::position, seeing);
        else return _Camera(seeing, this->eyePosition + this->_Base::position);
    }

    _Camera toCamera (const _Point3Base& outPos, bool isFromActor)
    {
        if (isFromActor) return _Camera(this->eyePosition + this->_Base::position, outPos);
        else return _Camera(outPos, this->eyePosition + this->_Base::position);
    }


protected:
    _Point3 eyePosition;


}; // class Actor<Number>

} // namespace world_3d

} // namespace mytricks


#endif // _ACTOR_3D_HPP_INCLUDED_
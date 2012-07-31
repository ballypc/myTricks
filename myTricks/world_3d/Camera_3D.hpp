#ifndef _CAMERA_3D_HPP_INCLUDED_
# define _CAMERA_3D_HPP_INCLUDED_


/**********************************************************************\
*
*
\**********************************************************************/


# include "PositionObj_3D.hpp"
# include "../math/geometry/Point_3D.hpp"
# include "../math/vector/PolarVector_3D.hpp"
# include "../math/Angle.hpp"


namespace mytricks {

namespace world_3d {

template<typename Number>
class Camera : public MovableObj<Number> {
/**********************************\
* Camera
* can be Derived.
\**********************************/

    typedef MovableObj<Number>  _Base;

    typedef math::Point<Number, 3>  _Point3Base;
    typedef math::Point3<Number>    _Point3;
    typedef math::LinearVector<Number, 3>   _LinearVector3Base;
    typedef math::LinearVector3<Number>     _LinearVector3;
    typedef math::PolarVector<Number, 3>    _PolarVector3Base;
    typedef math::PolarVector3<Number>      _PolarVector3;
    typedef math::Angle<Number>	    _Angle;

public:
    typedef Number  value_type;

    // Default Constructor
    Camera (void) : _Base(), staringVal(-10, 0, 0), sightVal(10, 0, 0), sightAngleVal() {}

    // Constructor, watch is a PolarVector3 that form Camera to staring
    Camera (const _Point3Base& pos, const _PolarVector3Base& watch, _Angle sAngle=_Angle()) : _Base(pos), staringVal(pos + watch./*math::PolarVector<Number, 3>::*/toLinear()), sightVal(-watch), sightAngleVal(sAngle) {}

    // Constructor, see is a PolarVector3 that form staring to Camera
    Camera (const _PolarVector3Base& see, const _Point3Base& stare, _Angle sAngle=_Angle()) : _Base(stare + see./*PolarVector<Number, 3>::*/toLinear()), staringVal(stare), sightVal(see), sightAngleVal(sAngle) {}

    // Constructor
    Camera (const _Point3Base& pos, const _Point3Base& stare, _Angle sAngle=_Angle()) : _Base(pos), staringVal(stare), sightVal(pos - stare), sightAngleVal(sAngle) {}

    virtual ~Camera () {}

    const _Point3& staring (void) {return this->staringVal;}
    const _PolarVector3& sight (void) {return this->sightVal;}
    const _Angle& sightAngle (void) {return this->sightAngleVal;}

    void translate (const _LinearVector3Base& tVec) {this->_Base::position += tVec; this->staringVal += tVec;}

    void turnLR (const Number& tAngle, bool stay) {this->sightVal.phi() += tAngle; this->flush(stay);}
    void turnUD (const Number& tAngle, bool stay) {this->sightVal.theta() += tAngle; this->flush(stay);}

    void pull (const Number& pLength, bool stay) {this->sightVal.r() += pLength; this->flush(stay);}

    void turn2 (const _Angle& tAngle) {this->sightAngleVal += tAngle;}


protected:
    _Point3     staringVal;     // place the Camera staring.
    _PolarVector3   sightVal;   // a PolarVector3 that form staring to Camera
    _Angle      sightAngleVal;  // an angle of sight that the View Plane rotates

    void flush (bool stay)
    {
        if (stay)
            this->staringVal = this->_Base::positionVal - this->sightVal./*PolarVector<Number, 3>::*/toLinear();
        else
            this->_Base::positionVal = this->staringVal + this->sightVal./*PolarVector<Number, 3>::*/toLinear();
    }


}; // class Camera<Number>


template<typename Number>
class CameraEx : public Camera<Number> {
/**********************************\
* Camera Extended
* easier moving.
\**********************************/

    typedef Camera<Number>  _Base;

    typedef math::Point<Number, 3>  _Point3Base;
    typedef math::Point3<Number>    _Point3;
    typedef math::LinearVector<Number, 3>   _LinearVector3Base;
    typedef math::LinearVector3<Number>     _LinearVector3;
    typedef math::PolarVector<Number, 3>	_PolarVector3Base;
    typedef math::PolarVector3<Number>		_PolarVector3;

public:
    typedef Number  value_type;

    CameraEx (void) : _Base() {}
    CameraEx (const _Point3Base& pos, const _PolarVector3Base& watch) : _Base(pos, watch) {}
    CameraEx (const _PolarVector3Base& see, const _Point3Base& stare) : _Base(see, stare) {}
    CameraEx (const _Point3Base& pos, const _Point3Base& stare) : _Base(pos, stare) {}

    CameraEx (const _Base& c) : _Base(c) {}

    virtual ~CameraEx () {}

    void turnLeft (const Number& tAngle, bool stay) {if (stay) this->turnLR(tAngle, stay); else this->turnLR(-tAngle, stay);}
    void turnRight (const Number& tAngle, bool stay) {if (stay) this->turnLR(-tAngle, stay); else this->turnLR(tAngle, stay);}
    void turnUp (const Number& tAngle, bool stay) {if (stay) this->turnUD(-tAngle, stay); else this->turnUD(tAngle, stay);}
    void turnDown (const Number& tAngle, bool stay) {if (stay) this->turnUD(tAngle, stay); else this->turnUD(-tAngle, stay);}

    void push (const Number& pLength, bool stay) {this->pull(-pLength, stay);}


protected:
    ;


}; // class CameraEx<Number>

} // namespace world_3d

} // namespace mytricks


#endif // _CAMERA_3D_HPP_INCLUDED_
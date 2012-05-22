#ifndef _CAMERA_3D_HPP_INCLUDED_
# define _CAMERA_3D_HPP_INCLUDED_


/**********************************************************************\
*
*
\**********************************************************************/


# include "../math/vector/PolarVector_3D.hpp"
# include "../math/geometry/Point_3D.hpp"
# include "PositionObj_3D.hpp"


namespace mytricks {

namespace world_3d {

template<typename Number>
class Camera : public MovableObj<Number> {
/**********************************\
* Camera
* can be Derived.
\**********************************/
public:
    typedef math::Point3<Number> _Point3;
    typedef math::Vector3<Number> _Vector3;
    typedef math::PolarVector3<Number> _PolarVector3;

    // Default Constructor
    Camera(void) : MovableObj<Number>/*::MovableObj*/(0), staring(-10, 0, 0), sight(10, 0, 0), sightAngle() {}

    // Constructor, watch is a PolarVector3 that form Camera to staring
    Camera(const _Point3& pos, const _PolarVector3& watch, Number sAngle=Number(0)) : MovableObj<Number>/*::MovableObj*/(pos), staring(pos + watch./*math::PolarVector<Number, 3>::*/toLinear()), sight(-watch), sightAngle(sAngle) {}

    // Constructor, see is a PolarVector3 that form staring to Camera
    Camera(const _PolarVector3& see, const _Point3& stare, Number sAngle=Number(0)) : MovableObj<Number>/*::MovableObj*/(stare + see./*PolarVector<Number, 3>::*/toLinear()), staring(stare), sight(see), sightAngle(sAngle) {}

    // Constructor
    Camera(const _Point3& pos, const _Point3& stare, Number sAngle=Number(0)) : MovableObj<Number>/*::MovableObj*/(pos), staring(stare), sight(pos - stare), sightAngle(sAngle) {}

    virtual ~Camera() {}

    const _Point3& GETstaring(void) {return this->staring;}
    const _PolarVector3& GETsight(void) {return this->sight;}
    const Number& GETsightAngle(void) {return this->sightAngle;}

    void Translate (const _Vector3& tVec) {this->PositionObj<Number>::position += tVec; this->staring += tVec;}

    void Turn (const Number& tAngle, bool stay) {this->sight.phi() += tAngle; this->flush(stay);}
    void Turn1 (const Number& tAngle, bool stay) {this->sight.theta() += tAngle; this->flush(stay);}
    void Pull (const Number& pLength, bool stay) {this->sight.r() += pLength; this->flush(stay);}
    void Turn2 (const Number& tAngle) {this->sightAngle += tAngle;}

protected:
    _Point3 staring;        // place the Camera staring.
    _PolarVector3 sight;    // a PolarVector3 that form staring to Camera
    Number sightAngle;      // an angle of sight that the View Plane rotates

    void flush(bool stay) {
        if (stay)
            this->staring = this->PositionObj<Number>::position - this->sight./*PolarVector<Number, 3>::*/toLinear();
        else
            this->PositionObj<Number>::position = this->staring + this->sight./*PolarVector<Number, 3>::*/toLinear();
    }

}; // class Camera<Number>

template<typename Number>
class CameraEx : public Camera<Number> {
/**********************************\
* Camera Extended
* easier moving.
\**********************************/
public:
    typedef math::Point3<Number> _Point3;
    typedef math::Vector3<Number> _Vector3;
    typedef math::PolarVector3<Number> _PolarVector3;

    CameraEx(void) : Camera<Number>/*::Camera*/() {}
    CameraEx(const _Point3& pos, const _PolarVector3& watch) : Camera<Number>/*::Camera*/(pos, watch) {}
    CameraEx(const _PolarVector3& see, const _Point3& stare) : Camera<Number>/*::Camera*/(see, stare) {}
    CameraEx(const _Point3& pos, const _Point3& stare) : Camera<Number>/*::Camera*/(pos, stare) {}

    CameraEx(const Camera<Number>& c) : Camera<Number>/*::Camera*/(c) {}

    virtual ~CameraEx() {}

//    void ab(void);

protected:
    ;

}; // class CameraEx<Number>

} // namespace world_3d

} // namespace mytricks


#endif // _CAMERA_3D_HPP_INCLUDED_
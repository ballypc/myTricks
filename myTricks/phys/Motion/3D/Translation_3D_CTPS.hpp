#ifndef _TRANSLATION_3D_CTPS_HPP_
# define _TRANSLATION_3D_CTPS_HPP_ 1


# include "../Translation.hpp"
# include "../../../math/vector/3D/LinearVector_3D_CTPS.hpp"
# include "../../../math/geometry/3D/Point_3D_CTPS.hpp"


namespace mytricks {

namespace phys {

// 表示一个运动(点)
template<typename Number>
class Translation<Number, 3> {

    typedef Translation<Number, 3>  _Translation3;
    typedef math::LinearVector<Number, 3>   _LinearVector3;
	typedef math::Point<Number, 3>  _Point3;

public:
    typedef Number  value_type;

    explicit Translation (const _LinearVector3& v) : vel(v), acc()  // 构造函数
    {
        ; // no-op
    }

    virtual ~Translation () {}

    void init (void)    // 初始时设置为0
    {
        acc.setZero();
    }


    // 增加一个加速度
    void applyAcc (const _LinearVector3& acc)
    {
        this->acc += acc;
    }

    // 根据输入的时间dt，模拟运动
    void simulate (_Point3& pos, Number dt)
    {
        vel += (acc * dt);
        pos.translate(vel * dt);
    }


protected:
    _LinearVector3 vel;             // velocity 速度
    _LinearVector3 acc;             // acceleration 加速度


}; // class Translation<Number, 3>


template<typename Number>
class Translation3 : public Translation<Number, 3> {

    typedef Translation<Number, 3>  _Base;
    typedef math::LinearVector<Number, 3>   _Vector3;

public:
    typedef Number  value_type;

    explicit Translation3 (const _Vector3& v) : _Base(v)    // 构造函数
    {
        ; // no-op
    }


}; // class Translation3<Number>

} // namespace phys

} // namespace mytricks


#endif // _TRANSLATION_3D_CTPS_HPP_
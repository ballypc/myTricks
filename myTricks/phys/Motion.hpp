#ifndef _MOTION_HPP_
# define _MOTION_HPP_ 1


# include "../math/vector/LinearVector.hpp"
# include "../math/geometry/Point.hpp"


namespace mytricks {

namespace phys {

// 表示一个运动(点)
template<typename Number, unsigned int len>
class Motion {
public:
	typedef math::LinearVector<Number, len> _Vector;
	typedef math::Point<Number, len> _Point;

    // 构造函数
    explicit Motion(const _Vector& v) : vel(v), acc()
    {
        this->init();
    }

    virtual ~Motion() {}

    // 初始时设置加速度为0
    void init(void)
    {
        acc.setZero();
    }

    // 增加一个加速度
    void applyAcc(const _Vector& acc)
    {
        this->acc += acc;
    }

    // 根据输入的时间dt，模拟运动
    void simulate(const _Point& pos, Number dt)
    {
        vel += (acc * dt);
        pos += (vel * dt);
    }

protected:
    _Vector vel;                        // velocity 速度
    _Vector acc;                        // acceleration 加速度

}; // class Motion<Number, len>

} // namespace phys

} // namespace mytricks


#endif // _MOTION_HPP_
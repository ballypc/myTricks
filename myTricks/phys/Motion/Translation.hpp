#ifndef _TRANSLATION_HPP_
# define _TRANSLATION_HPP_ 1


# include "../../math/vector/LinearVector.hpp"
# include "../../math/geometry/Point.hpp"


namespace mytricks {

namespace phys {

// 表示一个运动(点)
template<typename Number, unsigned int n>
class Translation {

	typedef math::LinearVector<Number, n>   _LinearVector;
	typedef math::Point<Number, n>  _Point;

public:
    typedef Number  value_type;

    // 构造函数
    explicit Translation (const _LinearVector& v) : vel(v), acc()
    {
        this->init();
    }

    virtual ~Translation () {}

    // 初始时设置为0
    void init (void)
    {
        acc.setZero();
    }


    // 增加一个加速度
    void applyAcc (const _LinearVector& acc)
    {
        this->acc += acc;
    }

    // 根据输入的时间dt，模拟运动
    void simulate (_Point& pos, Number dt)
    {
        vel += (acc * dt);
        pos.translate(vel * dt);
    }


protected:
    _LinearVector vel;              // velocity 速度
    _LinearVector acc;              // acceleration 加速度


}; // class Translation<Number, n>

} // namespace phys

} // namespace mytricks


#endif // _TRANSLATION_HPP_
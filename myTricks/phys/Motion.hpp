#ifndef _MOTION_HPP_
# define _MOTION_HPP_ 1


# include "Motion/Translation.hpp"
# include "Motion/Translation.hpp"


namespace mytricks {

namespace phys {

// 表示一个运动(点)
template<typename Number, unsigned int n>
class Motion {

	typedef math::LinearVector<Number, n> _Vector;
	typedef math::Point<Number, n> _Point;

public:
    // 构造函数
    Motion(void)
    {
        this->init();
    }

    virtual ~Motion() {}

    // 初始时设置为0
    void init(void)
    {
        ;
    }


    // 根据输入的时间dt，模拟运动
    void simulate(_Point& pos, Number dt)
    {
        ;
    }

protected:
    ;


}; // class Motion<Number, n>

} // namespace phys

} // namespace mytricks


#endif // _MOTION_HPP_
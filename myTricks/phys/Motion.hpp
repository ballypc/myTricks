#ifndef _MOTION_HPP_
# define _MOTION_HPP_ 1


# include "../math/vector/LinearVector.hpp"
# include "../math/geometry/Point.hpp"


namespace mytricks {

namespace phys {

// ��ʾһ���˶�(��)
template<typename Number, unsigned int len>
class Motion {
public:
	typedef math::LinearVector<Number, len> _Vector;
	typedef math::Point<Number, len> _Point;

    // ���캯��
    explicit Motion(const _Vector& v) : vel(v), acc()
    {
        this->init();
    }

    virtual ~Motion() {}

    // ��ʼʱ���ü��ٶ�Ϊ0
    void init(void)
    {
        acc.setZero();
    }

    // ����һ�����ٶ�
    void applyAcc(const _Vector& acc)
    {
        this->acc += acc;
    }

    // ���������ʱ��dt��ģ���˶�
    void simulate(const _Point& pos, Number dt)
    {
        vel += (acc * dt);
        pos += (vel * dt);
    }

protected:
    _Vector vel;                        // velocity �ٶ�
    _Vector acc;                        // acceleration ���ٶ�

}; // class Motion<Number, len>

} // namespace phys

} // namespace mytricks


#endif // _MOTION_HPP_
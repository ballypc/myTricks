#ifndef _TRANSLATION_HPP_
# define _TRANSLATION_HPP_ 1


# include "../../math/vector/LinearVector.hpp"
# include "../../math/geometry/Point.hpp"


namespace mytricks {

namespace phys {

// ��ʾһ���˶�(��)
template<typename Number, unsigned int n>
class Translation {

	typedef math::LinearVector<Number, n>   _LinearVector;
	typedef math::Point<Number, n>  _Point;

public:
    typedef Number  value_type;

    // ���캯��
    explicit Translation (const _LinearVector& v) : vel(v), acc()
    {
        this->init();
    }

    virtual ~Translation () {}

    // ��ʼʱ����Ϊ0
    void init (void)
    {
        acc.setZero();
    }


    // ����һ�����ٶ�
    void applyAcc (const _LinearVector& acc)
    {
        this->acc += acc;
    }

    // ���������ʱ��dt��ģ���˶�
    void simulate (_Point& pos, Number dt)
    {
        vel += (acc * dt);
        pos.translate(vel * dt);
    }


protected:
    _LinearVector vel;              // velocity �ٶ�
    _LinearVector acc;              // acceleration ���ٶ�


}; // class Translation<Number, n>

} // namespace phys

} // namespace mytricks


#endif // _TRANSLATION_HPP_
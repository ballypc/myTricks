#ifndef _MOTION_HPP_
# define _MOTION_HPP_ 1


# include "Motion/Translation.hpp"
# include "Motion/Translation.hpp"


namespace mytricks {

namespace phys {

// ��ʾһ���˶�(��)
template<typename Number, unsigned int n>
class Motion {

	typedef math::LinearVector<Number, n> _Vector;
	typedef math::Point<Number, n> _Point;

public:
    // ���캯��
    Motion(void)
    {
        this->init();
    }

    virtual ~Motion() {}

    // ��ʼʱ����Ϊ0
    void init(void)
    {
        ;
    }


    // ���������ʱ��dt��ģ���˶�
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
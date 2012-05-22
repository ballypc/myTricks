#ifndef _MOTION_3D_HPP_
# define _MOTION_3D_HPP_ 1


# include "Motion.hpp"
# include "../math/vector/Vector_3D.hpp"
# include "../math/geometry/Point_3D.hpp"


namespace mytricks {

namespace phys {

// 表示一个运动(点)
template<typename Number>
class Motion3 : public Motion<Number, 3> {
public:
    typedef math::Vector3<Number> _Vector3;
    typedef Motion<Number, 3> _Motion3Base;

    Motion3(const _Vector3& v) : _Motion3Base(v)    // 构造函数
    {
        ; // no-op
    }

}; // class Motion3<Number>

} // namespace phys

} // namespace mytricks


#endif // _MOTION_3D_HPP_
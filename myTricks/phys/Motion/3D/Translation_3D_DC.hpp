#ifndef _TRANSLATION_3D_DC_HPP_
# define _TRANSLATION_3D_DC_HPP_ 1


# include "../Translation.hpp"
# include "../../../math/vector/3D/LinearVector_3D_DC.hpp"
# include "../../../math/geometry/3D/Point_3D_DC.hpp"


namespace mytricks {

namespace phys {

// 表示一个运动(点)
template<typename Number>
class Translation3 : public Translation<Number, 3> {

    typedef Translation<Number, 3>  _Base;
    typedef math::LinearVector<Number, 3>   _Vector3;

public:
    typedef Number  value_type;

    explicit Translation3(const _Vector3& v) : _Base(v)     // 构造函数
    {
        ; // no-op
    }


}; // class Translation3<Number>

} // namespace phys

} // namespace mytricks


#endif // _TRANSLATION_3D_DC_HPP_
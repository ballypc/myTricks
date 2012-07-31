#ifndef _VECTOR_3D_HPP_INCLUDED_
# define _VECTOR_3D_HPP_INCLUDED_ 1


/**********************************************************************\
*
*
\**********************************************************************/


# include "LinearVector_3D.hpp"


namespace mytricks {

namespace math {

// 定义一个通用的3D向量类
template<typename Number>
class Vector3 : public LinearVector3<Number> {

    typedef LinearVector3<Number>   _Base;

public:
    typedef Number  value_type;

// 基本功能
    Vector3 (void) : _Base()    // 默认构造函数 x = y = z = 0
    {
        ;   // no-op
    }

    Vector3 (Number xv, Number yv, Number zv) : _Base(xv, yv, zv)   // 构造函数
    {
        ;   // no-op
    }

    Vector3 (const Number* ptr) : _Base(ptr)    // Constructor
    {
        ;   // no-op
    }

    // 复制构造函数
    Vector3 (const LinearVector<Number, 3>& v) : _Base(v)
    {
        ;   // no-op
    }


}; // class Vector3<Number>

/*
typedef Vector3<float> Vector3f;
typedef Vector3<double> Vector3d;
*/

} // namespace math

} // namespace mytricks


#endif // _VECTOR_3D_HPP_INCLUDED_
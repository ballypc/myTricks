#ifndef _WORLD_3D_HPP_INCLUDED_
# define _WORLD_3D_HPP_INCLUDED_


/**********************************************************************\
*
*
\**********************************************************************/


# include <vector>

# include "Camera_3D.hpp"
# include "Actor_3D.hpp"


namespace mytricks {

namespace world_3d {

template<typename Number>
class World {
/**********************************\
* World
* Virtual Class, CANNOT be instantiated.
* should be Derived.
\**********************************/
public:
    /*virtual bool Load() = 0;*/    // Parameter type can't be decided.
    /*virtual bool Save() = 0;*/    // Parameter type can't be decided.

protected:
    World(void) : actors() {}
    virtual ~World() {}

    std::vector<Actor<Number>*> actors;

}; // class World<Number>

} // namespace world_3d

} // namespace mytricks


#endif // _WORLD_3D_HPP_INCLUDED_
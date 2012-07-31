#ifndef _POINT_3D_HPP_INCLUDED_
# define _POINT_3D_HPP_INCLUDED_


/**********************************************************************\
*
*
\**********************************************************************/


# if (defined(_MSC_VER) && (_MSC_VER <= 1200))
#  include "3D/Point_3D_DC.hpp"
# else
#  include "3D/Point_3D_CTPS.hpp"
# endif


#endif // _POINT_3D_HPP_INCLUDED_
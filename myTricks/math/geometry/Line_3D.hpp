#ifndef _LINE_3D_HPP_INCLUDED_
# define _LINE_3D_HPP_INCLUDED_


/**********************************************************************\
*
*
\**********************************************************************/


# if (defined(_MSC_VER) && (_MSC_VER <= 1200))
#  include "3D/Line_3D_DC.hpp"
# else
#  include "3D/Line_3D_CTPS.hpp"
# endif


#endif // _LINE_3D_HPP_INCLUDED_
#ifndef _LINEARVECTOR_3D_HPP_INCLUDED_
# define _LINEARVECTOR_3D_HPP_INCLUDED_ 1


/**********************************************************************\
*
*
\**********************************************************************/


# if (defined(_MSC_VER) && (_MSC_VER <= 1200))
#  include "3D/LinearVector_3D_DC.hpp"
# else
#  include "3D/LinearVector_3D_CTPS.hpp"
# endif


#endif // _LINEARVECTOR_3D_HPP_INCLUDED_
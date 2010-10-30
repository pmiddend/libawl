#ifndef AWL_BACKENDS_X11_DELETER_HPP_INCLUDED
#define AWL_BACKENDS_X11_DELETER_HPP_INCLUDED

#include <X11/Xlib.h>

namespace awl
{
namespace backends
{
namespace x11
{

template<
	typename T
>
struct deleter
{
	void
	operator()(
		T *const _param
	) const
	{
		::XFree(
			_param
		);
	}
		
};

}
}
}

#endif

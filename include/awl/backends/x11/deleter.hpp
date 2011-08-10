#ifndef AWL_BACKENDS_X11_DELETER_HPP_INCLUDED
#define AWL_BACKENDS_X11_DELETER_HPP_INCLUDED

#include <awl/backends/x11/free.hpp>

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
		x11::free(
			_param
		);
	}

};

}
}
}

#endif

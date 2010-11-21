#ifndef AWL_BACKENDS_WINDOWS_WNDCLASS_REMOVE_CALLBACK_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_WNDCLASS_REMOVE_CALLBACK_HPP_INCLUDED

#include <fcppt/function/object.hpp>

namespace awl
{
namespace backends
{
namespace windows
{

typedef fcppt::function::object<
	void ()
> wndclass_remove_callback;

}
}
}

#endif

#ifndef AWL_BACKENDS_WINDOWS_WNDCLASS_REMOVE_CALLBACK_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_WNDCLASS_REMOVE_CALLBACK_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <functional>
#include <fcppt/config/external_end.hpp>


namespace awl
{
namespace backends
{
namespace windows
{

typedef std::function<
	void ()
> wndclass_remove_callback;

}
}
}

#endif

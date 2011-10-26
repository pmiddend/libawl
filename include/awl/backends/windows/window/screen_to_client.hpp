#ifndef AWL_BACKENDS_WINDOWS_WINDOW_SCREEN_TO_CLIENT_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_WINDOW_SCREEN_TO_CLIENT_HPP_INCLUDED

#include <awl/backends/windows/window/instance_fwd.hpp>
#include <awl/backends/windows/windows.hpp>
#include <awl/symbol.hpp>

namespace awl
{
namespace backends
{
namespace windows
{
namespace window
{

AWL_SYMBOL
POINT const
screen_to_client(
	window::instance const &,
	POINT const &
);

}
}
}
}

#endif

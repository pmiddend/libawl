#ifndef AWL_BACKENDS_WINDOWS_WINDOW_CLIENT_RECT_TO_SCREEN_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_WINDOW_CLIENT_RECT_TO_SCREEN_HPP_INCLUDED

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
RECT const
client_rect_to_screen(
	window::instance const &,
	RECT const &
);

}
}
}
}

#endif
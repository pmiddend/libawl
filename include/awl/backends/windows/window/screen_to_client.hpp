#ifndef AWL_BACKENDS_WINDOWS_WINDOW_SCREEN_TO_CLIENT_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_WINDOW_SCREEN_TO_CLIENT_HPP_INCLUDED

#include <awl/symbol.hpp>
#include <awl/backends/windows/optional_point_fwd.hpp>
#include <awl/backends/windows/windows.hpp>
#include <awl/backends/windows/window/object_fwd.hpp>


namespace awl
{
namespace backends
{
namespace windows
{
namespace window
{

AWL_SYMBOL
awl::backends::windows::optional_point const
screen_to_client(
	awl::backends::windows::window::object const &,
	POINT const &
);

}
}
}
}

#endif

#ifndef AWL_BACKENDS_WINDOWS_WINDOW_GET_CLIENT_RECT_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_WINDOW_GET_CLIENT_RECT_HPP_INCLUDED

#include <awl/symbol.hpp>
#include <awl/backends/windows/optional_rect_fwd.hpp>
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
awl::backends::windows::optional_rect const
get_client_rect(
	awl::backends::windows::window::object const &
);

}
}
}
}

#endif

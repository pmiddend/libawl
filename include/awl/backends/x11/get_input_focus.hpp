#ifndef AWL_BACKENDS_X11_GET_INPUT_FOCUS_HPP_INCLUDED
#define AWL_BACKENDS_X11_GET_INPUT_FOCUS_HPP_INCLUDED

#include <awl/backends/x11/display_fwd.hpp>
#include <awl/backends/x11/screen.hpp>
#include <awl/backends/x11/window/object_unique_ptr.hpp>


namespace awl
{
namespace backends
{
namespace x11
{

awl::backends::x11::window::object_unique_ptr
get_input_focus(
	awl::backends::x11::display &,
	awl::backends::x11::screen
);

}
}
}

#endif

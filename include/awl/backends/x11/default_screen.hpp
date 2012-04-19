#ifndef AWL_BACKENDS_X11_DEFAULT_SCREEN_HPP_INCLUDED
#define AWL_BACKENDS_X11_DEFAULT_SCREEN_HPP_INCLUDED

#include <awl/symbol.hpp>
#include <awl/backends/x11/display_fwd.hpp>
#include <awl/backends/x11/screen.hpp>


namespace awl
{
namespace backends
{
namespace x11
{

AWL_SYMBOL
awl::backends::x11::screen const
default_screen(
	awl::backends::x11::display const &
);

}
}
}

#endif

#ifndef AWL_WINDOW_HAS_FOCUS_HPP_INCLUDED
#define AWL_WINDOW_HAS_FOCUS_HPP_INCLUDED

#include <awl/system/object_fwd.hpp>
#include <awl/window/object_fwd.hpp>
#include <awl/symbol.hpp>


namespace awl
{
namespace window
{

AWL_SYMBOL
bool
has_focus(
	awl::system::object &,
	awl::window::object const &
);

}
}

#endif

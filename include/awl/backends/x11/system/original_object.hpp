#ifndef AWL_BACKENDS_X11_SYSTEM_ORIGINAL_OBJECT_HPP_INCLUDED
#define AWL_BACKENDS_X11_SYSTEM_ORIGINAL_OBJECT_HPP_INCLUDED

#include <awl/symbol.hpp>
#include <awl/backends/x11/display_fwd.hpp>
#include <awl/backends/x11/original_display.hpp>
#include <awl/backends/x11/screen.hpp>
#include <awl/backends/x11/system/object.hpp>
#include <awl/visual/object_unique_ptr.hpp>
#include <awl/window/object_unique_ptr.hpp>
#include <fcppt/noncopyable.hpp>


namespace awl
{
namespace backends
{
namespace x11
{
namespace system
{

class original_object
:
	public awl::backends::x11::system::object
{
	FCPPT_NONCOPYABLE(
		original_object
	);
public:
	// NOTE: We could add a string specifying which display to connect
	// to here
	AWL_SYMBOL
	original_object();

	AWL_SYMBOL
	~original_object();

	AWL_SYMBOL
	awl::window::object_unique_ptr
	create_window(
		awl::window::parameters const &
	);

	AWL_SYMBOL
	awl::visual::object_unique_ptr
	default_visual();

	AWL_SYMBOL
	awl::backends::x11::display &
	display();

	AWL_SYMBOL
	awl::backends::x11::screen const
	screen() const;
private:
	awl::backends::x11::original_display display_;

	awl::backends::x11::screen const screen_;
};

}
}
}
}

#endif

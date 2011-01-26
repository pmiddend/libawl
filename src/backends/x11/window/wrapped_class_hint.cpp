#include <awl/backends/x11/window/wrapped_class_hint.hpp>
#include <awl/exception.hpp>
#include <fcppt/text.hpp>
#include <X11/Xlib.h>

awl::backends::x11::window::wrapped_class_hint::wrapped_class_hint(
	Display *const _display,
	Window const _window
)
{
	if(
		::XGetClassHint(
			_display,
			_window,
			&data_
		)
		== 0
	)
		throw awl::exception(
			FCPPT_TEXT("XGetClassHint() failed!")
		);
}

awl::backends::x11::window::wrapped_class_hint::~wrapped_class_hint()
{
	::XFree(
		data_.res_name
	);

	::XFree(
		data_.res_class
	);
}

fcppt::string const
awl::backends::x11::window::wrapped_class_hint::res_name() const
{
	return data_.res_name;
}

fcppt::string const
awl::backends::x11::window::wrapped_class_hint::res_class() const
{
	return data_.res_class;
}

#include <awl/backends/x11/window/wrapped_class_hint.hpp>
#include <awl/backends/x11/free.hpp>
#include <X11/Xlib.h>

awl::backends::x11::window::wrapped_class_hint::wrapped_class_hint(
	Display *const _display,
	Window const _window
)
:
	data_()
{
	if(
		::XGetClassHint(
			_display,
			_window,
			&data_
		)
		== 0
	)
		data_.res_name = data_.res_class = 0;
}

awl::backends::x11::window::wrapped_class_hint::~wrapped_class_hint()
{
	x11::free(
		data_.res_name
	);

	x11::free(
		data_.res_class
	);
}

bool
awl::backends::x11::window::wrapped_class_hint::has_data() const
{
	return
		data_.res_name
		&& data_.res_class;
}

std::string const
awl::backends::x11::window::wrapped_class_hint::res_name() const
{
	return data_.res_name;
}

std::string const
awl::backends::x11::window::wrapped_class_hint::res_class() const
{
	return data_.res_class;
}

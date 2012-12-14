#include <awl/backends/windows/get_focus.hpp>
#include <awl/backends/windows/windows.hpp>
#include <awl/backends/windows/window/object_unique_ptr.hpp>
#include <awl/backends/windows/window/wrapped_object.hpp>
#include <fcppt/make_unique_ptr.hpp>


awl::backends::windows::window::object_unique_ptr
awl::backends::windows::get_focus()
{
	HWND const ret(
		::GetFocus()
	);

	return
		ret
		==
		nullptr
		?
			awl::backends::windows::window::object_unique_ptr()
		:
			awl::backends::windows::window::object_unique_ptr(
				fcppt::make_unique_ptr<
					awl::backends::windows::window::wrapped_object
				>(
					ret
				)
			)
		;
}


#include <awl/backends/windows/windows.hpp>
#include <awl/backends/windows/cursor/const_optional_object_ref.hpp>
#include <awl/backends/windows/visual/null_object.hpp>
#include <awl/backends/windows/window/common_object.hpp>
#include <awl/backends/windows/window/wrapped_object.hpp>
#include <awl/visual/object_fwd.hpp>
#include <fcppt/make_unique_ptr.hpp>


awl::backends::windows::window::wrapped_object::wrapped_object(
	HWND const _hwnd
)
:
	awl::backends::windows::window::common_object(),
	visual_(
		fcppt::make_unique_ptr<
			awl::backends::windows::visual::null_object
		>()
	),
	hwnd_(
		_hwnd
	)
{
}

awl::backends::windows::window::wrapped_object::~wrapped_object()
{
}

HWND
awl::backends::windows::window::wrapped_object::hwnd() const
{
	return
		hwnd_;
}

awl::backends::windows::cursor::const_optional_object_ref const
awl::backends::windows::window::wrapped_object::cursor() const
{
	return
		awl::backends::windows::cursor::const_optional_object_ref();
}

awl::visual::object const &
awl::backends::windows::window::wrapped_object::visual() const
{
	return
		*visual_;
}

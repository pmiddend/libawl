#include <awl/backends/windows/windows.hpp>
#include <awl/backends/windows/wndclass_fwd.hpp>
#include <awl/backends/windows/wndclass_remove_callback.hpp>
#include <awl/backends/windows/cursor/const_optional_object_ref.hpp>
#include <awl/backends/windows/cursor/object.hpp>
#include <awl/backends/windows/visual/object.hpp>
#include <awl/backends/windows/window/common_object.hpp>
#include <awl/backends/windows/window/create.hpp>
#include <awl/backends/windows/window/original_object.hpp>
#include <awl/visual/object_fwd.hpp>
#include <awl/window/parameters.hpp>
#include <fcppt/static_optional_cast.hpp>
#include <fcppt/cast/static_downcast.hpp>


awl::backends::windows::window::original_object::original_object(
	awl::window::parameters const &_param,
	awl::backends::windows::wndclass &_wndclass,
	awl::backends::windows::wndclass_remove_callback const &_remove_wndclass
)
:
	awl::backends::windows::window::common_object(),
	visual_(
		_param.visual()
	),
	holder_(
		awl::backends::windows::window::create(
			_param,
			_wndclass
		),
		_remove_wndclass
	),
	cursor_(
		fcppt::static_optional_cast<
			awl::backends::windows::cursor::object const
		>(
			_param.cursor()
		)
	)
{
	fcppt::cast::static_downcast<
		awl::backends::windows::visual::object const &
	>(
		_param.visual()
	).apply(
		this->hwnd()
	);
}

awl::backends::windows::window::original_object::~original_object()
{
}

HWND
awl::backends::windows::window::original_object::hwnd() const
{
	return
		holder_.get();
}

awl::backends::windows::cursor::const_optional_object_ref const
awl::backends::windows::window::original_object::cursor() const
{
	return
		cursor_;
}

awl::visual::object const &
awl::backends::windows::window::original_object::visual() const
{
	return
		visual_;
}

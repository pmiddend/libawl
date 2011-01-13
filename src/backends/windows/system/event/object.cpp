#include <awl/backends/windows/system/event/object.hpp>

awl::backends::windows::system::event::object::object(
	WPARAM const _wparam,
	LPARAM const _lparam
)
:
	wparam_(_wparam),
	lparam_(_lparam)
{
}

WPARAM
awl::backends::windows::system::event::object::wparam() const
{
	return wparam_;
}

LPARAM
awl::backends::windows::system::event::object::lparam() const
{
	return lparam_;
}

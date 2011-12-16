#include <awl/backends/windows/event/lparam.hpp>
#include <awl/backends/windows/event/wparam.hpp>
#include <awl/backends/windows/window/event/object.hpp>


awl::backends::windows::window::event::object::object(
	awl::backends::windows::event::wparam const _wparam,
	awl::backends::windows::event::lparam const _lparam
)
:
	wparam_(_wparam),
	lparam_(_lparam)
{
}

awl::backends::windows::event::wparam const
awl::backends::windows::window::event::object::wparam() const
{
	return wparam_;
}

awl::backends::windows::event::lparam const
awl::backends::windows::window::event::object::lparam() const
{
	return lparam_;
}

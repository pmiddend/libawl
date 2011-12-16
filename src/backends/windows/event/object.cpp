#include <awl/backends/windows/event/lparam.hpp>
#include <awl/backends/windows/event/object.hpp>
#include <awl/backends/windows/event/type.hpp>
#include <awl/backends/windows/event/wparam.hpp>


awl::backends::windows::event::object::object(
	awl::backends::windows::event::type const _type,
	awl::backends::windows::event::wparam const _wparam,
	awl::backends::windows::event::lparam const _lparam
)
:
	type_(
		_type
	),
	wparam_(
		_wparam
	),
	lparam_(
		_lparam
	)
{
}

awl::backends::windows::event::type const
awl::backends::windows::event::object::type() const
{
	return type_;
}

awl::backends::windows::event::wparam const
awl::backends::windows::event::object::wparam() const
{
	return wparam_;
}

awl::backends::windows::event::lparam const
awl::backends::windows::event::object::lparam() const
{
	return lparam_;
}

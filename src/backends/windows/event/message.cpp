#include <awl/backends/windows/windows.hpp>
#include <awl/backends/windows/event/message.hpp>
	
awl::backends::windows::event::message::message(
	MSG const &_msg
)
:
	msg_(
		_msg
	)
{
}

MSG const &
awl::backends::windows::event::message::get() const
{
	return msg_;
}

#include <awl/backends/windows/event/type.hpp>
#include <awl/backends/windows/window/event/processor.hpp>
#include <awl/backends/windows/window/event/scoped_user_message.hpp>


awl::backends::windows::window::event::scoped_user_message::scoped_user_message(
	awl::backends::windows::window::event::processor &_processor
)
:
	processor_(
		_processor
	),
	type_(
		_processor.allocate_user_message()
	)
{
}

awl::backends::windows::window::event::scoped_user_message::~scoped_user_message()
{
	processor_.free_user_message(
		type_
	);
}

awl::backends::windows::event::type const
awl::backends::windows::window::event::scoped_user_message::type() const
{
	return type_;
}

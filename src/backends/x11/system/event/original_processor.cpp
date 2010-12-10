#include <awl/backends/x11/system/event/original_processor.hpp>

awl::backends::x11::system::event::original_processor::original_processor(
	x11::system::object_ptr const _system
)
:
	system_(_system)
{
}

awl::backends::x11::system::event::original_processor::~original_processor()
{
}

fcppt::signal::auto_connection
awl::backends::x11::system::event::original_processor::register_callback(
	x11::system::event::opcode const &_opcode,
	x11::system::event::type const &_type,
	x11::system::event::callback const &_callback
)
{
	return
		signals_[
			event::map_key(
				_opcode,
				_type
			)
		].connect(
			_callback
		);

}

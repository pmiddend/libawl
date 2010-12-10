#include <awl/backends/x11/system/event/map_key.hpp>

awl::backends::x11::system::event::map_key::map_key(
	event::opcode const &_opcode,
	event::type const &_type
)
:
	opcode_(_opcode),
	type_(_type)
{
}

awl::backends::x11::system::event::opcode const &
awl::backends::x11::system::event::map_key::opcode() const
{
	return opcode_;
}

awl::backends::x11::system::event::type const &
awl::backends::x11::system::event::map_key::type() const
{
	return type_;
}

bool
awl::backends::x11::system::event::operator<(
	event::map_key const &_a,
	event::map_key const &_b
)
{
	return
		_a.opcode()
		== _b.opcode()
		?
			_a.type() < _b.type()
		:
			_a.opcode() < _b.opcode();
}

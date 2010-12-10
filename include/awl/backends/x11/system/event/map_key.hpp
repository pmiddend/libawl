#ifndef AWL_BACKENDS_X11_SYSTEM_EVENT_MAP_KEY_HPP_INCLUDED
#define AWL_BACKENDS_X11_SYSTEM_EVENT_MAP_KEY_HPP_INCLUDED

#include <awl/backends/x11/system/event/opcode.hpp>
#include <awl/backends/x11/system/event/type.hpp>
#include <awl/symbol.hpp>

namespace awl
{
namespace backends
{
namespace x11
{
namespace system
{
namespace event
{

class map_key
{
public:
	AWL_SYMBOL
	map_key(
		event::opcode const &,
		event::type const &
	);

	AWL_SYMBOL
	event::opcode const &
	opcode() const;

	AWL_SYMBOL
	event::type const &
	type() const;
private:
	event::opcode opcode_;

	event::type type_;
};

bool
operator<(
	event::map_key const &,
	event::map_key const &
);

}
}
}
}
}

#endif

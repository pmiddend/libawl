#ifndef AWL_BACKENDS_X11_SYSTEM_EVENT_MAP_KEY_HPP_INCLUDED
#define AWL_BACKENDS_X11_SYSTEM_EVENT_MAP_KEY_HPP_INCLUDED

#include <awl/symbol.hpp>
#include <awl/backends/x11/system/event/opcode.hpp>
#include <awl/backends/x11/system/event/type.hpp>


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
		awl::backends::x11::system::event::opcode const &,
		awl::backends::x11::system::event::type const &
	);

	AWL_SYMBOL
	awl::backends::x11::system::event::opcode const &
	opcode() const;

	AWL_SYMBOL
	awl::backends::x11::system::event::type const &
	type() const;
private:
	awl::backends::x11::system::event::opcode opcode_;

	awl::backends::x11::system::event::type type_;
};

bool
operator<(
	awl::backends::x11::system::event::map_key const &,
	awl::backends::x11::system::event::map_key const &
);

}
}
}
}
}

#endif

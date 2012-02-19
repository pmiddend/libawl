#ifndef AWL_SYSTEM_EVENT_QUIT_HPP_INCLUDED
#define AWL_SYSTEM_EVENT_QUIT_HPP_INCLUDED

#include <awl/symbol.hpp>
#include <awl/main/exit_code.hpp>
#include <awl/system/event/quit_fwd.hpp>


namespace awl
{
namespace system
{
namespace event
{

class quit
{
public:
	AWL_SYMBOL
	explicit
	quit(
		awl::main::exit_code
	);

	AWL_SYMBOL
	awl::main::exit_code const
	exit_code() const;
private:
	awl::main::exit_code exit_code_;
};

}
}
}

#endif

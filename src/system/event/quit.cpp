#include <awl/main/exit_code.hpp>
#include <awl/system/event/quit.hpp>


awl::system::event::quit::quit(
	awl::main::exit_code const _exit_code
)
:
	exit_code_(
		_exit_code
	)
{
}

awl::main::exit_code const
awl::system::event::quit::exit_code() const
{
	return
		exit_code_;
}

#include <awl/main/function_context.hpp>

awl::main::function_context::function_context(
	int const _argc,
	char *_argv[],
	main::optional_show_command const &_show_command)
:
	argc_(
		_argc),
	argv_(
		_argv),
	show_command_(
		_show_command)
{
}

int
awl::main::function_context::argc() const
{
	return argc_;
}

char**
awl::main::function_context::argv() const
{
	return argv_;
}

awl::main::optional_show_command const &
awl::main::function_context::show_command()
{
	return show_command_;
}

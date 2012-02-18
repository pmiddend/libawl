#include <awl/main/function_context.hpp>

awl::main::function_context::function_context(
	int const _argc,
	char *_argv[])
:
	argc_(
		_argc),
	argv_(
		_argv)
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

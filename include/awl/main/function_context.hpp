#ifndef AWL_MAIN_FUNCTION_CONTEXT_HPP_INCLUDED
#define AWL_MAIN_FUNCTION_CONTEXT_HPP_INCLUDED

#include <awl/main/optional_show_command.hpp>
#include <awl/symbol.hpp>
#include <fcppt/optional_impl.hpp>

namespace awl
{
namespace main
{
class function_context
{
public:
	AWL_SYMBOL
	explicit
	function_context(
		int argc,
		char *argv[],
		main::optional_show_command const &);

	AWL_SYMBOL
	int
	argc() const;

	AWL_SYMBOL
	char**
	argv() const;

	AWL_SYMBOL
	main::optional_show_command const &
	show_command();
private:
	int argc_;
	char **argv_;
	main::optional_show_command show_command_;
};
}
}

#endif


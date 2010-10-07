#include <awl/log_context.hpp>
#include <fcppt/log/context.hpp>

fcppt::log::context &
awl::log_context()
{
	static fcppt::log::context context_;
	return context_;
}

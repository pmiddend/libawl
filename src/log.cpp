#include <awl/log.hpp>
#include <awl/log_context.hpp>
#include <fcppt/log/parameters/root.hpp>
#include <fcppt/io/clog.hpp>
#include <fcppt/text.hpp>

fcppt::log::object &
awl::log()
{
	static fcppt::log::object l(
		fcppt::log::parameters::root(
			fcppt::io::clog)
		.prefix(
			FCPPT_TEXT("awl"))
		.enabled(
			true)
		.level(
			fcppt::log::level::debug)
		.context(
			log_context())
		.create());
	return l;
}

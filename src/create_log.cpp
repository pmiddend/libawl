#include <awl/create_log.hpp>
#include <awl/log_context.hpp>
#include <fcppt/log/level.hpp>
#include <fcppt/log/location.hpp>
#include <fcppt/log/parameters/all.hpp>
#include <fcppt/log/parameters/with_context.hpp>
#include <fcppt/io/clog.hpp>

fcppt::log::parameters::all const
awl::create_log(
	fcppt::log::location const &_location
)
{
	return
		fcppt::log::parameters::with_context(
			awl::log_context(),
			fcppt::io::clog,
			_location
		)
		.level_defaults(
			fcppt::log::level::warning
		)
		.enabled(
			true
		);
}

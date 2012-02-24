#include <awl/create_log.hpp>
#include <awl/log_context.hpp>
#include <fcppt/io/clog.hpp>
#include <fcppt/log/level.hpp>
#include <fcppt/log/location.hpp>
#include <fcppt/log/parameters/object.hpp>
#include <fcppt/log/parameters/with_context.hpp>


fcppt::log::parameters::object const
awl::create_log(
	fcppt::log::location const &_location
)
{
	return
		fcppt::log::parameters::with_context(
			awl::log_context(),
			_location
		)
		.level_defaults(
			fcppt::io::clog(),
			fcppt::log::level::warning
		)
		.enabled(
			true
		);
}

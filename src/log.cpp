#include <awl/log.hpp>
#include <awl/create_log.hpp>
#include <awl/log_location.hpp>
#include <fcppt/log/parameters/all.hpp>
#include <fcppt/log/object.hpp>

namespace
{

fcppt::log::object logger(
	awl::create_log(
		awl::log_location()
	)
);

}

fcppt::log::object &
awl::log()
{
	return logger;
}

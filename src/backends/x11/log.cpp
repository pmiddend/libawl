#include <awl/create_log.hpp>
#include <awl/log_location.hpp>
#include <awl/backends/x11/log.hpp>
#include <fcppt/log/object.hpp>
#include <fcppt/log/parameters/object.hpp>


namespace
{

fcppt::log::object logger(
	awl::create_log(
		awl::log_location()
		/
		FCPPT_TEXT("x11")
	)
);

}

fcppt::log::object &
awl::backends::x11::log()
{
	return logger;
}

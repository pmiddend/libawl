#include <awl/log_location.hpp>
#include <fcppt/text.hpp>
#include <fcppt/log/location.hpp>


fcppt::log::location const
awl::log_location()
{
	return
		fcppt::log::location(
			FCPPT_TEXT("awl")
		);
}

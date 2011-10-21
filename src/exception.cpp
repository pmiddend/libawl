#include <awl/exception.hpp>
#include <fcppt/assert/make_message.hpp>


awl::exception::exception(
	fcppt::string const &_string
)
:
	fcppt::exception(
		_string
	)
{}

awl::exception::exception(
	fcppt::assert_::information const &_info
)
:
	fcppt::exception(
		fcppt::assert_::make_message(
			_info
		)
	)
{
}

awl::exception::~exception() throw()
{
}

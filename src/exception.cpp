#include <awl/exception.hpp>

awl::exception::exception(
	fcppt::string const &_string
)
:
	fcppt::exception(
		_string
	)
{}

awl::exception::~exception() throw()
{
}

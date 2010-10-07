#include <awl/exception.hpp>

awl::exception::exception(
	fcppt::string const &string_)
:
	fcppt::exception(
		string_)
{}

awl::exception::~exception() throw()
{
}

#ifndef AWL_EXCEPTION_HPP_INCLUDED
#define AWL_EXCEPTION_HPP_INCLUDED

#include <fcppt/assert/information_fwd.hpp>
#include <fcppt/exception.hpp>
#include <fcppt/string.hpp>

namespace awl
{

class exception
:
	public fcppt::exception
{
public:
	explicit
	exception(
		fcppt::string const &
	);

	explicit
	exception(
		fcppt::assert_::information const &
	);

	virtual ~exception() throw();
};

}

#endif

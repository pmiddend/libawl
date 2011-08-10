#ifndef AWL_EXCEPTION_HPP_INCLUDED
#define AWL_EXCEPTION_HPP_INCLUDED

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
		fcppt::string const &);

	virtual ~exception() throw();
};
}

#endif

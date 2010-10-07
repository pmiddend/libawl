#ifndef AWL_WINDOW_INSTANCE_HPP_INCLUDED
#define AWL_WINDOW_INSTANCE_HPP_INCLUDED

#include <fcppt/noncopyable.hpp>

namespace awl
{
namespace window
{
class instance
{
FCPPT_NONCOPYABLE(instance)
public:
	explicit
	instance();

	virtual void
	show() = 0;

	~instance();
};
}
}

#endif

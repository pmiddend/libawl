#ifndef AWL_EVENT_PROCESSOR_HPP_INCLUDED
#define AWL_EVENT_PROCESSOR_HPP_INCLUDED

#include <awl/event/processor_fwd.hpp>
#include <fcppt/noncopyable.hpp>

namespace awl
{
namespace event
{

class processor
{
	FCPPT_NONCOPYABLE(
		processor
	)
protected:
	processor();
public:
	virtual void
	dispatch() = 0;

	virtual ~processor();
};

}
}

#endif

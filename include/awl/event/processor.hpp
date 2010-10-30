#ifndef AWL_EVENT_PROCESSOR_HPP_INCLUDED
#define AWL_EVENT_PROCESSOR_HPP_INCLUDED

#include <awl/event/processor_fwd.hpp>
#include <awl/class_symbol.hpp>
#include <awl/symbol.hpp>
#include <fcppt/noncopyable.hpp>

namespace awl
{
namespace event
{

class AWL_CLASS_SYMBOL processor
{
	FCPPT_NONCOPYABLE(
		processor
	)
protected:
	AWL_SYMBOL
	processor();
public:
	virtual void
	dispatch() = 0;

	AWL_SYMBOL
	virtual ~processor();
};

}
}

#endif

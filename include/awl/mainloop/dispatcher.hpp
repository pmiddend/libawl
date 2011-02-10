#ifndef AWL_MAINLOOP_DISPATCHER_HPP_INCLUDED
#define AWL_MAINLOOP_DISPATCHER_HPP_INCLUDED

#include <awl/mainloop/dispatcher_fwd.hpp>
#include <awl/class_symbol.hpp>
#include <awl/symbol.hpp>
#include <fcppt/noncopyable.hpp>

namespace awl
{
namespace mainloop
{

class AWL_CLASS_SYMBOL dispatcher
{
	FCPPT_NONCOPYABLE(
		dispatcher
	);
protected:
	AWL_SYMBOL
	dispatcher();
public:
	AWL_SYMBOL
	virtual ~dispatcher();

	virtual void
	stop() = 0;

	virtual bool
	is_stopped() const = 0;
};

}
}

#endif

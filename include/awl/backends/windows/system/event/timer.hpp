#ifndef AWL_BACKENDS_WINDOWS_SYSTEM_EVENT_TIMER_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_SYSTEM_EVENT_TIMER_HPP_INCLUDED

#include <awl/backends/windows/system/event/timer_fwd.hpp>
#include <awl/backends/windows/windows.hpp>
#include <awl/symbol.hpp>
#include <fcppt/noncopyable.hpp>

namespace awl
{
namespace backends
{
namespace windows
{
namespace system
{
namespace event
{

class timer
{
	FCPPT_NONCOPYABLE(
		timer
	)
public:
	AWL_SYMBOL
	explicit timer(
		UINT elapse
	);

	AWL_SYMBOL
	~timer();

	AWL_SYMBOL
	UINT_PTR
	id() const;
private:
	UINT_PTR const id_;
};

}
}
}
}
}

#endif

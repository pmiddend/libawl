#ifndef AWL_EVENT_SCOPED_WINDOW_PROCESSOR_HPP_INCLUDED
#define AWL_EVENT_SCOPED_WINDOW_PROCESSOR_HPP_INCLUDED

#include <awl/symbol.hpp>
#include <awl/event/processor_fwd.hpp>
#include <awl/event/scoped_window_processor_fwd.hpp>
#include <awl/window/event/processor_fwd.hpp>
#include <fcppt/noncopyable.hpp>

namespace awl
{
namespace event
{

class scoped_window_processor
{
	FCPPT_NONCOPYABLE(
		scoped_window_processor
	);
public:
	AWL_SYMBOL
	scoped_window_processor(
		awl::event::processor &,
		awl::window::event::processor &
	);

	AWL_SYMBOL
	~scoped_window_processor();
private:
	awl::event::processor &processor_;

	awl::window::event::processor &window_processor_;
};

}
}

#endif

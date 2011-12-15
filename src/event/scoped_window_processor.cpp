#include <awl/event/processor.hpp>
#include <awl/event/scoped_window_processor.hpp>
#include <awl/window/event/processor_fwd.hpp>


awl::event::scoped_window_processor::scoped_window_processor(
	awl::event::processor &_processor,
	awl::window::event::processor &_window_processor
)
:
	processor_(
		_processor
	),
	window_processor_(
		_window_processor
	)
{
	processor_.attach(
		window_processor_
	);
}

awl::event::scoped_window_processor::~scoped_window_processor()
{
	processor_.detach(
		window_processor_
	);
}

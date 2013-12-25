#ifndef AWL_BACKENDS_X11_EVENT_PROCESSOR_HPP_INCLUDED
#define AWL_BACKENDS_X11_EVENT_PROCESSOR_HPP_INCLUDED

#include <awl/class_symbol.hpp>
#include <awl/symbol.hpp>
#include <awl/backends/x11/event/processor_fwd.hpp>
#include <awl/backends/x11/system/object_fwd.hpp>
#include <awl/backends/x11/system/event/optional_processor_ref.hpp>
#include <awl/backends/x11/window/event/processor_fwd.hpp>
#include <awl/event/processor.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/config/external_begin.hpp>
#include <X11/Xlib.h>
#include <map>
#include <fcppt/config/external_end.hpp>


namespace awl
{
namespace backends
{
namespace x11
{
namespace event
{

class AWL_CLASS_SYMBOL processor
:
	public awl::event::processor
{
	FCPPT_NONCOPYABLE(
		processor
	);
public:
	AWL_SYMBOL
	processor(
		awl::backends::x11::system::object &,
		awl::backends::x11::system::event::optional_processor_ref const &
	);

	AWL_SYMBOL
	~processor();

	AWL_SYMBOL
	bool
	poll();

	AWL_SYMBOL
	void
	next();

	AWL_SYMBOL
	void
	attach(
		awl::window::event::processor &
	);

	AWL_SYMBOL
	void
	detach(
		awl::window::event::processor &
	);
private:
	typedef std::map<
		Window,
		awl::backends::x11::window::event::processor *
	> window_processor_map;

	awl::backends::x11::system::object &system_;

	awl::backends::x11::system::event::optional_processor_ref const system_processor_;

	window_processor_map window_processors_;
};

}
}
}
}

#endif

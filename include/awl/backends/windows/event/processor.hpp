#ifndef AWL_BACKENDS_WINDOWS_EVENT_PROCESSOR_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_EVENT_PROCESSOR_HPP_INCLUDED

#include <awl/symbol.hpp>
#include <awl/backends/windows/windows.hpp>
#include <awl/backends/windows/event/message_fwd.hpp>
#include <awl/backends/windows/event/processor_fwd.hpp>
#include <awl/backends/windows/system/object_fwd.hpp>
#include <awl/backends/windows/system/event/optional_processor_ref.hpp>
#include <awl/backends/windows/window/event/processor_fwd.hpp>
#include <awl/event/processor.hpp>
#include <awl/window/event/processor_fwd.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/optional_decl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <map>
#include <fcppt/config/external_end.hpp>


namespace awl
{
namespace backends
{
namespace windows
{
namespace event
{

class processor
:
	public awl::event::processor
{
	FCPPT_NONCOPYABLE(
		processor
	);
public:
	AWL_SYMBOL
	processor(
		awl::backends::windows::system::object &,
		awl::backends::windows::system::event::optional_processor_ref const &
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
	void
	do_process(
		awl::backends::windows::event::message const &
	);

	bool
	poll_messages();

	awl::backends::windows::system::event::optional_processor_ref const system_processor_;

	typedef std::map<
		HWND,
		awl::backends::windows::window::event::processor *
	> window_processor_map;

	window_processor_map window_processors_;
};

}
}
}
}

#endif

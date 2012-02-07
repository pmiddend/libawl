#ifndef AWL_BACKENDS_COCOA_WINDOW_INSTANCE_HPP_INCLUDED
#define AWL_BACKENDS_COCOA_WINDOW_INSTANCE_HPP_INCLUDED

#include <awl/window/instance.hpp>
#include <awl/symbol.hpp>
#include <awl/window/parameters_fwd.hpp>
#include <awl/backends/cocoa/window/event/processor_fwd.hpp>
#include <awl/backends/cocoa/event/processor_fwd.hpp>
#include <fcppt/noncopyable.hpp>

@class NSWindow;

namespace awl
{
namespace backends
{
namespace cocoa
{
namespace window
{
class instance
:
	public awl::window::instance
{
FCPPT_NONCOPYABLE(
		instance);
public:
	AWL_SYMBOL
	explicit
	instance(
			awl::window::parameters const &);

	AWL_SYMBOL
	void
	show();

	AWL_SYMBOL
	awl::window::dim const
	size() const;

	AWL_SYMBOL
	~instance();
private:
	friend class cocoa::window::event::processor;
	friend class cocoa::event::processor;

	__strong NSWindow *window_;
};
}
}
}
}

#endif

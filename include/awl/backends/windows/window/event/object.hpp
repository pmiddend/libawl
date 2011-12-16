#ifndef AWL_BACKENDS_WINDOWS_WINDOW_EVENT_OBJECT_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_WINDOW_EVENT_OBJECT_HPP_INCLUDED

#include <awl/symbol.hpp>
#include <awl/backends/windows/event/lparam.hpp>
#include <awl/backends/windows/event/wparam.hpp>
#include <awl/backends/windows/window/event/object_fwd.hpp>


namespace awl
{
namespace backends
{
namespace windows
{
namespace window
{
namespace event
{

class object
{
public:
	AWL_SYMBOL
	object(
		awl::backends::windows::event::wparam,
		awl::backends::windows::event::lparam
	);

	AWL_SYMBOL
	awl::backends::windows::event::wparam const
	wparam() const;

	AWL_SYMBOL
	awl::backends::windows::event::lparam const
	lparam() const;
private:
	awl::backends::windows::event::wparam wparam_;

	awl::backends::windows::event::lparam lparam_;
};

}
}
}
}
}

#endif

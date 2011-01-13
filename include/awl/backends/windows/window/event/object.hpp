#ifndef AWL_BACKENDS_WINDOWS_WINDOW_EVENT_OBJECT_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_WINDOW_EVENT_OBJECT_HPP_INCLUDED

#include <awl/backends/windows/window/event/object_fwd.hpp>
#include <awl/backends/windows/windows.hpp>
#include <awl/symbol.hpp>

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
		WPARAM,
		LPARAM
	);

	AWL_SYMBOL
	WPARAM
	wparam() const;

	AWL_SYMBOL
	LPARAM
	lparam() const;
private:
	WPARAM wparam_;

	LPARAM lparam_;
};

}
}
}
}
}

#endif

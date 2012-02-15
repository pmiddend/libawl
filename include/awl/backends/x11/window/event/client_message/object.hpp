#ifndef AWL_BACKENDS_X11_WINDOW_EVENT_CLIENT_MESSAGE_OBJECT_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_EVENT_CLIENT_MESSAGE_OBJECT_HPP_INCLUDED

#include <awl/symbol.hpp>
#include <awl/backends/x11/window/event/client_message/object_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <X11/Xlib.h>
#include <fcppt/config/external_end.hpp>


namespace awl
{
namespace backends
{
namespace x11
{
namespace window
{
namespace event
{
namespace client_message
{

class object
{
public:
	AWL_SYMBOL
	explicit
	object(
		XClientMessageEvent const &
	);

	AWL_SYMBOL
	XClientMessageEvent const &
	get() const;
private:
	XClientMessageEvent event_;
};

}
}
}
}
}
}

#endif

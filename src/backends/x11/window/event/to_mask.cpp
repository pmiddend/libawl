#include <awl/backends/x11/window/event/to_mask.hpp>
#include <awl/exception.hpp>
#include <fcppt/text.hpp>
#include <fcppt/config/external_begin.hpp>
#include <X11/Xlib.h>
#include <fcppt/config/external_end.hpp>

long
awl::backends::x11::window::event::to_mask(
	int const _event_type
)
{
	switch(
		_event_type
	)
	{
	case KeyPress:
		return KeyPressMask;
	case KeyRelease:
		return KeyReleaseMask;
	case ButtonPress:
		return ButtonPressMask;
	case ButtonRelease:
		return ButtonReleaseMask;
	case MotionNotify:
		return PointerMotionMask;
	case EnterNotify:
		return EnterWindowMask;
	case LeaveNotify:
		return LeaveWindowMask;
	case FocusIn:
		return FocusChangeMask;
	case FocusOut:
		return FocusChangeMask;
	case MapNotify:
		return StructureNotifyMask;
	case UnmapNotify:
		return StructureNotifyMask;
	case ResizeRequest:
		return ResizeRedirectMask;
	case ConfigureRequest:
		return SubstructureRedirectMask;
	case ConfigureNotify:
		return StructureNotifyMask;
	case GenericEvent:
		throw awl::exception(
			FCPPT_TEXT("Don't register generic events for a window!")
		);
	default:
		throw awl::exception(
			FCPPT_TEXT("Unknown x11 event type in to_event_mask!")
		);
	}
}

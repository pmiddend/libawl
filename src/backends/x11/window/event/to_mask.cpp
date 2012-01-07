#include <awl/backends/x11/window/event/mask.hpp>
#include <awl/backends/x11/window/event/optional_mask.hpp>
#include <awl/backends/x11/window/event/type.hpp>
#include <awl/backends/x11/window/event/to_mask.hpp>
#include <fcppt/text.hpp>
#include <fcppt/assert/unreachable_message.hpp>
#include <fcppt/config/external_begin.hpp>
#include <X11/Xlib.h>
#include <fcppt/config/external_end.hpp>


awl::backends::x11::window::event::optional_mask const
awl::backends::x11::window::event::to_mask(
	x11::window::event::type const _event_type
)
{
#define AWL_BACKENDS_X11_WINDOW_EVENT_TO_MASK_CASE(\
	type_value,\
	mask_value\
)\
case type_value: \
	return \
		awl::backends::x11::window::event::optional_mask(\
			awl::backends::x11::window::event::mask(\
				mask_value\
			) \
		);
	switch(
		_event_type.get()
	)
	{
		AWL_BACKENDS_X11_WINDOW_EVENT_TO_MASK_CASE(
			KeyPress,
			KeyPressMask
		);
		AWL_BACKENDS_X11_WINDOW_EVENT_TO_MASK_CASE(
			KeyRelease,
			KeyReleaseMask
		);
		AWL_BACKENDS_X11_WINDOW_EVENT_TO_MASK_CASE(
			ButtonPress,
			ButtonPressMask
		);
		AWL_BACKENDS_X11_WINDOW_EVENT_TO_MASK_CASE(
			ButtonRelease,
			ButtonReleaseMask
		);
		AWL_BACKENDS_X11_WINDOW_EVENT_TO_MASK_CASE(
			MotionNotify,
			PointerMotionMask
		);
		AWL_BACKENDS_X11_WINDOW_EVENT_TO_MASK_CASE(
			EnterNotify,
			EnterWindowMask
		);
		AWL_BACKENDS_X11_WINDOW_EVENT_TO_MASK_CASE(
			LeaveNotify,
			LeaveWindowMask
		);
		AWL_BACKENDS_X11_WINDOW_EVENT_TO_MASK_CASE(
			FocusIn,
			FocusChangeMask
		);
		AWL_BACKENDS_X11_WINDOW_EVENT_TO_MASK_CASE(
			FocusOut,
			FocusChangeMask
		);
		AWL_BACKENDS_X11_WINDOW_EVENT_TO_MASK_CASE(
			MapNotify,
			StructureNotifyMask
		);
		AWL_BACKENDS_X11_WINDOW_EVENT_TO_MASK_CASE(
			UnmapNotify,
			StructureNotifyMask
		);
		AWL_BACKENDS_X11_WINDOW_EVENT_TO_MASK_CASE(
			ResizeRequest,
			ResizeRedirectMask
		);
		AWL_BACKENDS_X11_WINDOW_EVENT_TO_MASK_CASE(
			ConfigureRequest,
			SubstructureRedirectMask
		);
		AWL_BACKENDS_X11_WINDOW_EVENT_TO_MASK_CASE(
			ConfigureNotify,
			StructureNotifyMask
		);
		AWL_BACKENDS_X11_WINDOW_EVENT_TO_MASK_CASE(
			DestroyNotify,
			StructureNotifyMask
		);
	case GenericEvent:
		FCPPT_ASSERT_UNREACHABLE_MESSAGE(
			FCPPT_TEXT("Don't register generic events for a window!")
		);
	}

	return
		awl::backends::x11::window::event::optional_mask();
}

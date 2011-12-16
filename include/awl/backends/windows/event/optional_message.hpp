#ifndef AWL_BACKENDS_WINDOWS_EVENT_OPTIONAL_MESSAGE_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_EVENT_OPTIONAL_MESSAGE_HPP_INCLUDED

#include <awl/backends/windows/event/message_fwd.hpp>
#include <fcppt/optional_fwd.hpp>

namespace awl
{
namespace backends
{
namespace windows
{
namespace event
{

typedef fcppt::optional<
	awl::backends::windows::event::message
> optional_message;

}
}
}
}

#endif

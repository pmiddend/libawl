#ifndef AWL_WINDOW_EVENT_PROCESSOR_UNIQUE_PTR_HPP_INCLUDED
#define AWL_WINDOW_EVENT_PROCESSOR_UNIQUE_PTR_HPP_INCLUDED

#include <awl/window/event/processor_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <memory>
#include <fcppt/config/external_end.hpp>


namespace awl
{
namespace window
{
namespace event
{

typedef std::unique_ptr<
	awl::window::event::processor
> processor_unique_ptr;

}
}
}

#endif

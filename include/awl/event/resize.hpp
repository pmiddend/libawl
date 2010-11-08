#ifndef AWL_EVENT_RESIZE_HPP_INCLUDED
#define AWL_EVENT_RESIZE_HPP_INCLUDED

#include <awl/event/resize_fwd.hpp>
#include <awl/window/dim.hpp>
#include <awl/window/instance_ptr.hpp>
#include <awl/symbol.hpp>
#include <fcppt/math/dim/basic_impl.hpp>

namespace awl
{
namespace event
{

class resize
{
public:
	AWL_SYMBOL
	resize(
		window::instance_ptr,
		window::dim const &
	);

	AWL_SYMBOL
	window::instance_ptr const
	instance() const;

	AWL_SYMBOL
	window::dim const &
	dim() const;
private:
	window::instance_ptr instance_;

	window::dim dim_;
};

}
}

#endif

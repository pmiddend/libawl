#ifndef AWL_WINDOW_EVENT_RESIZE_HPP_INCLUDED
#define AWL_WINDOW_EVENT_RESIZE_HPP_INCLUDED

#include <awl/window/event/resize_fwd.hpp>
#include <awl/window/dim.hpp>
#include <awl/window/instance_fwd.hpp>
#include <awl/symbol.hpp>
#include <fcppt/math/dim/basic_impl.hpp>
#include <fcppt/nonassignable.hpp>

namespace awl
{
namespace window
{
namespace event
{

class resize
{
	FCPPT_NONASSIGNABLE(
		resize
	);
public:
	AWL_SYMBOL
	resize(
		window::instance &,
		window::dim const &
	);

	AWL_SYMBOL
	window::instance &
	instance() const;

	AWL_SYMBOL
	window::dim const &
	dim() const;
private:
	window::instance &instance_;

	window::dim dim_;
};

}
}
}

#endif

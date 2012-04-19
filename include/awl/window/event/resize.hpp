#ifndef AWL_WINDOW_EVENT_RESIZE_HPP_INCLUDED
#define AWL_WINDOW_EVENT_RESIZE_HPP_INCLUDED

#include <awl/window/event/resize_fwd.hpp>
#include <awl/window/dim.hpp>
#include <awl/window/object_fwd.hpp>
#include <awl/symbol.hpp>
#include <fcppt/math/dim/object_impl.hpp>
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
		window::object &,
		window::dim const &
	);

	AWL_SYMBOL
	window::object &
	object() const;

	AWL_SYMBOL
	window::dim const &
	dim() const;
private:
	window::object &object_;

	window::dim dim_;
};

}
}
}

#endif

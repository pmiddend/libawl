#ifndef AWL_WINDOW_EVENT_RESIZE_HPP_INCLUDED
#define AWL_WINDOW_EVENT_RESIZE_HPP_INCLUDED

#include <awl/symbol.hpp>
#include <awl/window/dim.hpp>
#include <awl/window/event/resize_fwd.hpp>
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
	explicit
	resize(
		awl::window::dim const &
	);

	AWL_SYMBOL
	awl::window::dim const &
	dim() const;
private:
	awl::window::dim dim_;
};

}
}
}

#endif

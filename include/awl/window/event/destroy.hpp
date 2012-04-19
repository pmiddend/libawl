#ifndef AWL_WINDOW_EVENT_DESTROY_HPP_INCLUDED
#define AWL_WINDOW_EVENT_DESTROY_HPP_INCLUDED

#include <awl/window/event/destroy_fwd.hpp>
#include <awl/window/object_fwd.hpp>
#include <awl/symbol.hpp>
#include <fcppt/nonassignable.hpp>

namespace awl
{
namespace window
{
namespace event
{

class destroy
{
	FCPPT_NONASSIGNABLE(
		destroy
	);
public:
	AWL_SYMBOL
	explicit destroy(
		window::object &
	);

	AWL_SYMBOL
	window::object &
	object() const;
private:
	window::object &object_;
};

}
}
}

#endif

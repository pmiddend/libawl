#ifndef AWL_WINDOW_EVENT_CLOSE_HPP_INCLUDED
#define AWL_WINDOW_EVENT_CLOSE_HPP_INCLUDED

#include <awl/window/event/close_fwd.hpp>
#include <awl/window/object_fwd.hpp>
#include <awl/symbol.hpp>
#include <fcppt/nonassignable.hpp>

namespace awl
{
namespace window
{
namespace event
{

class close
{
	FCPPT_NONASSIGNABLE(
		close
	);
public:
	AWL_SYMBOL
	explicit close(
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

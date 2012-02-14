#ifndef AWL_WINDOW_EVENT_CLOSE_HPP_INCLUDED
#define AWL_WINDOW_EVENT_CLOSE_HPP_INCLUDED

#include <awl/window/event/close_fwd.hpp>
#include <awl/window/instance_fwd.hpp>
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
		window::instance &
	);

	AWL_SYMBOL
	window::instance &
	instance() const;
private:
	window::instance &instance_;
};

}
}
}

#endif

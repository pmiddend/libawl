#ifndef AWL_WINDOW_EVENT_DESTROY_HPP_INCLUDED
#define AWL_WINDOW_EVENT_DESTROY_HPP_INCLUDED

#include <awl/window/event/destroy_fwd.hpp>
#include <awl/window/instance_fwd.hpp>
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

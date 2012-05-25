#include <awl/window/dim.hpp>
#include <awl/window/event/resize.hpp>


awl::window::event::resize::resize(
	awl::window::dim const &_dim
)
:
	dim_(
		_dim
	)
{
}

awl::window::dim const &
awl::window::event::resize::dim() const
{
	return dim_;
}

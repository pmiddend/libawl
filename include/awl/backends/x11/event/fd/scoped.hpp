#ifndef AWL_BACKENDS_X11_EVENT_FD_SCOPED_HPP_INCLUDED
#define AWL_BACKENDS_X11_EVENT_FD_SCOPED_HPP_INCLUDED

#include <awl/symbol.hpp>
#include <awl/backends/x11/event/fd/object.hpp>
#include <awl/backends/x11/event/fd/set_fwd.hpp>
#include <awl/backends/x11/event/fd/scoped_fwd.hpp>
#include <fcppt/noncopyable.hpp>


namespace awl
{
namespace backends
{
namespace x11
{
namespace event
{
namespace fd
{

class scoped
{
	FCPPT_NONCOPYABLE(
		scoped
	);
public:
	AWL_SYMBOL
	scoped(
		awl::backends::x11::event::fd::set &,
		awl::backends::x11::event::fd::object
	);

	AWL_SYMBOL
	~scoped();
private:
	awl::backends::x11::event::fd::set &set_;

	awl::backends::x11::event::fd::object const fd_;
};

}
}
}
}
}

#endif

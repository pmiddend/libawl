#include <awl/backends/x11/event/fd/object.hpp>
#include <awl/backends/x11/event/fd/scoped.hpp>
#include <awl/backends/x11/event/fd/set.hpp>


awl::backends::x11::event::fd::scoped::scoped(
	awl::backends::x11::event::fd::set &_set,
	awl::backends::x11::event::fd::object const _fd
)
:
	set_(
		_set
	),
	fd_(
		_fd
	)
{
	set_.add(
		fd_
	);
}

awl::backends::x11::event::fd::scoped::~scoped()
{
	set_.remove(
		fd_
	);
}

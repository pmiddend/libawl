#include <awl/backends/x11/signal/object.hpp>
#include <awl/backends/x11/signal/connection.hpp>
#include <fcppt/make_unique_ptr.hpp>

awl::backends::x11::signal::object::object()
:
	signal_()
{
}

awl::backends::x11::signal::object::~object()
{
}

awl::backends::x11::signal::unique_connection
awl::backends::x11::signal::object::connect(
	x11::event_callback const &_callback,
	signal::unregister_callback const &_unregister
)
{
	return
		// FIXME! This must be fixed in fcppt!
		unique_connection(
			new connection(
//		fcppt::make_unique_ptr<
//			signal::connection	
//		>(
			signal_.connect(
				_callback
			),
			_unregister
//		);
		));
}

void
awl::backends::x11::signal::object::operator()(
	x11::event const &_event
) const
{
	signal_(
		_event
	);
}

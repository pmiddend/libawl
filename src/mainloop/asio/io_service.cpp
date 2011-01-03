#include <awl/mainloop/asio/io_service.hpp>
#include <awl/system/object.hpp>
#include <awl/config.hpp>
#include <fcppt/function/object.hpp>
#include <fcppt/tr1/functional.hpp>
#include <fcppt/make_shared_ptr.hpp>

#if defined(AWL_X11_BACKEND)
#include <awl/backends/x11/system/object.hpp>
#include <awl/backends/x11/asio/dispatcher.hpp>
#include <fcppt/dynamic_pointer_cast.hpp>
#elif defined(AWL_WINDOWS_BACKEND)
#endif

awl::mainloop::asio::io_service::io_service()
{
}

awl::mainloop::asio::io_service::~io_service()
{
}

void
awl::mainloop::asio::io_service::run_one()
{
	get().run_one();
}

void
awl::mainloop::asio::io_service::run()
{
	get().run();
}

void
awl::mainloop::asio::io_service::poll()
{
	get().poll();
}

void
awl::mainloop::asio::io_service::stop()
{
	get().stop();
}

void
awl::mainloop::asio::io_service::reset()
{
	get().reset();
}

void
awl::mainloop::asio::io_service::post(
	nullary_callback const &_callback
)
{
	get().post(
		_callback
	);
}

awl::mainloop::dispatcher_ptr const
awl::mainloop::asio::io_service::create_dispatcher(
	awl::system::object_ptr const _system,
	dispatcher_callback const &_callback
)
{
	return
#if defined(AWL_X11_BACKEND)
		fcppt::make_shared_ptr<
			awl::backends::x11::asio::dispatcher
		>(
			std::tr1::ref(
				get()
			),
			fcppt::dynamic_pointer_cast<
				awl::backends::x11::system::object
			>(
				_system
			)->display(),
			_callback
		);
#elif defined(AWL_WINDOWS_BACKEND)
		mainloop::dispatcher_ptr(); // TODO!
#endif
}

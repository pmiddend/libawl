#include <awl/mainloop/asio/io_service.hpp>
#include <awl/system/object.hpp>
#include <awl/config.hpp>
#include <fcppt/function/object.hpp>
#include <fcppt/tr1/functional.hpp>
#include <fcppt/make_unique_ptr.hpp>

#if defined(AWL_X11_BACKEND)
#include <awl/backends/x11/system/object.hpp>
#include <awl/backends/x11/asio/dispatcher.hpp>
#elif defined(AWL_WINDOWS_BACKEND)
#include <awl/backends/windows/asio/dispatcher.hpp>
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
	this->get().run_one();
}

void
awl::mainloop::asio::io_service::run()
{
	this->get().run();
}

void
awl::mainloop::asio::io_service::poll()
{
	this->get().poll();
}

void
awl::mainloop::asio::io_service::stop()
{
	this->get().stop();
}

void
awl::mainloop::asio::io_service::reset()
{
	this->get().reset();
}

void
awl::mainloop::asio::io_service::post(
	nullary_callback const &_callback
)
{
	this->get().post(
		_callback
	);
}

awl::mainloop::dispatcher_unique_ptr
awl::mainloop::asio::io_service::create_dispatcher(
	awl::system::object &_system,
	dispatcher_callback const &_callback
)
{
	return
		awl::mainloop::dispatcher_unique_ptr(
#if defined(AWL_X11_BACKEND)
			fcppt::make_unique_ptr<
				awl::backends::x11::asio::dispatcher
			>(
				std::tr1::ref(
					this->get()
				),
				std::tr1::ref(
					dynamic_cast<
						awl::backends::x11::system::object &
					>(
						_system
					).display()
				),
				_callback
			)	
#elif defined(AWL_WINDOWS_BACKEND)
			fcppt::make_unique_ptr<
				awl::backends::windows::asio::dispatcher
			>(
				std::tr1::ref(
					this->get()
				),
				_callback
			)
#endif
		);
}

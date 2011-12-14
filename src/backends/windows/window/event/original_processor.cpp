#include <awl/backends/windows/default_wnd_proc.hpp>
#include <awl/backends/windows/windows.hpp>
#include <awl/backends/windows/window/instance.hpp>
#include <awl/backends/windows/window/event/combine_result.hpp>
#include <awl/backends/windows/window/event/object.hpp>
#include <awl/backends/windows/window/event/original_processor.hpp>
#include <awl/backends/windows/window/event/return_type.hpp>
#include <awl/backends/windows/window/event/wnd_proc.hpp>
#include <awl/window/dim.hpp>
#include <awl/window/event/destroy.hpp>
#include <awl/window/event/destroy_callback.hpp>
#include <awl/window/event/resize.hpp>
#include <awl/window/event/resize_callback.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/optional_impl.hpp>
#include <fcppt/container/ptr/insert_unique_ptr_map.hpp>
#include <fcppt/math/dim/basic_impl.hpp>
#include <fcppt/signal/auto_connection.hpp>
#include <fcppt/signal/object_impl.hpp>


awl::backends::windows::window::event::original_processor::original_processor(
	windows::window::instance &_window
)
:
	window_(
		_window
	),
	signals_(),
	destroy_signal_(),
	resize_signal_()
{
	::SetWindowLongPtr(
		window_.hwnd(),
		GWLP_USERDATA,
		reinterpret_cast<
			LONG_PTR
		>(
			this
		)
	);

	::SetWindowLongPtr(
		window_.hwnd(),
		GWLP_WNDPROC,
		reinterpret_cast<
			LONG_PTR
		>(
			windows::window::event::wnd_proc
		)
	);
}

awl::backends::windows::window::event::original_processor::~original_processor()
{
	::SetWindowLongPtr(
		window_.hwnd(),
		GWLP_WNDPROC,
		reinterpret_cast<
			LONG_PTR
		>(
			windows::default_wnd_proc
		)
	);
}

bool
awl::backends::windows::window::event::original_processor::dispatch()
{
	MSG msg;

	bool events_processed = false;

	while(
		::PeekMessage(
			&msg,
			window_.hwnd(),
			0,
			0,
			PM_REMOVE
		)
	)
	{
		::TranslateMessage(
			&msg
		);

		::DispatchMessage(
			&msg
		);

		events_processed = true;
	}

	return events_processed;
}

fcppt::signal::auto_connection
awl::backends::windows::window::event::original_processor::destroy_callback(
	awl::window::event::destroy_callback const &_callback
)
{
	return
		destroy_signal_.connect(
			_callback
		);
}

fcppt::signal::auto_connection
awl::backends::windows::window::event::original_processor::resize_callback(
	awl::window::event::resize_callback const &_callback
)
{
	return
		resize_signal_.connect(
			_callback
		);
}

awl::window::instance &
awl::backends::windows::window::event::original_processor::window() const
{
	return window_;
}

fcppt::signal::auto_connection
awl::backends::windows::window::event::original_processor::register_callback(
	UINT const _msg,
	windows::window::event::callback const &_func
)
{
	signal_map::iterator it(
		signals_.find(
			_msg
		)
	);

	if(
		it == signals_.end()
	)
		it =
			fcppt::container::ptr::insert_unique_ptr_map(
				signals_,
				_msg,
				fcppt::make_unique_ptr<
					signal_type
				>(
					windows::window::event::combine_result,
					windows::window::event::return_type()
				)
			).first;

	return
		it->second->connect(
			_func
		);
}

awl::backends::windows::window::event::return_type const
awl::backends::windows::window::event::original_processor::execute_callback(
	UINT const _msg,
	WPARAM const _wparam,
	LPARAM const _lparam
)
{
	switch(
		_msg
	)
	{
	case WM_DESTROY:
		destroy_signal_(
			awl::window::event::destroy(
				this->window()
			)
		);
		break;
	case WM_SIZE:
		resize_signal_(
			awl::window::event::resize(
				this->window(),
				awl::window::dim(
					static_cast<
						awl::window::dim::value_type
					>(
						LOWORD(
							_lparam
						)
					),
					static_cast<
						awl::window::dim::value_type
					>(
						HIWORD(
							_lparam
						)
					)
				)
			)
		);
		break;
	}

	signal_map::iterator const it(
		signals_.find(
			_msg
		)
	);

	return
		it != signals_.end()
		?
			(*(it->second))(
				windows::window::event::object(
					_wparam,
					_lparam
				)
		)
		:
			windows::window::event::return_type();
}

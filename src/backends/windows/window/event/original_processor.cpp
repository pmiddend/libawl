#include <awl/backends/windows/window/event/original_processor.hpp>
#include <awl/backends/windows/window/event/wnd_proc.hpp>
#include <awl/backends/windows/window/event/combine_result.hpp>
#include <awl/backends/windows/window/instance.hpp>
#include <awl/backends/windows/default_wnd_proc.hpp>
#include <fcppt/container/ptr/insert_unique_ptr_map.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/optional_impl.hpp>

awl::backends::windows::window::event::original_processor::original_processor(
	windows::window::instance_ptr const _window
)
:
	window_(_window),
	signals_()
{
	::SetWindowLongPtr(
		window_->hwnd(),
		GWLP_USERDATA,
		reinterpret_cast<
			LONG_PTR
		>(
			this
		)
	);

	::SetWindowLongPtr(
		window_->hwnd(),
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
		window_->hwnd(),
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
			window_->hwnd(),
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
	signal_map::iterator const it(
		signals_.find(
			_msg
		)
	);

	return
		it != signals_.end()
		?
			(*(it->second))(
				_msg,
				_wparam,
				_lparam
		)
		:
			windows::window::event::return_type();
}
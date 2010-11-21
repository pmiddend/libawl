#include <awl/backends/windows/original_event_processor.hpp>
#include <awl/backends/windows/default_wnd_proc.hpp>
#include <awl/backends/windows/event_wnd_proc.hpp>

awl::backends::windows::original_event_processor::original_event_processor(
	windows;:window_instance_ptr const _window
)
:
	window_(_window),
	signals_()
{
	::SetWindowLongPtr(
		window_->hwnd(),
		GWLP_USERDATA,
		this
	);

	::SetWindowLongPtr(
		window_->hwnd(),
		GWLP_WNDPROC,
		windows::event_wnd_proc()
	);
}

awl::backends::windows::original_event_processor::~original_event_processor()
{
	::SetWindowLongPtr(
		window_->hwnd(),
		GWLP_WNDPROC,
		windows::default_wnd_proc()
	);
}

void
awl::backends::windows::original_event_processor::dispatch()
{
	MSG msg;

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
	}
}
fcppt::signal::auto_connection
awl::backends::windows::original_event_processor::register_callback(
	event_type const _msg,
	callback_type const _func
)
{
	signal_map::iterator it(
		signals_.find(
			_msg
		)
	);

	if(
		it_ == signals.end()
	)
		it_
			=
			fcppt::container::ptr::insert_unique_ptr_map(
				signals_,
				_msg,
				fcppt::make_unique_ptr<
					signal_type
				>(
					windows::combine_result()
				)
			).second;

	return
		it_->second.connect(
			_func
		)
}

awl::backends::windows::callback_return_type
awl::backends::windows::window::execute_callback(
	event_type const _msg,
	WPARAM const _wparam,
	LPARAM const _lparam
)
{
	signal_map::iterator const it(
		signals_.find(
			msg
		)
	);

	return
		it != signals.end()
		?
			(*(it->second))(
				window_,
				_msg,
				_wparam,
				_lparam
		)
		:
			callback_return_type();
}



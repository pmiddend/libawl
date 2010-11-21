#include <awl/backends/windows/original_event_processor.hpp>
#include <awl/backends/windows/default_wnd_proc.hpp>
#include <awl/backends/windows/event_wnd_proc.hpp>
#include <awl/backends/windows/window_instance.hpp>
#include <awl/backends/windows/combine_result.hpp>
#include <fcppt/container/ptr/insert_unique_ptr_map.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/optional_impl.hpp>

awl::backends::windows::original_event_processor::original_event_processor(
	windows::window_instance_ptr const _window
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
			windows::event_wnd_proc
		)
	);
}

awl::backends::windows::original_event_processor::~original_event_processor()
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
	UINT const _msg,
	windows::event_callback const &_func
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
					windows::combine_result
				)
			).first;

	return
		it->second->connect(
			_func
		);
}

awl::backends::windows::event_return_type const
awl::backends::windows::original_event_processor::execute_callback(
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
			windows::event_return_type();
}

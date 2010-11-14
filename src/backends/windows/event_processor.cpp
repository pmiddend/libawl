namespace
{

LRESULT CALLBACK wnd_proc(
	HWND,
	UINT,
	WPARAM,
	LPARAM);

}

fcppt::signal::auto_connection
awl::backends::windows::window::register_callback(
	event_type const msg,
	callback_type const func
)
{
	signal_map::iterator const it(
		signals.find(
			msg
		)
	);

	if(
		it == signals.end()
	)
		fcppt::container::ptr::insert_unique_ptr_map(
			signals,
			msg,
			fcppt::make_unique_ptr<
				signal_type
			>(
				detail::combine_result
			)
		);

	// TODO: can be optimized
	return signals[msg].connect(func);
}

awl::backends::windows::callback_return_type
awl::backends::windows::window::execute_callback(
	event_type const msg,
	WPARAM const wparam,
	LPARAM const lparam
)
{
	signal_map::iterator const it(
		signals.find(msg)
	);

	return it != signals.end()
		? (*(it->second))(
			std::tr1::ref(
				*this
			),
			msg,
			wparam,
			lparam
		)
		: callback_return_type();
}

void
awl::backends::windows::window::dispatch()
{
	MSG msg;
	while(PeekMessage(&msg, handle, 0, 0, PM_REMOVE))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}

namespace
{

LRESULT CALLBACK
wnd_proc(
	HWND const hwnd,
	unsigned const msg,
	WPARAM const wparam,
	LPARAM const lparam
)
{
	if (msg == WM_CREATE)
	{
		CREATESTRUCT* const s = reinterpret_cast<CREATESTRUCT*>(lparam);
		SetWindowLongPtr(hwnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(s->lpCreateParams));
	}

	awl::backends::windows::window *const wnd = reinterpret_cast<awl::backends::windows::window*>(GetWindowLongPtr(hwnd, GWLP_USERDATA));
	if (wnd)
	{
		awl::backends::windows::callback_return_type const ret =
			wnd->execute_callback(msg, wparam, lparam);
		if (ret)
			return *ret;
	}

	switch(msg) {
	case WM_CLOSE:
		return 0;
	case WM_CREATE:
		break;
	case WM_ACTIVATE:
	{
		awl::backends::windows::window* const wnd
			= reinterpret_cast<awl::backends::windows::window*>(
				GetWindowLongPtr(hwnd, GWLP_USERDATA));

		bool const active = wparam != 0 ? true : false;
		if(!active)
			ShowWindow(wnd->hwnd(),SW_MINIMIZE);
		return 0;
	}
	default:
		return DefWindowProc(hwnd,msg,wparam,lparam);
	}
	return TRUE;
}

}

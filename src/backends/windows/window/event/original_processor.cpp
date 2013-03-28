#include <awl/backends/windows/default_wnd_proc.hpp>
#include <awl/backends/windows/windows.hpp>
#include <awl/backends/windows/cursor/const_optional_object_ref.hpp>
#include <awl/backends/windows/cursor/object.hpp>
#include <awl/backends/windows/event/lparam.hpp>
#include <awl/backends/windows/event/message.hpp>
#include <awl/backends/windows/event/optional_message.hpp>
#include <awl/backends/windows/event/peek.hpp>
#include <awl/backends/windows/event/type.hpp>
#include <awl/backends/windows/event/wparam.hpp>
#include <awl/backends/windows/window/object.hpp>
#include <awl/backends/windows/window/event/combine_result.hpp>
#include <awl/backends/windows/window/event/object.hpp>
#include <awl/backends/windows/window/event/original_processor.hpp>
#include <awl/backends/windows/window/event/return_type.hpp>
#include <awl/backends/windows/window/event/wnd_proc.hpp>
#include <awl/window/dim.hpp>
#include <awl/window/event/close.hpp>
#include <awl/window/event/close_callback.hpp>
#include <awl/window/event/destroy.hpp>
#include <awl/window/event/destroy_callback.hpp>
#include <awl/window/event/focus_in.hpp>
#include <awl/window/event/focus_in_callback.hpp>
#include <awl/window/event/focus_out.hpp>
#include <awl/window/event/focus_out_callback.hpp>
#include <awl/window/event/hide.hpp>
#include <awl/window/event/hide_callback.hpp>
#include <awl/window/event/resize.hpp>
#include <awl/window/event/resize_callback.hpp>
#include <awl/window/event/show.hpp>
#include <awl/window/event/show_callback.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/optional_impl.hpp>
#include <fcppt/strong_typedef_construct_cast.hpp>
#include <fcppt/assign/make_container.hpp>
#include <fcppt/container/ptr/insert_unique_ptr_map.hpp>
#include <fcppt/math/dim/object_impl.hpp>
#include <fcppt/preprocessor/disable_vc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/signal/auto_connection.hpp>
#include <fcppt/signal/connection_manager.hpp>
#include <fcppt/signal/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <functional>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_VC_WARNING(4355)
awl::backends::windows::window::event::original_processor::original_processor(
	awl::backends::windows::window::object &_window
)
:
	window_(
		_window
	),
	signals_(),
	close_signal_(
		[](
			bool const _arg1,
			bool const _arg2
		)
		{
			return
				_arg1 && _arg2;
		}
		,
		true
	),
	destroy_signal_(),
	focus_in_signal_(),
	focus_out_signal_(),
	hide_signal_(),
	resize_signal_(),
	show_signal_(),
	connections_(
		fcppt::assign::make_container<
			fcppt::signal::connection_manager::container
		>(
			this->register_callback(
				fcppt::strong_typedef_construct_cast<
					awl::backends::windows::event::type
				>(
					WM_CLOSE
				),
				std::bind(
					&awl::backends::windows::window::event::original_processor::on_close,
					this,
					std::placeholders::_1
				)
			)
		)(
			this->register_callback(
				fcppt::strong_typedef_construct_cast<
					awl::backends::windows::event::type
				>(
					WM_DESTROY
				),
				std::bind(
					&awl::backends::windows::window::event::original_processor::on_destroy,
					this,
					std::placeholders::_1
				)
			)
		)(
			this->register_callback(
				fcppt::strong_typedef_construct_cast<
					awl::backends::windows::event::type
				>(
					WM_SETFOCUS
				),
				std::bind(
					&awl::backends::windows::window::event::original_processor::on_focus_in,
					this,
					std::placeholders::_1
				)
			)
		)(
			this->register_callback(
				fcppt::strong_typedef_construct_cast<
					awl::backends::windows::event::type
				>(
					WM_KILLFOCUS
				),
				std::bind(
					&awl::backends::windows::window::event::original_processor::on_focus_out,
					this,
					std::placeholders::_1
				)
			)
		)(
			this->register_callback(
				fcppt::strong_typedef_construct_cast<
					awl::backends::windows::event::type
				>(
					WM_SIZE
				),
				std::bind(
					&awl::backends::windows::window::event::original_processor::on_resize,
					this,
					std::placeholders::_1
				)
			)
		)(
			this->register_callback(
				fcppt::strong_typedef_construct_cast<
					awl::backends::windows::event::type
				>(
					WM_SHOWWINDOW
				),
				std::bind(
					&awl::backends::windows::window::event::original_processor::on_show,
					this,
					std::placeholders::_1
				)
			)
		)(
			this->register_callback(
				fcppt::strong_typedef_construct_cast<
					awl::backends::windows::event::type
				>(
					WM_SETCURSOR
				),
				std::bind(
					&awl::backends::windows::window::event::original_processor::on_setcursor,
					this,
					std::placeholders::_1
				)
			)
		)
		.move_container()
	)
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
			awl::backends::windows::window::event::wnd_proc
		)
	);
}
FCPPT_PP_POP_WARNING

awl::backends::windows::window::event::original_processor::~original_processor()
{
	::SetWindowLongPtr(
		window_.hwnd(),
		GWLP_WNDPROC,
		reinterpret_cast<
			LONG_PTR
		>(
			awl::backends::windows::default_wnd_proc
		)
	);
}

bool
awl::backends::windows::window::event::original_processor::poll()
{
	bool events_processed = false;

	while(
		awl::backends::windows::event::optional_message const message =
			awl::backends::windows::event::peek(
				window_.hwnd()
			)
	)
	{
		this->do_process(
			*message
		);

		events_processed = true;
	}

	return events_processed;
}

fcppt::signal::auto_connection
awl::backends::windows::window::event::original_processor::close_callback(
	awl::window::event::close_callback const &_callback
)
{
	return
		close_signal_.connect(
			_callback
		);
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
awl::backends::windows::window::event::original_processor::focus_in_callback(
	awl::window::event::focus_in_callback const &_callback
)
{
	return
		focus_in_signal_.connect(
			_callback
		);
}

fcppt::signal::auto_connection
awl::backends::windows::window::event::original_processor::focus_out_callback(
	awl::window::event::focus_out_callback const &_callback
)
{
	return
		focus_out_signal_.connect(
			_callback
		);
}

fcppt::signal::auto_connection
awl::backends::windows::window::event::original_processor::hide_callback(
	awl::window::event::hide_callback const &_callback
)
{
	return
		hide_signal_.connect(
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

fcppt::signal::auto_connection
awl::backends::windows::window::event::original_processor::show_callback(
	awl::window::event::show_callback const &_callback
)
{
	return
		show_signal_.connect(
			_callback
		);
}

awl::window::object &
awl::backends::windows::window::event::original_processor::window() const
{
	return window_;
}

awl::backends::windows::window::object &
awl::backends::windows::window::event::original_processor::windows_window() const
{
	return window_;
}

fcppt::signal::auto_connection
awl::backends::windows::window::event::original_processor::register_callback(
	awl::backends::windows::event::type const _type,
	awl::backends::windows::window::event::callback const &_func
)
{
	awl::backends::windows::window::event::original_processor::signal_map::iterator it(
		signals_.find(
			_type
		)
	);

	if(
		it == signals_.end()
	)
		it =
			fcppt::container::ptr::insert_unique_ptr_map(
				signals_,
				_type,
				fcppt::make_unique_ptr<
					signal_type
				>(
					awl::backends::windows::window::event::combine_result,
					awl::backends::windows::window::event::return_type()
				)
			).first;

	return
		it->second->connect(
			_func
		);
}

void
awl::backends::windows::window::event::original_processor::process(
	awl::backends::windows::event::message const &_message
)
{
	this->do_process(
		_message
	);
}

awl::backends::windows::event::type const
awl::backends::windows::window::event::original_processor::allocate_user_message()
{
	// FIXME
	return
		fcppt::strong_typedef_construct_cast<
			awl::backends::windows::event::type
		>(
			WM_USER
		);
}

void
awl::backends::windows::window::event::original_processor::free_user_message(
	awl::backends::windows::event::type const _message
)
{
	// FIXME
}

awl::backends::windows::window::event::return_type const
awl::backends::windows::window::event::original_processor::execute_callback(
	awl::backends::windows::event::type const _type,
	awl::backends::windows::event::wparam const _wparam,
	awl::backends::windows::event::lparam const _lparam
)
{
	signal_map::iterator const it(
		signals_.find(
			_type
		)
	);

	return
		it != signals_.end()
		?
			(*(it->second))(
				awl::backends::windows::window::event::object(
					_wparam,
					_lparam
				)
		)
		:
			awl::backends::windows::window::event::return_type();
}

void
awl::backends::windows::window::event::original_processor::do_process(
	awl::backends::windows::event::message const &_message
)
{
	::TranslateMessage(
		&_message.get()
	);

	::DispatchMessage(
		&_message.get()
	);
}

awl::backends::windows::window::event::return_type const
awl::backends::windows::window::event::original_processor::on_close(
	awl::backends::windows::window::event::object const &
)
{
	return
		close_signal_(
			awl::window::event::close()
		)
		?
			awl::backends::windows::window::event::return_type()
		:
			awl::backends::windows::window::event::return_type(
				0
			)
		;
}

awl::backends::windows::window::event::return_type const
awl::backends::windows::window::event::original_processor::on_destroy(
	awl::backends::windows::window::event::object const &
)
{
	destroy_signal_(
		awl::window::event::destroy()
	);

	return
		awl::backends::windows::window::event::return_type();
}

awl::backends::windows::window::event::return_type const
awl::backends::windows::window::event::original_processor::on_focus_in(
	awl::backends::windows::window::event::object const &
)
{
	focus_in_signal_(
		awl::window::event::focus_in()
	);

	return
		awl::backends::windows::window::event::return_type();
}

awl::backends::windows::window::event::return_type const
awl::backends::windows::window::event::original_processor::on_focus_out(
	awl::backends::windows::window::event::object const &
)
{
	focus_out_signal_(
		awl::window::event::focus_out()
	);

	return
		awl::backends::windows::window::event::return_type();
}

awl::backends::windows::window::event::return_type const
awl::backends::windows::window::event::original_processor::on_resize(
	awl::backends::windows::window::event::object const &_event
)
{
	resize_signal_(
		awl::window::event::resize(
			awl::window::dim(
				static_cast<
					awl::window::dim::value_type
				>(
					LOWORD(
						_event.lparam().get()
					)
				),
				static_cast<
					awl::window::dim::value_type
				>(
					HIWORD(
						_event.lparam().get()
					)
				)
			)
		)
	);

	return
		awl::backends::windows::window::event::return_type();
}

awl::backends::windows::window::event::return_type const
awl::backends::windows::window::event::original_processor::on_show(
	awl::backends::windows::window::event::object const &_event
)
{
	switch(
		_event.wparam().get()
	)
	{
	case TRUE:
		show_signal_(
			awl::window::event::show()
		);
		break;
	case FALSE:
		hide_signal_(
			awl::window::event::hide()
		);
		break;
	}

	return
		awl::backends::windows::window::event::return_type();
}

awl::backends::windows::window::event::return_type const
awl::backends::windows::window::event::original_processor::on_setcursor(
	awl::backends::windows::window::event::object const &_event
)
{
	if(
		window_.cursor()
		&&
		LOWORD(
			_event.lparam().get()
		)
		==
		HTCLIENT
	)
	{
		::SetCursor(
			window_.cursor()->get()
		);

		return
			awl::backends::windows::window::event::return_type(
				TRUE
			);
	}

	return
		awl::backends::windows::window::event::return_type();
}

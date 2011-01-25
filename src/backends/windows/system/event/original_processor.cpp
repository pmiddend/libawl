#include <awl/backends/windows/system/event/original_processor.hpp>
#include <awl/backends/windows/system/event/object.hpp>
#include <awl/backends/windows/system/event/original_handle.hpp>
#include <awl/backends/windows/windows.hpp>
#include <awl/exception.hpp>
#include <fcppt/algorithm/remove.hpp>
#include <fcppt/container/ptr/insert_unique_ptr_map.hpp>
#include <fcppt/container/raw_vector_impl.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/make_shared_ptr.hpp>
#include <fcppt/text.hpp>

awl::backends::windows::system::event::original_processor::original_processor(
	windows::system::object_ptr
)
:
	signals_(),
	handle_signal_(),
	handles_()
{
}

awl::backends::windows::system::event::original_processor::~original_processor()
{
}

bool
awl::backends::windows::system::event::original_processor::dispatch()
{
	MSG msg;

	bool events_processed = false;

	while(
		::PeekMessage(
			&msg,
			reinterpret_cast<
				HWND
			>(
				-1
			),
			0,
			0,
			PM_REMOVE
		)
	)
	{
		signals_[
			msg.message
		](
			windows::system::event::object(
				msg.wParam,
				msg.lParam
			)
		);

		events_processed = true;
	}

	if(
		!handles_.empty()
	)
	{
		DWORD const result(
			::WaitForMultipleObjects(
				handles_.size(),
				handles_.data(),
				FALSE,
				0u
			)
		);

		if(
			result >= WAIT_OBJECT_0
			&& result < WAIT_OBJECT_0 + handles_.size()
		)
		{
			handle_signal_();

			events_processed = true;
		}
		else if(
			result == WAIT_FAILED
		)
			throw awl::exception(
				FCPPT_TEXT("WaitForMultipleObjects() failed!")
			);
	}

	return events_processed;
}

fcppt::signal::auto_connection
awl::backends::windows::system::event::original_processor::register_callback(
	UINT const _msg,
	windows::system::event::callback const &_func
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
				>()
			).first;

	return
		it->second->connect(
			_func
		);
}

fcppt::signal::auto_connection
awl::backends::windows::system::event::original_processor::register_handle_callback(
	windows::system::event::handle_callback const &_func
)
{
	return
		handle_signal_.connect(
			_func
		);
}

awl::backends::windows::system::event::handle_ptr const
awl::backends::windows::system::event::original_processor::create_event_handle()
{
	awl::backends::windows::system::event::handle_ptr const ret(
		fcppt::make_shared_ptr<
			awl::backends::windows::system::event::original_handle
		>(
			std::tr1::bind(
				&system::event::original_processor::unregister_event_handle,
				this,
				std::tr1::placeholders::_1
			)
		)
	);

	handles_.push_back(
		ret->get()
	);

	return ret;
}


void
awl::backends::windows::system::event::original_processor::unregister_event_handle(
	HANDLE const _handle
)
{
	fcppt::algorithm::remove(
		handles_,
		_handle
	);
}

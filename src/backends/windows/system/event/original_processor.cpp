#include <awl/exception.hpp>
#include <awl/backends/windows/event/lparam.hpp>
#include <awl/backends/windows/event/message.hpp>
#include <awl/backends/windows/event/object.hpp>
#include <awl/backends/windows/event/optional_message.hpp>
#include <awl/backends/windows/event/peek.hpp>
#include <awl/backends/windows/event/type.hpp>
#include <awl/backends/windows/event/wparam.hpp>
#include <awl/backends/windows/windows.hpp>
#include <awl/backends/windows/system/event/object.hpp>
#include <awl/backends/windows/system/event/original_handle.hpp>
#include <awl/backends/windows/system/event/original_processor.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/optional_impl.hpp>
#include <fcppt/text.hpp>
#include <fcppt/algorithm/remove.hpp>
#include <fcppt/container/raw_vector_impl.hpp>
#include <fcppt/container/ptr/insert_unique_ptr_map.hpp>
#include <fcppt/tr1/functional.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/static_assert.hpp>
#include <fcppt/config/external_end.hpp>


awl::backends::windows::system::event::original_processor::original_processor(
	windows::system::object &
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
awl::backends::windows::system::event::original_processor::poll()
{
	bool events_processed = false;

	while(
		windows::event::optional_message const message =
			windows::event::peek(
				reinterpret_cast<
					HWND
				>(
					-1
				)
			)
	)
	{
		this->do_process(
			awl::backends::windows::event::type(
				message->get().message
			),
			awl::backends::windows::system::event::object(
				awl::backends::windows::event::wparam(
					message->get().wParam
				),
				awl::backends::windows::event::lparam(
					message->get().lParam
				)
			)
		);

		events_processed = true;
	}

	events_processed =
		this->poll_handles()
		|| events_processed;

	return events_processed;
}

fcppt::signal::auto_connection
awl::backends::windows::system::event::original_processor::register_callback(
	windows::event::type const _msg,
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

awl::backends::windows::system::event::handle_unique_ptr
awl::backends::windows::system::event::original_processor::create_event_handle()
{
	awl::backends::windows::system::event::handle_unique_ptr ret(
		fcppt::make_unique_ptr<
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

	return
		awl::backends::windows::system::event::handle_unique_ptr(
			move(
				ret
			)
		);
}

void
awl::backends::windows::system::event::original_processor::process(
	awl::backends::windows::event::object const &_event
)
{
	this->do_process(
		_event.type(),
		awl::backends::windows::system::event::object(
			_event.wparam(),
			_event.lparam()
		)
	);
}

bool
awl::backends::windows::system::event::original_processor::poll_handles()
{
	return
		handles_.empty()
		?
			false
		:
			this->generic_multiple_wait(
				::WaitForMultipleObjects,
				0u
			)
		;
}

void
awl::backends::windows::system::event::original_processor::next()
{
	this->generic_multiple_wait(
		std::tr1::bind(
			::MsgWaitForMultipleObjects,
			std::tr1::placeholders::_1,
			std::tr1::placeholders::_2,
			std::tr1::placeholders::_3,
			std::tr1::placeholders::_4,
			QS_ALLPOSTMESSAGE
		),
		INFINITE
	);
}

void
awl::backends::windows::system::event::original_processor::do_process(
	awl::backends::windows::event::type const _type,
	awl::backends::windows::system::event::object const &_event
)
{
	signals_[
		_type
	](
		_event
	);
}

template<
	typename Function
>
bool
awl::backends::windows::system::event::original_processor::generic_multiple_wait(
	Function const &_function,
	DWORD const _timeout
)
{
	DWORD const result(
		_function(
			static_cast<
				DWORD
			>(
				handles_.size()
			),
			handles_.data(),
			FALSE,
			_timeout
		)
	);

	BOOST_STATIC_ASSERT(
		WAIT_OBJECT_0 == 0
	);

	if(
		result < WAIT_OBJECT_0 + handles_.size()
	)
	{
		handle_signal_();

		return true;
	}
	else if(
		result == WAIT_FAILED
	)
		throw awl::exception(
			FCPPT_TEXT("WaitForMultipleObjects() failed!")
		);

	return false;
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

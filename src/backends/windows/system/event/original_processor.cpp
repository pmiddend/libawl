#include <awl/backends/windows/system/event/original_processor.hpp>
#include <awl/backends/windows/system/event/object.hpp>
#include <awl/backends/windows/windows.hpp>
#include <fcppt/container/ptr/insert_unique_ptr_map.hpp>
#include <fcppt/make_unique_ptr.hpp>

awl::backends::windows::system::event::original_processor::original_processor(
	windows::system::object_ptr
)
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
			0,
			0,
			0,
			PM_NOREMOVE
		)
	)
	{
		if(
			msg.hwnd != 0
		)
			return events_processed;

		::PeekMessage(
			&msg,
			0,
			0,
			0,
			PM_REMOVE
		);

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

	return events_processed;
}

AWL_SYMBOL
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

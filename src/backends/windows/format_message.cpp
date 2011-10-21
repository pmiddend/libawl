#include <awl/exception.hpp>
#include <awl/backends/windows/format_message.hpp>
#include <awl/backends/windows/windows.hpp>
#include <fcppt/char_type.hpp>
#include <fcppt/text.hpp>
#include <fcppt/container/array.hpp>


fcppt::string const
awl::backends::windows::format_message(
	DWORD const _error
)
{
	fcppt::container::array<
		fcppt::char_type,
		1024
	> errmsg;

	if(
		::FormatMessage(
			FORMAT_MESSAGE_FROM_SYSTEM,
			0, // ignored
			_error, // message id
			0, // language id
			errmsg.data(),
			errmsg.size()-1,
			0
		) == 0
	)
		throw awl::exception(
			FCPPT_TEXT("FormatMessage() failed!")
		);

	return
		fcppt::string(
			errmsg.data()
		);
}

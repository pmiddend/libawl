#include <awl/exception.hpp>
#include <awl/backends/windows/format_message.hpp>
#include <awl/backends/windows/scoped_local_memory.hpp>
#include <awl/backends/windows/windows.hpp>
#include <fcppt/string.hpp>
#include <fcppt/text.hpp>


fcppt::string const
awl::backends::windows::format_message(
	DWORD const _error
)
{
	LPTSTR out;

	if(
		::FormatMessage(
			FORMAT_MESSAGE_ALLOCATE_BUFFER
			| FORMAT_MESSAGE_FROM_SYSTEM
			| FORMAT_MESSAGE_IGNORE_INSERTS,
			0, // source
			_error, // message id
			0, // language id
			// needs to be done for allocated buffers
			reinterpret_cast<
				LPTSTR
			>(
				&out
			),
			0u, // minimum size
			0 // va arguments
		) == 0
	)
		throw awl::exception(
			FCPPT_TEXT("FormatMessage() failed!")
		);
	
	windows::scoped_local_memory const guard(
		out
	);

	return
		// out is null terminated
		fcppt::string(
			out
		);
}

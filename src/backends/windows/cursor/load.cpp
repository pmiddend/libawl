#include <awl/exception.hpp>
#include <awl/backends/windows/windows.hpp>
#include <awl/backends/windows/cursor/load.hpp>
#include <fcppt/null_ptr.hpp>
#include <fcppt/string.hpp>
#include <fcppt/text.hpp>


HCURSOR
awl::backends::windows::cursor::load(
	fcppt::string const _name
)
{
	HCURSOR const result(
		LoadCursor(
			fcppt::null_ptr(),
			_name.c_str()
		)
	);

	if(
		result
		==
		fcppt::null_ptr()
	)
		throw awl::exception(
			FCPPT_TEXT("LoadCursor ")
			+
			_name
			+
			FCPPT_TEXT(" failed")
		);

	return result;
}

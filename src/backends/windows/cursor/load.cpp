#include <awl/exception.hpp>
#include <awl/backends/windows/windows.hpp>
#include <awl/backends/windows/cursor/load.hpp>
#include <fcppt/char_type.hpp>
#include <fcppt/text.hpp>


HCURSOR
awl::backends::windows::cursor::load(
	fcppt::char_type const *const _name
)
{
	HCURSOR const result(
		LoadCursor(
			nullptr,
			_name
		)
	);

	if(
		result
		==
		nullptr
	)
		throw awl::exception(
			FCPPT_TEXT("LoadCursor failed")
		);

	return result;
}

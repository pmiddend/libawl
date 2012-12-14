#include <awl/backends/windows/windows.hpp>
#include <awl/backends/windows/cursor/convert_predefined.hpp>
#include <awl/cursor/predefined.hpp>
#include <fcppt/char_type.hpp>
#include <fcppt/assert/unreachable.hpp>


fcppt::char_type const *
awl::backends::windows::cursor::convert_predefined(
	awl::cursor::predefined const _type
)
{
	switch(
		_type
	)
	{
	case awl::cursor::predefined::arrow:
		return IDC_ARROW;
	case awl::cursor::predefined::cross:
		return IDC_CROSS;
	case awl::cursor::predefined::hand:
		return IDC_HAND;
	case awl::cursor::predefined::icon:
		return IDC_ICON;
	}

	FCPPT_ASSERT_UNREACHABLE;
}

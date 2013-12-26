#include <awl/show_message.hpp>
#include <fcppt/string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/config/platform.hpp>
#if defined(FCPPT_CONFIG_WINDOWS_PLATFORM)
#include <awl/backends/windows/message_box.hpp>
#include <awl/backends/windows/windows.hpp>
#include <awl/backends/windows/window/const_optional_object_ref.hpp>
#else
#include <fcppt/io/clog.hpp>
#endif


void
awl::show_message(
	fcppt::string const &_text
)
{
#if defined(FCPPT_CONFIG_WINDOWS_PLATFORM)
	awl::backends::windows::message_box(
		awl::backends::windows::window::const_optional_object_ref(),
		_text,
		FCPPT_TEXT("Info"),
		MB_OK | MB_ICONINFORMATION
	);
#else
	fcppt::io::clog()
		<< _text
		<< FCPPT_TEXT('\n');
#endif
}

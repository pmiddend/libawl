#include <awl/show_message_narrow.hpp>
#include <fcppt/config/external_begin.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>
#include <fcppt/config/platform.hpp>
#if defined(FCPPT_CONFIG_WINDOWS_PLATFORM)
#include <awl/backends/windows/message_box_narrow.hpp>
#include <awl/backends/windows/windows.hpp>
#include <awl/backends/windows/window/const_optional_object_ref.hpp>
#else
#include <iostream>
#include <ostream>
#endif


void
awl::show_message_narrow(
	std::string const &_text
)
{
#if defined(FCPPT_CONFIG_WINDOWS_PLATFORM)
	awl::backends::windows::message_box_narrow(
		awl::backends::windows::window::const_optional_object_ref(),
		_text,
		"Info",
		MB_OK | MB_ICONINFORMATION
	);
#else
	std::clog
		<< _text
		<< '\n';
#endif
}

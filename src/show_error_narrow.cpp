#include <awl/show_error_narrow.hpp>
#include <fcppt/config/external_begin.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>
#include <fcppt/config/platform.hpp>
#if defined(FCPPT_CONFIG_WINDOWS_PLATFORM)
#include <awl/exception.hpp>
#include <awl/backends/windows/windows.hpp>
#include <fcppt/from_std_string.hpp>
#include <fcppt/text.hpp>
#else
#include <iostream>
#include <ostream>
#endif


void
awl::show_error_narrow(
	std::string const &_text
)
{
#if defined(FCPPT_CONFIG_WINDOWS_PLATFORM)
	if(
		::MessageBoxA(
			nullptr,
			_text.c_str(),
			"Error",
			MB_OK | MB_ICONERROR
		)
		== 0
	)
		throw
			awl::exception(
				FCPPT_TEXT("MessageBox failed: ")
				+
				fcppt::from_std_string(
					_text
				)
			);
#else
	std::cerr
		<< _text
		<< '\n';
#endif
}

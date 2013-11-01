#include <awl/show_error.hpp>
#include <fcppt/string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/config/platform.hpp>
#if defined(FCPPT_CONFIG_WINDOWS_PLATFORM)
#include <awl/exception.hpp>
#include <awl/backends/windows/windows.hpp>
#else
#include <fcppt/io/cerr.hpp>
#endif


void
awl::show_error(
	fcppt::string const &_text
)
{
#if defined(FCPPT_CONFIG_WINDOWS_PLATFORM)
	if(
		::MessageBox(
			nullptr,
			_text.c_str(),
			FCPPT_TEXT("Error"),
			MB_OK | MB_ICONERROR
		)
		== 0
	)
		throw
			awl::exception(
				FCPPT_TEXT("MessageBox failed: ")
				+ _text
			);
#else
	fcppt::io::cerr()
		<< _text
		<< FCPPT_TEXT('\n');
#endif
}

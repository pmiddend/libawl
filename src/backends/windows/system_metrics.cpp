#include <awl/backends/windows/system_metrics.hpp>
#include <awl/backends/windows/windows.hpp>
#include <awl/exception.hpp>
#include <fcppt/text.hpp>

int
awl::backends::windows::system_metrics(
	int const _what
)
{
	int const ret(
		::GetSystemMetrics(
			_what
		)
	);

	if(
		ret == 0
	)
		throw awl::exception(
			FCPPT_TEXT("GetSystemMetrics() failed!")
		);

	return ret;
}

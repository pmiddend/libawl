#include <awl/exception.hpp>
#include <awl/backends/windows/local_free.hpp>
#include <awl/backends/windows/windows.hpp>
#include <fcppt/text.hpp>


void
awl::backends::windows::local_free(
	HLOCAL const _handle
)
{
	if(
		::LocalFree(
			_handle
		)
		!= NULL
	)
		throw awl::exception(
			FCPPT_TEXT("LocalFree() failed!")
		);
}

#include <awl/exception.hpp>
#include <awl/backends/windows/module_handle.hpp>
#include <awl/backends/windows/windows.hpp>
#include <fcppt/null_ptr.hpp>
#include <fcppt/text.hpp>


HMODULE
awl::backends::windows::module_handle()
{
	HMODULE const object(
		::GetModuleHandle(0)
	);

	if(
		object
		==
		fcppt::null_ptr()
	)
		throw awl::exception(
			FCPPT_TEXT("GetModuleHandle() failed!")
		);

	return object;
}

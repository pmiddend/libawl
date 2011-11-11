#include <awl/exception.hpp>
#include <awl/backends/windows/module_handle.hpp>
#include <fcppt/text.hpp>


HINSTANCE
awl::backends::windows::module_handle()
{
	HINSTANCE const instance(
		::GetModuleHandle(0)
	);

	if(!instance)
		throw awl::exception(
			FCPPT_TEXT("GetModuleHandle() failed!")
		);

	return instance;
}

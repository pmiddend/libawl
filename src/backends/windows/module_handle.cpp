#include <awl/exception.hpp>
#include <awl/backends/windows/module_handle.hpp>
#include <fcppt/text.hpp>


HOBJECT
awl::backends::windows::module_handle()
{
	HOBJECT const object(
		::GetModuleHandle(0)
	);

	if(!object)
		throw awl::exception(
			FCPPT_TEXT("GetModuleHandle() failed!")
		);

	return object;
}

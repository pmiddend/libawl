#include <awl/backends/windows/gdi_device.hpp>
#include <awl/exception.hpp>
#include <fcppt/text.hpp>

awl::backends::windows::gdi_device::gdi_device(
	HWND const _hwnd,
	get_tag
)
:
	hwnd_(_hwnd),
	dc_(::GetDC(_hwnd))
{
	if(!dc_)
		throw awl::exception(
			FCPPT_TEXT("GetDC() failed!")
		);
}

awl::backends::windows::gdi_device::~gdi_device()
{
	::ReleaseDC(
		hwnd_,
		dc_
	);
}

HDC
awl::backends::windows::gdi_device::hdc() const
{
	return dc_;
}

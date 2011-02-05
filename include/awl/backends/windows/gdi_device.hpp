#ifndef AWL_BACKENDS_WINDOWS_GDI_DEVICE_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_GDI_DEVICE_HPP_INCLUDED

#include <awl/backends/windows/gdi_device_fwd.hpp>
#include <awl/backends/windows/windows.hpp>
#include <awl/symbol.hpp>
#include <fcppt/noncopyable.hpp>

namespace awl
{
namespace backends
{
namespace windows
{

class gdi_device
{
	FCPPT_NONCOPYABLE(
		gdi_device
	);
public:
	struct get_tag
	{
	};

	AWL_SYMBOL gdi_device(
		HWND,
		get_tag
	);

	AWL_SYMBOL ~gdi_device();

	AWL_SYMBOL HDC
	hdc() const;
private:
	HWND hwnd_;

	HDC dc_;
};

}
}
}

#endif

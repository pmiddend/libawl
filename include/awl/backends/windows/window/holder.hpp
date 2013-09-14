#ifndef AWL_BACKENDS_WINDOWS_WINDOW_HOLDER_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_WINDOW_HOLDER_HPP_INCLUDED

#include <awl/backends/windows/windows.hpp>
#include <awl/backends/windows/wndclass_remove_callback.hpp>
#include <fcppt/noncopyable.hpp>


namespace awl
{
namespace backends
{
namespace windows
{
namespace window
{

class holder
{
	FCPPT_NONCOPYABLE(
		holder
	);
public:
	holder(
		HWND,
		awl::backends::windows::wndclass_remove_callback const &
	);

	~holder();

	HWND
	get() const;
private:
	HWND hwnd_;

	awl::backends::windows::wndclass_remove_callback const remove_wndclass_;

};

}
}
}
}

#endif

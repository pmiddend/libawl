#ifndef AWL_BACKENDS_WINDOWS_WINDOW_ORIGINAL_OBJECT_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_WINDOW_ORIGINAL_OBJECT_HPP_INCLUDED

#include <awl/class_symbol.hpp>
#include <awl/symbol.hpp>
#include <awl/backends/windows/windows.hpp>
#include <awl/backends/windows/window/common_object.hpp>
#include <awl/backends/windows/wndclass_fwd.hpp>
#include <awl/backends/windows/wndclass_remove_callback.hpp>
#include <awl/window/parameters_fwd.hpp>
#include <fcppt/noncopyable.hpp>


namespace awl
{
namespace backends
{
namespace windows
{
namespace window
{

class AWL_CLASS_SYMBOL original_object
:
	public awl::backends::windows::window::common_object
{
	FCPPT_NONCOPYABLE(
		original_object
	);
public:
	AWL_SYMBOL
	original_object(
		awl::window::parameters const &,
		awl::backends::windows::wndclass &,
		awl::backends::windows::wndclass_remove_callback const &
	);

	AWL_SYMBOL
	~original_object();

	AWL_SYMBOL
	HWND
	hwnd() const;
private:
	HWND const handle_;

	awl::backends::windows::wndclass_remove_callback const remove_wndclass_;
};

}
}
}
}

#endif

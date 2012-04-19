#ifndef AWL_BACKENDS_WINDOWS_WINDOW_ORIGINAL_OBJECT_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_WINDOW_ORIGINAL_OBJECT_HPP_INCLUDED

#include <awl/backends/windows/window/object.hpp>
#include <awl/backends/windows/windows.hpp>
#include <awl/backends/windows/wndclass_fwd.hpp>
#include <awl/backends/windows/wndclass_remove_callback.hpp>
#include <awl/window/parameters_fwd.hpp>
#include <awl/class_symbol.hpp>
#include <awl/symbol.hpp>
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
	public awl::backends::windows::window::object
{
	FCPPT_NONCOPYABLE(
		original_object
	);
public:
	AWL_SYMBOL original_object(
		awl::window::parameters const &,
		windows::wndclass &,
		windows::wndclass_remove_callback const &
	);

	AWL_SYMBOL ~original_object();

	AWL_SYMBOL void
	show();

	AWL_SYMBOL awl::window::dim const
	size() const;

	AWL_SYMBOL HWND
	hwnd() const;
private:
	HWND const handle_;

	windows::wndclass_remove_callback const remove_wndclass_;
};

}
}
}
}

#endif

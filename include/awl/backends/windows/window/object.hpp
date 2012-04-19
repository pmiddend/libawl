#ifndef AWL_BACKENDS_WINDOWS_WINDOW_OBJECT_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_WINDOW_OBJECT_HPP_INCLUDED

#include <awl/backends/windows/window/object_fwd.hpp>
#include <awl/backends/windows/windows.hpp>
#include <awl/window/object.hpp>
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

class AWL_CLASS_SYMBOL object
:
	public awl::window::object
{
	FCPPT_NONCOPYABLE(
		object
	);
protected:
	AWL_SYMBOL object();
public:
	AWL_SYMBOL ~object();

	AWL_SYMBOL
	virtual HWND
	hwnd() const = 0;
};

}
}
}
}

#endif

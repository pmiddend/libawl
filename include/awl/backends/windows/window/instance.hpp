#ifndef AWL_BACKENDS_WINDOWS_WINDOW_INSTANCE_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_WINDOW_INSTANCE_HPP_INCLUDED

#include <awl/backends/windows/window/instance_fwd.hpp>
#include <awl/backends/windows/windows.hpp>
#include <awl/window/instance.hpp>
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

class AWL_CLASS_SYMBOL instance
:
	public awl::window::instance
{
	FCPPT_NONCOPYABLE(
		instance
	)
protected:
	AWL_SYMBOL instance();
public:
	AWL_SYMBOL ~instance();

	AWL_SYMBOL
	virtual HWND
	hwnd() const = 0;
};

}
}
}
}

#endif

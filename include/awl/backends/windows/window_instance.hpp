#ifndef AWL_BACKENDS_WINDOWS_WINDOW_INSTANCE_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_WINDOW_INSTANCE_HPP_INCLUDED

#include <awl/backends/windows/window_instance_fwd.hpp>
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

class AWL_CLASS_SYMBOL window_instance
:
	public awl::window::instance
{
	FCPPT_NONCOPYABLE(
		window_instance
	)
protected:
	AWL_SYMBOL window_instance();
public:
	AWL_SYMBOL ~window_instance();

	AWL_SYMBOL
	virtual HWND
	hwnd() const = 0;
};

}
}
}

#endif

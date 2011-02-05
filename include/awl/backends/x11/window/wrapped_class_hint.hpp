#ifndef AWL_BACKENDS_X11_WINDOW_WRAPPED_CLASS_HINT_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_WRAPPED_CLASS_HINT_HPP_INCLUDED

#include <X11/Xutil.h>
#include <X11/Xlib.h>
#include <awl/backends/x11/window/class_hint.hpp>
#include <awl/symbol.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/scoped_ptr.hpp>
#include <string>

namespace awl
{
namespace backends
{
namespace x11
{
namespace window
{

class wrapped_class_hint
:
	public x11::window::class_hint
{
	FCPPT_NONCOPYABLE(
		wrapped_class_hint
	);
public:
	AWL_SYMBOL
	wrapped_class_hint(
		Display *,
		Window
	);

	AWL_SYMBOL
	~wrapped_class_hint();

	AWL_SYMBOL
	std::string const
	res_name() const;

	AWL_SYMBOL
	std::string const
	res_class() const;
private:
	XClassHint data_;
};

}
}
}
}

#endif

#ifndef AWL_BACKENDS_X11_WINDOW_WRAPPED_CLASS_HINT_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_WRAPPED_CLASS_HINT_HPP_INCLUDED

#include <awl/symbol.hpp>
#include <awl/backends/x11/window/class_hint.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/config/external_begin.hpp>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <string>
#include <fcppt/config/external_end.hpp>


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
	public awl::backends::x11::window::class_hint
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
	~wrapped_class_hint()
	override;

	AWL_SYMBOL
	bool
	has_data() const;

	AWL_SYMBOL
	std::string
	res_name() const
	override;

	AWL_SYMBOL
	std::string
	res_class() const
	override;
private:
	XClassHint data_;
};

}
}
}
}

#endif

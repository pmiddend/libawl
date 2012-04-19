#ifndef AWL_BACKENDS_X11_VISUAL_WRAPPED_HPP_INCLUDED
#define AWL_BACKENDS_X11_VISUAL_WRAPPED_HPP_INCLUDED

#include <awl/backends/x11/visual/info_unique_ptr.hpp>
#include <awl/backends/x11/visual/info_scoped_ptr.hpp>
#include <awl/backends/x11/visual/object.hpp>
#include <awl/symbol.hpp>
#include <fcppt/scoped_ptr_impl.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/config/external_begin.hpp>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <fcppt/config/external_end.hpp>


namespace awl
{
namespace backends
{
namespace x11
{
namespace visual
{

class wrapped
:
	public awl::backends::x11::visual::object
{
	FCPPT_NONCOPYABLE(
		wrapped
	);
public:
	AWL_SYMBOL
	explicit
	wrapped(
		awl::backends::x11::visual::info_unique_ptr
	);

	AWL_SYMBOL
	~wrapped();

	AWL_SYMBOL
	Visual &
	get() const;

	AWL_SYMBOL
	XVisualInfo &
	info() const;
private:
	awl::backends::x11::visual::info_scoped_ptr const info_;
};

}
}
}
}

#endif

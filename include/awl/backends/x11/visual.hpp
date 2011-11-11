#ifndef AWL_BACKENDS_X11_VISUAL_HPP_INCLUDED
#define AWL_BACKENDS_X11_VISUAL_HPP_INCLUDED

#include <awl/backends/x11/visual_fwd.hpp>
#include <awl/symbol.hpp>
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

class visual
{
	FCPPT_NONCOPYABLE(
		visual
	);
protected:
	AWL_SYMBOL
	visual();
public:
	AWL_SYMBOL
	virtual ~visual();

	virtual Visual &
	get() const = 0;

	virtual XVisualInfo &
	info() const = 0;
};

}
}
}

#endif

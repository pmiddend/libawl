#ifndef AWL_BACKENDS_X11_WINDOW_HINTS_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_HINTS_HPP_INCLUDED

#include <awl/symbol.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/config/external_begin.hpp>
#include <X11/Xutil.h>
#include <fcppt/config/external_end.hpp>

namespace awl
{
namespace backends
{
namespace x11
{
namespace window
{

class hints
{
	FCPPT_NONCOPYABLE(
		hints
	);
public:
	AWL_SYMBOL
	hints();

	AWL_SYMBOL
	~hints();

	AWL_SYMBOL
	XWMHints *
	get() const;
private:
	XWMHints *const hints_;
};

}
}
}
}

#endif

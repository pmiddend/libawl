#ifndef AWL_BACKENDS_X11_WINDOW_SIZE_HINTS_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_SIZE_HINTS_HPP_INCLUDED

#include <awl/backends/x11/deleter.hpp>
#include <awl/window/optional_dim.hpp>
#include <awl/symbol.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/scoped_ptr_impl.hpp>
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

class size_hints
{
	FCPPT_NONCOPYABLE(
		size_hints
	);
public:
	AWL_SYMBOL
	size_hints(
		awl::window::optional_dim const &exact_hint,
		awl::window::optional_dim const &minimum_hint,
		awl::window::optional_dim const &maximum_hint
	);

	AWL_SYMBOL
	~size_hints();

	AWL_SYMBOL
	XSizeHints *
	get() const;
private:
	typedef
	fcppt::scoped_ptr<
		XSizeHints,
		awl::backends::x11::deleter
	> scoped_hints;

	scoped_hints const hints_;
};

}
}
}
}

#endif

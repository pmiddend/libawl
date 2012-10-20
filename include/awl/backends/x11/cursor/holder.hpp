#ifndef AWL_BACKENDS_X11_CURSOR_HOLDER_HPP_INCLUDED
#define AWL_BACKENDS_X11_CURSOR_HOLDER_HPP_INCLUDED

#include <awl/symbol.hpp>
#include <awl/backends/x11/display_fwd.hpp>
#include <awl/backends/x11/cursor/holder_fwd.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/config/external_begin.hpp>
#include <X11/X.h>
#include <fcppt/config/external_end.hpp>


namespace awl
{
namespace backends
{
namespace x11
{
namespace cursor
{

class holder
{
	FCPPT_NONCOPYABLE(
		holder
	);
public:
	AWL_SYMBOL
	holder(
		awl::backends::x11::display const &,
		Cursor
	);

	AWL_SYMBOL
	~holder();

	AWL_SYMBOL
	Cursor
	get() const;
private:
	awl::backends::x11::display const &display_;

	Cursor const cursor_;
};

}
}
}
}

#endif

#ifndef AWL_BACKENDS_X11_PIXMAP_HOLDER_HPP_INCLUDED
#define AWL_BACKENDS_X11_PIXMAP_HOLDER_HPP_INCLUDED

#include <awl/symbol.hpp>
#include <awl/backends/x11/display_fwd.hpp>
#include <awl/backends/x11/pixmap/holder_fwd.hpp>
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
namespace pixmap
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
		Pixmap
	);

	AWL_SYMBOL
	~holder();

	AWL_SYMBOL
	Pixmap
	get() const;
private:
	awl::backends::x11::display const &display_;

	Pixmap const pixmap_;
};

}
}
}
}

#endif

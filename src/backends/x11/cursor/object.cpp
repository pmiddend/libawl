#include <awl/backends/x11/cursor/holder.hpp>
#include <awl/backends/x11/cursor/holder_unique_ptr.hpp>
#include <awl/backends/x11/cursor/object.hpp>
#include <awl/cursor/object.hpp>
#include <fcppt/move.hpp>
#include <fcppt/config/external_begin.hpp>
#include <X11/X.h>
#include <fcppt/config/external_end.hpp>


awl::backends::x11::cursor::object::object(
	awl::backends::x11::cursor::holder_unique_ptr _holder
)
:
	awl::cursor::object(),
	holder_(
		fcppt::move(
			_holder
		)
	)
{
}

awl::backends::x11::cursor::object::~object()
{
}

Cursor
awl::backends::x11::cursor::object::get() const
{
	return
		holder_->get();
}

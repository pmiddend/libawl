#include <awl/backends/x11/visual/info_unique_ptr.hpp>
#include <awl/backends/x11/visual/object.hpp>
#include <awl/backends/x11/visual/wrapped.hpp>
#include <fcppt/config/external_begin.hpp>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <utility>
#include <fcppt/config/external_end.hpp>


awl::backends::x11::visual::wrapped::wrapped(
	awl::backends::x11::visual::info_unique_ptr &&_info
)
:
	awl::backends::x11::visual::object(),
	info_(
		std::move(
			_info
		)
	)
{
}

awl::backends::x11::visual::wrapped::~wrapped()
{
}

Visual *
awl::backends::x11::visual::wrapped::get() const
{
	return
		info_->visual;
}

XVisualInfo *
awl::backends::x11::visual::wrapped::info() const
{
	return
		info_.get();
}

int
awl::backends::x11::visual::wrapped::depth() const
{
	return
		this->info()->depth;
}

#include <awl/backends/x11/visual/copy_from_parent.hpp>
#include <awl/backends/x11/visual/object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <fcppt/config/external_end.hpp>


awl::backends::x11::visual::copy_from_parent::copy_from_parent()
:
	awl::backends::x11::visual::object()
{
}

awl::backends::x11::visual::copy_from_parent::~copy_from_parent()
{
}

Visual *
awl::backends::x11::visual::copy_from_parent::get() const
{
	return
		CopyFromParent;
}

XVisualInfo *
awl::backends::x11::visual::copy_from_parent::info() const
{
	return
		nullptr;
}

int
awl::backends::x11::visual::copy_from_parent::depth() const
{
	return
		CopyFromParent;
}

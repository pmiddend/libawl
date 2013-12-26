#ifndef AWL_BACKENDS_WINDOWS_MESSAGE_BOX_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_MESSAGE_BOX_HPP_INCLUDED

#include <awl/symbol.hpp>
#include <awl/backends/windows/windows.hpp>
#include <awl/backends/windows/window/const_optional_object_ref_fwd.hpp>
#include <fcppt/string.hpp>


namespace awl
{
namespace backends
{
namespace windows
{

void
message_box(
	awl::backends::windows::window::const_optional_object_ref const &,
	fcppt::string const &text,
	fcppt::string const &title,
	UINT type
);

}
}
}

#endif

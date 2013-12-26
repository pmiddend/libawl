#ifndef AWL_BACKENDS_WINDOWS_MESSAGE_BOX_NARROW_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_MESSAGE_BOX_NARROW_HPP_INCLUDED

#include <awl/symbol.hpp>
#include <awl/backends/windows/windows.hpp>
#include <awl/backends/windows/window/const_optional_object_ref_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>


namespace awl
{
namespace backends
{
namespace windows
{

void
message_box_narrow(
	awl::backends::windows::window::const_optional_object_ref const &,
	std::string const &text,
	std::string const &title,
	UINT type
);

}
}
}

#endif

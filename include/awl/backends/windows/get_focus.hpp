#ifndef AWL_BACKENDS_WINDOWS_GET_FOCUS_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_GET_FOCUS_HPP_INCLUDED

#include <awl/backends/windows/window/object_unique_ptr.hpp>


namespace awl
{
namespace backends
{
namespace windows
{

awl::backends::windows::window::object_unique_ptr
get_focus();

}
}
}

#endif

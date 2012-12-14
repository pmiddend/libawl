#ifndef AWL_BACKENDS_WINDOWS_CURSOR_OBJECT_UNIQUE_PTR_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_CURSOR_OBJECT_UNIQUE_PTR_HPP_INCLUDED

#include <awl/backends/windows/cursor/object_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <memory>
#include <fcppt/config/external_end.hpp>



namespace awl
{
namespace backends
{
namespace windows
{
namespace cursor
{

typedef std::unique_ptr<
	awl::backends::windows::cursor::object
> object_unique_ptr;

}
}
}
}

#endif

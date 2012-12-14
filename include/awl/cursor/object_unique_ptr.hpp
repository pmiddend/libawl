#ifndef AWL_CURSOR_OBJECT_UNIQUE_PTR_HPP_INCLUDED
#define AWL_CURSOR_OBJECT_UNIQUE_PTR_HPP_INCLUDED

#include <awl/cursor/object_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <memory>
#include <fcppt/config/external_end.hpp>



namespace awl
{
namespace cursor
{

typedef std::unique_ptr<
	awl::cursor::object
> object_unique_ptr;

}
}

#endif

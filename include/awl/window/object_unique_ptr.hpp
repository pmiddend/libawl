#ifndef AWL_WINDOW_OBJECT_UNIQUE_PTR_HPP_INCLUDED
#define AWL_WINDOW_OBJECT_UNIQUE_PTR_HPP_INCLUDED

#include <awl/window/object_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <memory>
#include <fcppt/config/external_end.hpp>


namespace awl
{
namespace window
{

typedef std::unique_ptr<
	awl::window::object
> object_unique_ptr;

}
}

#endif

#ifndef AWL_BACKENDS_WINDOWS_WNDCLASS_PTR_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_WNDCLASS_PTR_HPP_INCLUDED

#include <sge/windows/wndclass_fwd.hpp>
#include <fcppt/shared_ptr.hpp>

namespace sge
{
namespace windows
{

typedef fcppt::shared_ptr<
	wndclass
> wndclass_ptr;

}
}

#endif

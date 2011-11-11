#ifndef AWL_BACKENDS_WINDOWS_WINDOW_ADJUSTED_SIZE_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_WINDOW_ADJUSTED_SIZE_HPP_INCLUDED

#include <awl/backends/windows/windows.hpp>
#include <awl/window/dim.hpp>
#include <awl/window/optional_dim.hpp>
#include <awl/symbol.hpp>

namespace awl
{
namespace backends
{
namespace windows
{
namespace window
{

AWL_SYMBOL
awl::window::dim const
adjusted_size(
	awl::window::optional_dim const &,
	DWORD flags
);

}
}
}
}

#endif

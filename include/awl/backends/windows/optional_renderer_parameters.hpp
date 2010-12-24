#ifndef AWL_BACKENDS_WINDOWS_OPTIONAL_RENDERER_PARAMETERS_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_OPTIONAL_RENDERER_PARAMETERS_HPP_INCLUDED

#include <sge/renderer/parameters.hpp>
#include <fcppt/optional_fwd.hpp>

namespace sge
{
namespace windows
{

typedef fcppt::optional<
	renderer::parameters
> optional_renderer_parameters;

}
}

#endif

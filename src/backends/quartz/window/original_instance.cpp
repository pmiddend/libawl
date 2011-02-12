#include <awl/backends/quartz/window/original_instance.hpp>
#include <awl/window/parameters.hpp>

awl::backends::quartz::window::original_instance::original_instance(
	awl::window::parameters const &_param
)
{
}

awl::backends::quartz::window::original_instance::~original_instance()
{
}

awl::window::dim const
awl::backends::quartz::window::original_instance::size() const
{
	return
		awl::window::dim(
			100,
			100
		);
}

void
awl::backends::quartz::window::original_instance::show()
{
}

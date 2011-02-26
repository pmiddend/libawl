#ifndef AWL_BACKENDS_QUARTZ_WINDOW_ORIGINAL_INSTANCE_HPP_INCLUDED
#define AWL_BACKENDS_QUARTZ_WINDOW_ORIGINAL_INSTANCE_HPP_INCLUDED

#include <awl/backends/quartz/window_ref.hpp>
#include <awl/backends/quartz/window/instance.hpp>
#include <awl/window/parameters_fwd.hpp>
#include <awl/class_symbol.hpp>
#include <awl/symbol.hpp>
#include <fcppt/noncopyable.hpp>

namespace awl
{
namespace backends
{
namespace quartz
{
namespace window
{

class AWL_CLASS_SYMBOL original_instance
:
	public awl::backends::quartz::window::instance
{
	FCPPT_NONCOPYABLE(
		original_instance
	);
public:
	AWL_SYMBOL explicit original_instance(
		awl::window::parameters const &
	);

	AWL_SYMBOL ~original_instance();

	AWL_SYMBOL void
	show();

	AWL_SYMBOL awl::window::dim const
	size() const;

	AWL_SYMBOL window_ref
	get() const;
private:
	window_ref const window_;
};

}
}
}
}

#endif

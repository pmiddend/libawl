#ifndef AWL_BACKENDS_WINDOWS_WINDOW_SYSTEM_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_WINDOW_SYSTEM_HPP_INCLUDED

#include <awl/backends/windows/counted_wndclass_fwd.hpp>
#include <awl/window/system.hpp>
#include <awl/symbol.hpp>
#include <boost/ptr_container/ptr_map.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/string.hpp>

namespace awl
{
namespace backends
{
namespace windows
{

class window_system
:
	public awl::window::system
{
	FCPPT_NONCOPYABLE(
		window_system
	)
public:
	AWL_SYMBOL
	window_system();

	AWL_SYMBOL
	~window_system();
	
	AWL_SYMBOL
	awl::window::instance_ptr const
	create(
		awl::window::parameters const &
	);
private:
	typedef boost::ptr_map<
		fcppt::string,
		windows::counted_wndclass
	> wndclass_map;

	wndclass_map wndclasses_;
};

}
}
}

#endif

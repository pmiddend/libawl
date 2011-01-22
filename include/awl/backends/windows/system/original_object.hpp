#ifndef AWL_BACKENDS_WINDOWS_SYSTEM_ORIGINAL_OBJECT_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_SYSTEM_ORIGINAL_OBJECT_HPP_INCLUDED

#include <awl/backends/windows/system/object.hpp>
#include <awl/backends/windows/counted_wndclass_fwd.hpp>
#include <awl/symbol.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/string.hpp>
#include <boost/ptr_container/ptr_map.hpp>

namespace awl
{
namespace backends
{
namespace windows
{
namespace system
{

class original_object
:
	public windows::system::object
{
	FCPPT_NONCOPYABLE(
		original_object
	)
public:
	AWL_SYMBOL
	original_object();

	AWL_SYMBOL
	~original_object();
	
	AWL_SYMBOL
	awl::window::instance_ptr const
	create(
		awl::window::parameters const &
	);
private:
	void
	unregister_wndclass(
		fcppt::string const &
	);

	typedef boost::ptr_map<
		fcppt::string,
		windows::counted_wndclass
	> wndclass_map;

	wndclass_map wndclasses_;
};

}
}
}
}

#endif

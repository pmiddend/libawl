#ifndef AWL_BACKENDS_WINDOWS_SYSTEM_ORIGINAL_OBJECT_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_SYSTEM_ORIGINAL_OBJECT_HPP_INCLUDED

#include <awl/backends/windows/counted_wndclass_fwd.hpp>
#include <awl/backends/windows/system/object.hpp>
#include <awl/visual/object_unique_ptr.hpp>
#include <awl/window/object_unique_ptr.hpp>
#include <awl/symbol.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/string.hpp>
#include <fcppt/config/external_begin.hpp>
#include <unordered_map>
#include <fcppt/config/external_end.hpp>


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
	);
public:
	AWL_SYMBOL
	original_object();

	AWL_SYMBOL
	~original_object();

	AWL_SYMBOL
	awl::window::object_unique_ptr
	create_window(
		awl::window::parameters const &
	);

	awl::visual::object_unique_ptr
	default_visual();

	awl::window::object_unique_ptr
	focus_window();
private:
	void
	unregister_wndclass(
		fcppt::string const &
	);

	typedef std::unordered_map<
		fcppt::string,
		awl::backends::windows::counted_wndclass
	> wndclass_map;

	wndclass_map wndclasses_;
};

}
}
}
}

#endif

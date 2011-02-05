#ifndef AWL_BACKENDS_WINDOWS_COUNTED_WNDCLASS_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_COUNTED_WNDCLASS_HPP_INCLUDED

#include <awl/backends/windows/counted_wndclass_fwd.hpp>
#include <awl/backends/windows/wndclass.hpp>
#include <awl/backends/windows/windows.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/string.hpp>

namespace awl
{
namespace backends
{
namespace windows
{

class counted_wndclass
{
	FCPPT_NONCOPYABLE(
		counted_wndclass
	);
public:
	typedef unsigned counter_type;

	counted_wndclass(
		fcppt::string const &,
		WNDPROC
	);

	~counted_wndclass();

	void
	add_ref();

	counter_type
	release();

	windows::wndclass &
	wndclass();
private:
	windows::wndclass wndclass_;

	counter_type counter_;
};

}
}
}

#endif

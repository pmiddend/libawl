#include <awl/backends/windows/counted_wndclass.hpp>

awl::backends::windows::counted_wndclass::counted_wndclass(
	fcppt::string const &_name
)
:
	wndclass_(
		_name
	),
	counter_(0u)
{
}

awl::backends::windows::counted_wndclass::~counted_wndclass()
{
}

void
awl::backends::windows::counted_wndclass::add_ref()
{
	++counter_;
}

awl::backends::windows::counted_wndclass::counter_type
awl::backends::windows::counted_wndclass::release()
{
	return --counter_;	
}

awl::backends::windows::wndclass &
awl::backends::windows::counted_wndclass::wndclass()
{
	return wndclass_;
}

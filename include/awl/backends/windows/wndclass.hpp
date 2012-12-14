#ifndef AWL_BACKENDS_WINDOWS_WNDCLASS_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_WNDCLASS_HPP_INCLUDED

#include <awl/backends/windows/wndclass_fwd.hpp>
#include <awl/backends/windows/windows.hpp>
#include <awl/symbol.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/string.hpp>


namespace awl
{
namespace backends
{
namespace windows
{

class wndclass
{
	FCPPT_NONCOPYABLE(
		wndclass
	);
public:
	wndclass();

	AWL_SYMBOL
	wndclass(
		fcppt::string const &class_name,
		WNDPROC
	);

	AWL_SYMBOL
	wndclass(
		wndclass &&
	);

	AWL_SYMBOL
	wndclass &
	operator=(
		wndclass &&
	);

	AWL_SYMBOL
	~wndclass();

	AWL_SYMBOL
	fcppt::string const &
	name() const;

	AWL_SYMBOL
	void
	swap(
		wndclass &
	);
private:
	fcppt::string class_name_;
};

AWL_SYMBOL
void
swap(
	awl::backends::windows::wndclass &,
	awl::backends::windows::wndclass &
);

}
}
}

#endif

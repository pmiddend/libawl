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
	)
public:
	AWL_SYMBOL wndclass(
		fcppt::string const &class_name,
		WNDPROC
	);

	AWL_SYMBOL ~wndclass();

	AWL_SYMBOL fcppt::string const &
	name() const;
private:
	fcppt::string const class_name_;
};

}
}
}

#endif

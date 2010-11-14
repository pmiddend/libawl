#ifndef AWL_BACKENDS_WINDOWS_WNDCLASS_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_WNDCLASS_HPP_INCLUDED

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
	SGE_SYMBOL wndclass(
		fcppt::string const &class_name,
		WNDPROC
	);

	SGE_SYMBOL ~wndclass();

	SGE_SYMBOL fcppt::string const &
	name() const;
private:
	fcppt::string const class_name_;
};

}
}
}

#endif

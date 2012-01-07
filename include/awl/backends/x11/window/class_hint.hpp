#ifndef AWL_BACKENDS_X11_WINDOW_CLASS_HINT_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_CLASS_HINT_HPP_INCLUDED

#include <awl/backends/x11/window/class_hint_fwd.hpp>
#include <awl/symbol.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/config/external_begin.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>

namespace awl
{
namespace backends
{
namespace x11
{
namespace window
{

class class_hint
{
	FCPPT_NONCOPYABLE(
		class_hint
	);
protected:
	AWL_SYMBOL
	class_hint();
public:
	AWL_SYMBOL
	virtual ~class_hint() = 0;

	virtual
	std::string const
	res_name() const = 0;

	virtual
	std::string const
	res_class() const = 0;
};

}
}
}
}

#endif

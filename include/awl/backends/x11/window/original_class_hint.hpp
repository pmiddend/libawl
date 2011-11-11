#ifndef AWL_BACKENDS_X11_WINDOW_ORIGINAL_CLASS_HINT_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_ORIGINAL_CLASS_HINT_HPP_INCLUDED

#include <awl/backends/x11/window/class_hint.hpp>
#include <awl/symbol.hpp>
#include <fcppt/string.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/scoped_ptr.hpp>
#include <fcppt/config/external_begin.hpp>
#include <string>
#include <X11/Xutil.h>
#include <fcppt/config/external_end.hpp>

namespace awl
{
namespace backends
{
namespace x11
{
namespace window
{

class original_class_hint
:
	public x11::window::class_hint
{
	FCPPT_NONCOPYABLE(
		original_class_hint
	);
public:
	AWL_SYMBOL
	explicit
	original_class_hint(
		fcppt::string const &app_name,
		fcppt::string const &class_name
	);

	AWL_SYMBOL
	~original_class_hint();

	AWL_SYMBOL
	XClassHint *
	get() const;

	AWL_SYMBOL
	std::string const
	res_name() const;

	AWL_SYMBOL
	std::string const
	res_class() const;
private:
	class impl;

	fcppt::scoped_ptr<
		impl
	> impl_;

	std::string const
		res_name_,
		res_class_;
};

}
}
}
}

#endif

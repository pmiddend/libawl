#ifndef AWL_BACKENDS_X11_CLASS_HINT_HPP_INCLUDED
#define AWL_BACKENDS_X11_CLASS_HINT_HPP_INCLUDED

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <fcppt/string.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/scoped_ptr.hpp>
#include <string>

namespace awl
{
namespace backends
{
namespace x11
{
class class_hint
{
FCPPT_NONCOPYABLE(class_hint)
public:
	explicit
	class_hint(
		fcppt::string const &app_name,
		fcppt::string const &class_name
	);

	~class_hint();

	XClassHint *
	get() const;
private:
	class impl;

	fcppt::scoped_ptr<impl> impl_;

	std::string const
		app_name,
		res_name;
};
}
}
}

#endif
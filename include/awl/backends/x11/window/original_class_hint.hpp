#ifndef AWL_BACKENDS_X11_WINDOW_ORIGINAL_CLASS_HINT_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_ORIGINAL_CLASS_HINT_HPP_INCLUDED

#include <awl/symbol.hpp>
#include <awl/backends/x11/window/class_hint.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/string.hpp>
#include <fcppt/config/external_begin.hpp>
#include <X11/Xutil.h>
#include <memory>
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

class original_class_hint
:
	public awl::backends::x11::window::class_hint
{
	FCPPT_NONCOPYABLE(
		original_class_hint
	);
public:
	AWL_SYMBOL
	original_class_hint(
		fcppt::string const &app_name,
		fcppt::string const &class_name
	);

	AWL_SYMBOL
	~original_class_hint()
	override;

	AWL_SYMBOL
	XClassHint *
	get() const;

	AWL_SYMBOL
	std::string
	res_name() const
	override;

	AWL_SYMBOL
	std::string
	res_class() const
	override;
private:
	class impl;

	std::unique_ptr<
		impl
	> const impl_;

	std::string const
		res_name_,
		res_class_;
};

}
}
}
}

#endif

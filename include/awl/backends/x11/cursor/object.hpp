#ifndef AWL_BACKENDS_X11_CURSOR_OBJECT_HPP_INCLUDED
#define AWL_BACKENDS_X11_CURSOR_OBJECT_HPP_INCLUDED

#include <awl/class_symbol.hpp>
#include <awl/symbol.hpp>
#include <awl/backends/x11/cursor/holder_unique_ptr.hpp>
#include <awl/backends/x11/cursor/object_fwd.hpp>
#include <awl/cursor/object.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/config/external_begin.hpp>
#include <X11/X.h>
#include <fcppt/config/external_end.hpp>


namespace awl
{
namespace backends
{
namespace x11
{
namespace cursor
{

class AWL_CLASS_SYMBOL object
:
	public awl::cursor::object
{
	FCPPT_NONCOPYABLE(
		object
	);
public:
	AWL_SYMBOL
	explicit
	object(
		awl::backends::x11::cursor::holder_unique_ptr &&
	);

	AWL_SYMBOL
	~object()
	override;

	AWL_SYMBOL
	Cursor
	get() const;
private:
	awl::backends::x11::cursor::holder_unique_ptr const holder_;
};

}
}
}
}

#endif

#ifndef AWL_BACKENDS_X11_PIXMAP_ORIGINAL_OBJECT_HPP_INCLUDED
#define AWL_BACKENDS_X11_PIXMAP_ORIGINAL_OBJECT_HPP_INCLUDED

#include <awl/class_symbol.hpp>
#include <awl/symbol.hpp>
#include <awl/backends/x11/pixmap/holder.hpp>
#include <awl/backends/x11/pixmap/object.hpp>
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
namespace pixmap
{

class AWL_CLASS_SYMBOL original_object
{
	FCPPT_NONCOPYABLE(
		object
	);
public:
	AWL_SYMBOL
	explicit
	original_object(
		awl::backends::x11::pixmap::holder_unique_ptr &&
	);

	~object()
	override;

	Pixmap
	get() const
	override;
private:
	awl::backends::x11::pixmap::holder_unique_ptr const holder_;
};

}
}
}
}

#endif

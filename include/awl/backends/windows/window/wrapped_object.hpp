#ifndef AWL_BACKENDS_WINDOWS_WINDOW_WRAPPED_OBJECT_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_WINDOW_WRAPPED_OBJECT_HPP_INCLUDED

#include <awl/class_symbol.hpp>
#include <awl/symbol.hpp>
#include <awl/backends/windows/windows.hpp>
#include <awl/backends/windows/cursor/const_optional_object_ref_fwd.hpp>
#include <awl/backends/windows/window/common_object.hpp>
#include <awl/visual/object_fwd.hpp>
#include <awl/visual/object_scoped_ptr.hpp>
#include <fcppt/noncopyable.hpp>


namespace awl
{
namespace backends
{
namespace windows
{
namespace window
{

class AWL_CLASS_SYMBOL wrapped_object
:
	public awl::backends::windows::window::common_object
{
	FCPPT_NONCOPYABLE(
		wrapped_object
	);
public:
	AWL_SYMBOL
	explicit
	wrapped_object(
		HWND
	);

	AWL_SYMBOL
	~wrapped_object();

	AWL_SYMBOL
	HWND
	hwnd() const;

	AWL_SYMBOL
	awl::backends::windows::cursor::const_optional_object_ref const
	cursor() const
	override;

	AWL_SYMBOL
	awl::visual::object const &
	visual() const
	override;
private:
	awl::visual::object_scoped_ptr const visual_;

	HWND const hwnd_;
};

}
}
}
}

#endif

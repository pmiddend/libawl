#ifndef AWL_BACKENDS_WINDOWS_VISUAL_NULL_OBJECT_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_VISUAL_NULL_OBJECT_HPP_INCLUDED

#include <awl/symbol.hpp>
#include <awl/backends/windows/windows.hpp>
#include <awl/backends/windows/visual/object.hpp>
#include <fcppt/noncopyable.hpp>


namespace awl
{
namespace backends
{
namespace windows
{
namespace visual
{

class null_object
:
	public awl::backends::windows::visual::object
{
	FCPPT_NONCOPYABLE(
		null_object
	);
public:
	AWL_SYMBOL
	null_object();

	AWL_SYMBOL
	~null_object();
private:
	void
	apply(
		HWND
	) const;
};

}
}
}
}

#endif

#ifndef AWL_BACKENDS_WINDOWS_CURSOR_OBJECT_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_CURSOR_OBJECT_HPP_INCLUDED

#include <awl/class_symbol.hpp>
#include <awl/symbol.hpp>
#include <awl/backends/windows/windows.hpp>
#include <awl/backends/windows/cursor/object_fwd.hpp>
#include <awl/cursor/object.hpp>
#include <fcppt/noncopyable.hpp>


namespace awl
{
namespace backends
{
namespace windows
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
protected:
	AWL_SYMBOL
	object();
public:
	AWL_SYMBOL
	virtual
	~object() = 0;

	virtual
	HCURSOR
	get() const = 0;
};

}
}
}
}

#endif

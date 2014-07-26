#ifndef AWL_BACKENDS_WINDOWS_CURSOR_CREATED_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_CURSOR_CREATED_HPP_INCLUDED

#include <awl/class_symbol.hpp>
#include <awl/symbol.hpp>
#include <awl/backends/windows/windows.hpp>
#include <awl/backends/windows/cursor/and_plane.hpp>
#include <awl/backends/windows/cursor/created_fwd.hpp>
#include <awl/backends/windows/cursor/dim_fwd.hpp>
#include <awl/backends/windows/cursor/object.hpp>
#include <awl/backends/windows/cursor/xor_plane.hpp>
#include <awl/cursor/hotspot_fwd.hpp>
#include <fcppt/noncopyable.hpp>


namespace awl
{
namespace backends
{
namespace windows
{
namespace cursor
{

class AWL_CLASS_SYMBOL created
:
	public awl::backends::windows::cursor::object
{
	FCPPT_NONCOPYABLE(
		created
	);
public:
	AWL_SYMBOL
	created(
		awl::cursor::hotspot,
		awl::backends::windows::cursor::dim,
		awl::backends::windows::cursor::and_plane,
		awl::backends::windows::cursor::xor_plane
	);

	AWL_SYMBOL
	~created();

	AWL_SYMBOL
	HCURSOR
	get() const;
private:
	HCURSOR const cursor_;
};

}
}
}
}

#endif

#include <awl/backends/windows/windows.hpp>
#include <awl/backends/windows/cursor/object.hpp>
#include <awl/backends/windows/cursor/shared.hpp>	


awl::backends::windows::cursor::shared::shared(
	HCURSOR const _cursor
)
:
	cursor_(
		_cursor
	)
{
}

awl::backends::windows::cursor::shared::~shared()
{
}

HCURSOR
awl::backends::windows::cursor::shared::get() const
{
	return cursor_;
}

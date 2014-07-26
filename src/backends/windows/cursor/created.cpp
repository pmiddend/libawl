#include <awl/exception.hpp>
#include <awl/backends/windows/module_handle.hpp>
#include <awl/backends/windows/windows.hpp>
#include <awl/backends/windows/cursor/and_plane.hpp>
#include <awl/backends/windows/cursor/created.hpp>
#include <awl/backends/windows/cursor/dim.hpp>
#include <awl/backends/windows/cursor/object.hpp>
#include <awl/backends/windows/cursor/xor_plane.hpp>
#include <awl/cursor/hotspot.hpp>
#include <fcppt/text.hpp>
#include <fcppt/assert/error.hpp>
#include <fcppt/cast/to_signed.hpp>


awl::backends::windows::cursor::created::created(
	awl::cursor::hotspot const _hotspot,
	awl::backends::windows::cursor::dim const _dim,
	awl::backends::windows::cursor::and_plane const _and_plane,
	awl::backends::windows::cursor::xor_plane const _xor_plane
)
:
	awl::backends::windows::cursor::object(),
	cursor_(
		::CreateCursor(
			awl::backends::windows::module_handle(),
			fcppt::cast::to_signed(
				_hotspot.x()
			),
			fcppt::cast::to_signed(
				_hotspot.y()
			),
			fcppt::cast::to_signed(
				_dim.w()
			),
			fcppt::cast::to_signed(
				_dim.h()
			),
			_and_plane.get(),
			_xor_plane.get()
		)
	)
{
	if(
		cursor_
		==
		nullptr
	)
		throw
			awl::exception{
				FCPPT_TEXT("CreateCursor failed")
			};
}

awl::backends::windows::cursor::created::~created()
{
	FCPPT_ASSERT_ERROR(
		::DestroyCursor(
			cursor_
		)
		!= 0
	);
}

HCURSOR
awl::backends::windows::cursor::created::get() const
{
	return
		cursor_;
}

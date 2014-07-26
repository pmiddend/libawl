#include <awl/backends/windows/system_metrics.hpp>
#include <awl/backends/windows/windows.hpp>
#include <awl/backends/windows/cursor/create_invisible.hpp>
#include <awl/backends/windows/cursor/created.hpp>
#include <awl/backends/windows/cursor/dim.hpp>
#include <awl/backends/windows/cursor/load.hpp>
#include <awl/backends/windows/cursor/object_unique_ptr.hpp>
#include <awl/backends/windows/cursor/shared.hpp>
#include <awl/backends/windows/cursor/size.hpp>
#include <awl/cursor/hotspot.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/cast/to_unsigned.hpp>
#include <fcppt/config/external_begin.hpp>
#include <limits>
#include <vector>
#include <fcppt/config/external_end.hpp>


awl::backends::windows::cursor::object_unique_ptr
awl::backends::windows::cursor::create_invisible()
{
	awl::backends::windows::cursor::dim const dim(
		fcppt::cast::to_unsigned(
			awl::backends::windows::system_metrics(
				SM_CXCURSOR
			)
		),
		fcppt::cast::to_unsigned(
			awl::backends::windows::system_metrics(
				SM_CYCURSOR
			)
		)
	);

	typedef
	std::vector<
		BYTE
	>
	byte_vector;

	awl::backends::windows::cursor::size const size(
		dim.content()
		/
		8
	);

	byte_vector const and_vector(
		size,
		std::numeric_limits<
			BYTE
		>::max()
	);

	byte_vector const xor_vector(
		size,
		0
	);

	return
		fcppt::make_unique_ptr<
			awl::backends::windows::cursor::created
		>(
			awl::cursor::hotspot::null(),
			dim,
			awl::backends::windows::cursor::and_plane(
				and_vector.data()
			),
			awl::backends::windows::cursor::xor_plane(
				xor_vector.data()
			)
		);
}

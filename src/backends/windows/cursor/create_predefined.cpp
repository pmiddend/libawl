#include <awl/backends/windows/cursor/convert_predefined.hpp>
#include <awl/backends/windows/cursor/create_predefined.hpp>
#include <awl/backends/windows/cursor/load.hpp>
#include <awl/backends/windows/cursor/object_unique_ptr.hpp>
#include <awl/backends/windows/cursor/shared.hpp>
#include <awl/cursor/predefined.hpp>
#include <fcppt/make_unique_ptr.hpp>


awl::backends::windows::cursor::object_unique_ptr
awl::backends::windows::cursor::create_predefined(
	awl::cursor::predefined const _type
)
{
	return
		awl::backends::windows::cursor::object_unique_ptr(
			fcppt::make_unique_ptr<
				awl::backends::windows::cursor::shared
			>(
				awl::backends::windows::cursor::load(
					awl::backends::windows::cursor::convert_predefined(
						_type
					)
				)
			)
		);
}

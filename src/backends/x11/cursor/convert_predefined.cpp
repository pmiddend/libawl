#include <awl/backends/x11/cursor/convert_predefined.hpp>
#include <awl/backends/x11/cursor/shape.hpp>
#include <awl/cursor/predefined.hpp>
#include <fcppt/strong_typedef_construct_cast.hpp>
#include <fcppt/assert/unreachable.hpp>
#include <fcppt/config/external_begin.hpp>
#include <X11/cursorfont.h>
#include <fcppt/config/external_end.hpp>


awl::backends::x11::cursor::shape const
awl::backends::x11::cursor::convert_predefined(
	awl::cursor::predefined::type const _type
)
{
	switch(
		_type
	)
	{
	case awl::cursor::predefined::arrow:
		return
			fcppt::strong_typedef_construct_cast<
				awl::backends::x11::cursor::shape
			>(
				XC_left_ptr
			);
	case awl::cursor::predefined::cross:
		return
			fcppt::strong_typedef_construct_cast<
				awl::backends::x11::cursor::shape
			>(
				XC_cross
			);
	case awl::cursor::predefined::hand:
		return
			fcppt::strong_typedef_construct_cast<
				awl::backends::x11::cursor::shape
			>(
				XC_hand1
			);
	case awl::cursor::predefined::icon:
		return
			fcppt::strong_typedef_construct_cast<
				awl::backends::x11::cursor::shape
			>(
				XC_icon
			);
	}

	FCPPT_ASSERT_UNREACHABLE;
}

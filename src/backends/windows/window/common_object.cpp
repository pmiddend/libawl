#include <awl/exception.hpp>
#include <awl/backends/windows/optional_rect.hpp>
#include <awl/backends/windows/windows.hpp>
#include <awl/backends/windows/event/lparam.hpp>
#include <awl/backends/windows/event/post_message.hpp>
#include <awl/backends/windows/event/type.hpp>
#include <awl/backends/windows/event/wparam.hpp>
#include <awl/backends/windows/window/common_object.hpp>
#include <awl/backends/windows/window/get_client_rect.hpp>
#include <awl/backends/windows/window/object.hpp>
#include <awl/window/dim.hpp>
#include <awl/window/object.hpp>
#include <awl/window/rect.hpp>
#include <awl/window/unit.hpp>
#include <fcppt/maybe.hpp>
#include <fcppt/strong_typedef_construct_cast.hpp>
#include <fcppt/text.hpp>
#include <fcppt/cast/try_dynamic.hpp>
#include <fcppt/cast/size.hpp>
#include <fcppt/math/dim/structure_cast.hpp>


awl::backends::windows::window::common_object::common_object()
:
	awl::backends::windows::window::object()
{
}

awl::backends::windows::window::common_object::~common_object()
{
}

awl::window::dim const
awl::backends::windows::window::common_object::size() const
{
	return
		fcppt::math::dim::structure_cast<
			awl::window::dim
		>(
			this->rect().size()
		);
}

awl::window::rect const
awl::backends::windows::window::common_object::rect() const
{
	awl::backends::windows::optional_rect const ret(
		awl::backends::windows::window::get_client_rect(
			*this
		)
	);

	if(
		!ret
	)
		throw awl::exception(
			FCPPT_TEXT("Can't get the window size because GetWindowRect failed!")
		);

	return
		awl::window::rect(
			awl::window::rect::vector(
				fcppt::cast::size<
					awl::window::unit
				>(
					ret->left
				),
				fcppt::cast::size<
					awl::window::unit
				>(
					ret->top
				)
			),
			awl::window::rect::dim(
				fcppt::cast::size<
					awl::window::unit
				>(
					ret->right - ret->left
				),
				fcppt::cast::size<
					awl::window::unit
				>(
					ret->bottom - ret->top
				)
			)
		);
}

void
awl::backends::windows::window::common_object::show()
{
	BOOL const prev_visible(
		::ShowWindow(
			this->hwnd(),
			SW_SHOWDEFAULT
		)
	);

	if(
		prev_visible != 0
	)
		return;

	awl::window::dim const cur_size(
		this->size()
	);

	awl::backends::windows::event::post_message(
		this->hwnd(),
		fcppt::strong_typedef_construct_cast<
			awl::backends::windows::event::type
		>(
			WM_SIZE
		),
		fcppt::strong_typedef_construct_cast<
			awl::backends::windows::event::wparam
		>(
			SIZE_RESTORED
		),
		awl::backends::windows::event::lparam(
			MAKELPARAM(
				static_cast<
					WORD
				>(
					cur_size.w()
				),
				static_cast<
					WORD
				>(
					cur_size.h()
				)
			)
		)
	);
}

bool
awl::backends::windows::window::common_object::equal_to(
	awl::window::object const &_other
) const
{
	return
		fcppt::maybe(
			fcppt::cast::try_dynamic<
				awl::backends::windows::window::object const &
			>(
				_other
			),
			[]
			{
				return
					false;
			},
			[
				this
			](
				awl::backends::windows::window::object const &_casted_other
			)
			{
				return
					_casted_other.hwnd()
					==
					this->hwnd();
			}
		);
}

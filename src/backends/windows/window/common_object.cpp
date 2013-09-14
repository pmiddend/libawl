#include <awl/exception.hpp>
#include <awl/backends/windows/optional_rect.hpp>
#include <awl/backends/windows/windows.hpp>
#include <awl/backends/windows/event/post_message.hpp>
#include <awl/backends/windows/event/lparam.hpp>
#include <awl/backends/windows/event/type.hpp>
#include <awl/backends/windows/event/wparam.hpp>
#include <awl/backends/windows/window/common_object.hpp>
#include <awl/backends/windows/window/get_client_rect.hpp>
#include <awl/backends/windows/window/object.hpp>
#include <awl/window/dim.hpp>
#include <awl/window/object.hpp>
#include <awl/window/size.hpp>
#include <fcppt/strong_typedef_construct_cast.hpp>
#include <fcppt/text.hpp>
#include <fcppt/try_dynamic_cast.hpp>
#include <fcppt/cast/size.hpp>
#include <fcppt/cast/to_unsigned.hpp>


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
	awl::backends::windows::optional_rect const rect(
		awl::backends::windows::window::get_client_rect(
			*this
		)
	);

	if(
		!rect
	)
		throw awl::exception(
			FCPPT_TEXT("Can't get the window size because GetWindowRect failed!")
		);

	return
		awl::window::dim(
			fcppt::cast::size<
				awl::window::size
			>(
				fcppt::cast::to_unsigned(
					rect->right - rect->left
				)
			),
			fcppt::cast::size<
				awl::window::size
			>(
				fcppt::cast::to_unsigned(
					rect->bottom - rect->top
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
	FCPPT_TRY_DYNAMIC_CAST(
		awl::backends::windows::window::object const *,
		casted_other,
		&_other
	)
	{
		return
			casted_other->hwnd()
			==
			this->hwnd();
	}

	return false;
}

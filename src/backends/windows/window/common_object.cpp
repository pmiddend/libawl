#include <awl/backends/windows/windows.hpp>
#include <awl/backends/windows/event/post_message.hpp>
#include <awl/backends/windows/event/lparam.hpp>
#include <awl/backends/windows/event/type.hpp>
#include <awl/backends/windows/event/wparam.hpp>
#include <awl/backends/windows/window/client_rect.hpp>
#include <awl/backends/windows/window/common_object.hpp>
#include <awl/backends/windows/window/object.hpp>
#include <awl/window/dim.hpp>
#include <awl/window/object.hpp>
#include <fcppt/strong_typedef_construct_cast.hpp>
#include <fcppt/try_dynamic_cast.hpp>


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
	RECT const rect(
		awl::backends::windows::window::client_rect(
			*this
		)
	);

	return
		awl::window::dim(
			rect.right - rect.left,
			rect.bottom - rect.top
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

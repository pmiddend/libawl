#include <awl/exception.hpp>
#include <awl/backends/x11/window/size_hints.hpp>
#include <awl/window/optional_dim.hpp>
#include <fcppt/text.hpp>
#include <fcppt/cast/to_signed.hpp>
#include <fcppt/config/external_begin.hpp>
#include <X11/Xutil.h>
#include <fcppt/config/external_end.hpp>


awl::backends::x11::window::size_hints::size_hints(
	awl::window::optional_dim const &_exact_hint,
	awl::window::optional_dim const &_minimum_hint,
	awl::window::optional_dim const &_maximum_hint
)
:
	hints_(
		::XAllocSizeHints()
	)
{
	if(
		!hints_
	)
		throw awl::exception(
			FCPPT_TEXT("XAllocSizeHints() failed!")
		);

	hints_->flags = 0;

	if(
		_exact_hint
	)
	{
		hints_->base_width =
			fcppt::cast::to_signed(
				_exact_hint->w()
			);

		hints_->base_height =
			fcppt::cast::to_signed(
				_exact_hint->h()
			);

		hints_->flags |= PSize;
	}

	if(
		_minimum_hint
	)
	{

		hints_->min_width =
			fcppt::cast::to_signed(
				_minimum_hint->w()
			);

		hints_->min_height =
			fcppt::cast::to_signed(
				_minimum_hint->h()
			);

		hints_->flags |= PMinSize;
	}

	if(
		_maximum_hint
	)
	{
		hints_->max_width =
			fcppt::cast::to_signed(
				_maximum_hint->w()
			);

		hints_->max_height =
			fcppt::cast::to_signed(
				_maximum_hint->h()
			);

		hints_->flags |= PMaxSize;
	}
}

XSizeHints *
awl::backends::x11::window::size_hints::get() const
{
	return
		hints_.get();
}

awl::backends::x11::window::size_hints::~size_hints()
{
}

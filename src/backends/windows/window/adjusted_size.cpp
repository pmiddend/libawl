#include <awl/exception.hpp>
#include <awl/backends/windows/windows.hpp>
#include <awl/backends/windows/window/adjusted_size.hpp>
#include <fcppt/optional_impl.hpp>
#include <fcppt/text.hpp>
#include <fcppt/math/dim/object_impl.hpp>


awl::window::dim const
awl::backends::windows::window::adjusted_size(
	awl::window::optional_dim const &_dim,
	DWORD const _flags
)
{
	if(
		!_dim
	)
		return
			awl::window::dim(
				CW_USEDEFAULT,
				CW_USEDEFAULT
			);

	RECT rect =
	{
		0,
		0,
		_dim->w(),
		_dim->h()
	};

	if(
		!::AdjustWindowRect(
			&rect,
			_flags,
			FALSE
		)
	)
		throw awl::exception(
			FCPPT_TEXT("AdjustWindowRect() failed!")
		);

	return
		awl::window::dim(
			rect.right - rect.left,
			rect.bottom - rect.top
		);
}

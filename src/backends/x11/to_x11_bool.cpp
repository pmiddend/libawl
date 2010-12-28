#include <awl/backends/x11/to_x11_bool.hpp>

Bool
awl::backends::x11::to_x11_bool(
	bool const _value
)
{
	return
		_value
		?
			True
		:
			False;
}

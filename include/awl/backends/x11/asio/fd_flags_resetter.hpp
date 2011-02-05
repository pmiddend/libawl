#ifndef AWL_BACKENDS_X11_ASIO_FD_FLAGS_RESETTER_HPP_INCLUDED
#define AWL_BACKENDS_X11_ASIO_FD_FLAGS_RESETTER_HPP_INCLUDED

#include <awl/backends/x11/display_ptr.hpp>
#include <fcppt/noncopyable.hpp>

namespace awl
{
namespace backends
{
namespace x11
{
namespace asio
{

class fd_flags_resetter
{
	FCPPT_NONCOPYABLE(
		fd_flags_resetter
	);
public:
	explicit fd_flags_resetter(
		x11::display_ptr
	);

	~fd_flags_resetter();
private:
	x11::display_ptr const display_;

	int const flags_;
};

}
}
}
}

#endif

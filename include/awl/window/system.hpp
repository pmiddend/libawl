#ifndef AWL_WINDOW_SYSTEM_HPP_INCLUDED
#define AWL_WINDOW_SYSTEM_HPP_INCLUDED

#include <awl/window/instance_ptr.hpp>
#include <awl/window/parameters_fwd.hpp>
#include <fcppt/noncopyable.hpp>

namespace awl
{
namespace window
{

class system
{
	FCPPT_NONCOPYABLE(
		system
	)
protected:
	explicit
	system();
public:
	virtual window::instance_ptr const
	create(
		window::parameters const &
	) = 0;

	virtual 
	~system();
};

}
}

#endif

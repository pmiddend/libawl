#ifndef AWL_WINDOW_SYSTEM_HPP_INCLUDED
#define AWL_WINDOW_SYSTEM_HPP_INCLUDED

#include <awl/window/instance_ptr.hpp>
#include <awl/window/parameters_fwd.hpp>
#include <awl/class_symbol.hpp>
#include <awl/symbol.hpp>
#include <fcppt/noncopyable.hpp>

namespace awl
{
namespace window
{

class AWL_CLASS_SYMBOL system
{
	FCPPT_NONCOPYABLE(
		system
	)
protected:
	AWL_SYMBOL
	explicit
	system();
public:
	virtual window::instance_ptr const
	create(
		window::parameters const &
	) = 0;

	AWL_SYMBOL
	virtual 
	~system();
};

}
}

#endif

#ifndef AWL_BACKENDS_COCOA_SYSTEM_OBJECT_HPP_INCLUDED
#define AWL_BACKENDS_COCOA_SYSTEM_OBJECT_HPP_INCLUDED

#include <awl/system/object.hpp>
#include <awl/window/object_unique_ptr.hpp>
#include <awl/window/parameters_fwd.hpp>
#include <awl/symbol.hpp>
#include <fcppt/noncopyable.hpp>
#import <Cocoa/Cocoa.h>

namespace awl
{
namespace backends
{
namespace cocoa
{
namespace system
{
class object
:
	public awl::system::object
{
FCPPT_NONCOPYABLE(
		object);
public:
	explicit
	object();

	awl::window::object_unique_ptr
	create(
		awl::window::parameters const &);

	~object();
private:
	NSApplication *app_;
};
}
}
}
}

#endif

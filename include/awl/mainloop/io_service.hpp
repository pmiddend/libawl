#ifndef AWL_MAINLOOP_IO_SERVICE_HPP_INCLUDED
#define AWL_MAINLOOP_IO_SERVICE_HPP_INCLUDED

#include <awl/mainloop/io_service_fwd.hpp>
#include <awl/mainloop/dispatcher_unique_ptr.hpp>
#include <awl/mainloop/dispatcher_callback.hpp>
#include <awl/mainloop/nullary_callback.hpp>
#include <awl/system/object_fwd.hpp>
#include <awl/class_symbol.hpp>
#include <awl/symbol.hpp>
#include <fcppt/noncopyable.hpp>

namespace awl
{
namespace mainloop
{

class AWL_CLASS_SYMBOL io_service
{
	FCPPT_NONCOPYABLE(
		io_service
	);
protected:
	AWL_SYMBOL
	io_service();
public:
	AWL_SYMBOL
	virtual ~io_service();

	virtual void
	run_one() = 0;

	virtual void
	run() = 0;

	virtual void
	poll() = 0;

	virtual void
	stop() = 0;

	virtual void
	reset() = 0;

	virtual void
	post(
		mainloop::nullary_callback const &
	) = 0;

	virtual mainloop::dispatcher_unique_ptr
	create_dispatcher(
		awl::system::object &,
		mainloop::dispatcher_callback const &
	) = 0;
};

}
}

#endif

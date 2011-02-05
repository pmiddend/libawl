#ifndef AWL_BACKENDS_WINDOWS_SYSTEM_EVENT_ORIGINAL_HANDLE_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_SYSTEM_EVENT_ORIGINAL_HANDLE_HPP_INCLUDED

#include <awl/backends/windows/system/event/handle.hpp>
#include <awl/backends/windows/system/event/handle_destroy_callback.hpp>
#include <awl/backends/windows/windows.hpp>
#include <awl/symbol.hpp>
#include <fcppt/function/object.hpp>
#include <fcppt/noncopyable.hpp>

namespace awl
{
namespace backends
{
namespace windows
{
namespace system
{
namespace event
{

class original_handle
:
	public system::event::handle
{
	FCPPT_NONCOPYABLE(
		original_handle
	);
public:
	AWL_SYMBOL
	explicit original_handle(
		system::event::handle_destroy_callback const &
	);

	AWL_SYMBOL
	~original_handle();

	AWL_SYMBOL
	HANDLE
	get() const;

	AWL_SYMBOL
	bool
	ready() const;
private:
	system::event::handle_destroy_callback const on_destroy_;

	HANDLE handle_;
};

}
}
}
}
}

#endif

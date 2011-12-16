#ifndef AWL_BACKENDS_WINDOWS_EVENT_MESSAGE_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_EVENT_MESSAGE_HPP_INCLUDED

#include <awl/symbol.hpp>
#include <awl/backends/windows/windows.hpp>
#include <awl/backends/windows/event/message_fwd.hpp>


namespace awl
{
namespace backends
{
namespace windows
{
namespace event
{

class message
{
public:
	AWL_SYMBOL
	explicit
	message(
		MSG const &
	);

	AWL_SYMBOL
	MSG const &
	get() const;
private:
	MSG msg_;
};

}
}
}
}

#endif

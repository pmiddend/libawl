#include <X11/Xlib.h>
#include <fcppt/time/sleep_any.hpp>
#include <fcppt/chrono/seconds.hpp>
#include <fcppt/exception.hpp>

namespace add
{
class display
{
public:
	explicit
	display()
	:
		handle(
			XOpenDisplay(0))
	{
		if (!handle)
		{
			fcppt::time::sleep_any(
				fcppt::chrono::seconds(1));
			
			handle = 
				XOpenDisplay(0);

			if (!handle)
				throw fcppt::exception(FCPPT_TEXT("Couldn't open display"));
		}
	}
	
	~display()
	{
		if (handle)
			XCloseDisplay(
				handle);
	}

	Display *handle;
};
}

int main()
{
	// The 0 is a char* defining to which server/screen to connect to
	add::display d(XOpenDisplay(0));
}

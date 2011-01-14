#include <awl/backends/windows/wndclass.hpp>
#include <awl/backends/windows/windows.hpp>
#include <awl/backends/windows/module_handle.hpp>
#include <awl/exception.hpp>
#include <fcppt/text.hpp>
#include <cstring>

awl::backends::windows::wndclass::wndclass(
	fcppt::string const &_class_name,
	WNDPROC const _proc
)
:
	class_name_(
		_class_name
	)
{
	WNDCLASSEX wndclassex;

	std::memset(
		&wndclassex,
		0,
		sizeof(WNDCLASSEX)
	);

	wndclassex.cbClsExtra = 0;
	wndclassex.cbWndExtra = 0;
	wndclassex.hbrBackground = reinterpret_cast<HBRUSH>(COLOR_WINDOW+1);
	wndclassex.hCursor = 0;
	wndclassex.hIcon = 0;
	wndclassex.hIconSm = 0;
	wndclassex.hInstance = windows::module_handle();
	wndclassex.lpfnWndProc = _proc;
	wndclassex.lpszClassName = class_name_.c_str();
	wndclassex.lpszMenuName = 0;
	wndclassex.cbSize = sizeof(WNDCLASSEX);
	wndclassex.style = 0;

	if(
		!::RegisterClassEx(
			&wndclassex
		)
	)
		throw awl::exception(
			FCPPT_TEXT("RegisterClassEx() failed!")
		);
}

awl::backends::windows::wndclass::~wndclass()
{
	::UnregisterClass(
		class_name_.c_str(),
		windows::module_handle()
	);
}

fcppt::string const &
awl::backends::windows::wndclass::name() const
{
	return class_name_;
}

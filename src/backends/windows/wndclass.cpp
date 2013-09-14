#include <awl/exception.hpp>
#include <awl/backends/windows/module_handle.hpp>
#include <awl/backends/windows/windows.hpp>
#include <awl/backends/windows/wndclass.hpp>
#include <fcppt/string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/assert/pre.hpp>
#include <fcppt/cast/size.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstring>
#include <fcppt/config/external_end.hpp>


awl::backends::windows::wndclass::wndclass()
:
	class_name_()
{
}

awl::backends::windows::wndclass::wndclass(
	fcppt::string const &_class_name,
	WNDPROC const _proc
)
:
	class_name_(
		_class_name
	)
{
	FCPPT_ASSERT_PRE(
		!class_name_.empty()
	);

	WNDCLASSEX wndclassex;

	std::memset(
		&wndclassex,
		0,
		sizeof(WNDCLASSEX)
	);

	wndclassex.cbClsExtra = 0;

	wndclassex.cbWndExtra = 0;

	wndclassex.hbrBackground =
		reinterpret_cast<
			HBRUSH
		>(
			COLOR_WINDOW + 1
		);

	wndclassex.hCursor = nullptr;

	wndclassex.hIcon = nullptr;

	wndclassex.hIconSm = nullptr;

	wndclassex.hInstance = awl::backends::windows::module_handle();

	wndclassex.lpfnWndProc = _proc;

	wndclassex.lpszClassName = class_name_.c_str();

	wndclassex.lpszMenuName = nullptr;

	wndclassex.cbSize =
		fcppt::cast::size<
			UINT
		>(
			sizeof(WNDCLASSEX)
		);

	wndclassex.style = 0;

	if(
		::RegisterClassEx(
			&wndclassex
		)
		== 0
	)
		throw awl::exception(
			FCPPT_TEXT("RegisterClassEx() failed!")
		);
}

awl::backends::windows::wndclass::wndclass(
	wndclass &&_other
)
:
	class_name_()
{
	_other.swap(
		*this
	);
}

awl::backends::windows::wndclass &
awl::backends::windows::wndclass::operator=(
	wndclass &&_other
)
{
	_other.swap(
		*this
	);

	return *this;
}

awl::backends::windows::wndclass::~wndclass()
{
	if(
		!class_name_.empty()
	)
		::UnregisterClass(
			class_name_.c_str(),
			awl::backends::windows::module_handle()
		);
}

fcppt::string const &
awl::backends::windows::wndclass::name() const
{
	return class_name_;
}

void
awl::backends::windows::wndclass::swap(
	wndclass &_other
)
{
	_other.class_name_.swap(
		class_name_
	);
}

void
awl::backends::windows::swap(
	awl::backends::windows::wndclass &_a,
	awl::backends::windows::wndclass &_b
)
{
	_a.swap(
		_b
	);
}

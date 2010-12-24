/*
spacegameengine is a portable easy to use game engine written in C++.
Copyright (C) 2006-2010 Carl Philipp Reh (sefi@s-e-f-i.de)

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/


#include <awl/backends/windows/wndclass.hpp>
#include <awl/backends/windows/windows.hpp>
#include <awl/backends/windows/module_handle.hpp>
#include <awl/exception.hpp>
#include <fcppt/text.hpp>

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

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


#ifndef AWL_BACKENDS_WINDOWS_WINDOW_INSTANCE_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_WINDOW_INSTANCE_HPP_INCLUDED

namespace awl
{
namespace backends
{
namespace windows
{

class window_instance
:
	public awl::window::instance
{
	FCPPT_NONCOPYABLE(
		window_instance
	)
public:
	SGE_SYMBOL window(
		awl::window::parameters const &,
		windows::wndclass &,
		windows::wndclass_remove_callback const &
	);

	SGE_SYMBOL ~window();

	SGE_SYMBOL void
	show();

	SGE_SYMBOL awl::window::dim const
	size() const;

	SGE_SYMBOL HWND
	hwnd() const;
private:
	typedef fcppt::math::box::rect<
		LONG
	>::type decoration_rect;

	decoration_rect decoration_size_;

	HWND handle_;

	windows::wndclass_remove_callback const remove_wndclass_;
};

}
}
}

#endif

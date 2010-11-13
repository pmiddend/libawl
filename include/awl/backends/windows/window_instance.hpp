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

#include <awl/backends/windows/window_instance_fwd.hpp>
#include <sge/windows/callback_return_type.hpp>
#include <sge/windows/event_type.hpp>
#include <sge/windows/windows.hpp>
#include <sge/windows/wndclass_ptr.hpp>
#include <sge/window/instance.hpp>
#include <sge/symbol.hpp>
#include <fcppt/signal/auto_connection.hpp>
#include <fcppt/signal/object.hpp>
#include <fcppt/math/box/rect.hpp>
#include <fcppt/math/box/basic_decl.hpp>
#include <fcppt/function/object.hpp>
#include <fcppt/string.hpp>
#include <fcppt/optional_fwd.hpp>
#include <fcppt/noncopyable.hpp>
#include <boost/ptr_container/ptr_map.hpp>

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
		dim_type const &,
		fcppt::string const &title,
		fcppt::string const &class_name
	);

	SGE_SYMBOL ~window();

	SGE_SYMBOL void
	show();

	SGE_SYMBOL awl::window::dim const
	size() const;

	SGE_SYMBOL HWND
	hwnd() const;
private:
	windows::wndclass_ptr const wndclass_;

	typedef fcppt::math::box::rect<
		LONG
	>::type decoration_rect;

	decoration_rect decoration_size_;

	HWND handle_;

};

}
}
}

#endif

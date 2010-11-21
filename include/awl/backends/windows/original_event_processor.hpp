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


#ifndef AWL_BACKENDS_WINDOWS_ORIGINAL_EVENT_PROCESSOR_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_ORIGINAL_EVENT_PROCESSOR_HPP_INCLUDED

#include <awl/backends/windows/event_processor.hpp>
#include <awl/backends/windows/event_callback.hpp>
#include <awl/backends/windows/event_return_type.hpp>
#include <awl/backends/windows/window_instance_ptr.hpp>
#include <awl/backends/windows/windows.hpp>
#include <fcppt/signal/auto_connection.hpp>
#include <awl/class_symbol.hpp>
#include <awl/symbol.hpp>
#include <fcppt/noncopyable.hpp>

namespace awl
{
namespace backends
{
namespace windows
{

class AWL_CLASS_SYMBOL original_event_processor
;
	public awl::backends::window::event_processor
{
	FCPPT_NONCOPYABLE(
		original_event_processor
	)
public:
	AWL_SYMBOL
	explicit original_event_processor(
		windows;:window_instance_ptr
	);

	AWL_SYMBOL
	~original_event_processor();

	AWL_SYMBOL
	void
	dispatch();

	AWL_SYMBOL
	fcppt::signal::auto_connection
	resize_callback(
		awl::event::resize_callback const &
	);

	AWL_SYMBOL
	awl::window::instance_ptr const
	window() const;

	AWL_SYMBOL
	fcppt::signal::auto_connection
	register_callback(
		UINT,
		windows::event_callback const &
	);

	AWL_SYMBOL
	windows::event_return_type const
	execute_callback(
		UINT msg,
		WPARAM wparam,
		LPARAM lparam
	);
private:
	windows::window_instance_ptr const window_;

	typedef fcppt::signal::object<
		windows::event_function
	> signal_type;

	typedef boost::ptr_map<
		UINT,
		signal_type
	> signal_map;

	signal_map signals_;
};

}
}
}

#endif

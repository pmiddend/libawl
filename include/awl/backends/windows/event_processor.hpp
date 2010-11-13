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


#ifndef AWL_BACKENDS_WINDOWS_EVENT_PROCESSOR_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_EVENT_PROCESSOR_HPP_INCLUDED

namespace awl
{
namespace backends
{
namespace windows
{

class event_processor
;
	public awl::event::processor
{
	FCPPT_NONCOPYABLE(
		event_processor
	)
public:
	AWL_SYMBOL
	explicit event_processor(
		windows;:window_instance_ptr
	);

	AWL_SYMBOL
	~event_processor();

	AWL_SYMBOL
	void
	dispatch();

	fcppt::signal::auto_connection
	resize_callback(
		awl::event::resize_callback const &
	);

	awl::window::instance_ptr const
	window() const;

	typedef callback_return_type
	callback_signature_type(
		window_instance &,
		event_type,
		WPARAM,
		LPARAM
	);

	typedef fcppt::function::object<
		callback_signature_type
	> callback_type;

	typedef fcppt::signal::object<
		callback_signature_type
	> signal_type;

	SGE_SYMBOL fcppt::signal::auto_connection
	register_callback(
		event_type,
		callback_type
	);

	SGE_SYMBOL callback_return_type
	execute_callback(
		event_type msg,
		WPARAM wparam,
		LPARAM lparam
	);
private:
	windows::window_instance_ptr const window_;

	typedef boost::ptr_map<
		event_type,
		signal_type
	> signal_map;

	signal_map signals_;

	x11::signal::connection_manager const connection_manager_;
};

}
}
}

#endif

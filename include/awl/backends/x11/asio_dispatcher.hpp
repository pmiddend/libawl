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


#ifndef AWL_BACKENDS_X11_ASIO_DISPATCHER_HPP_INCLUDED
#define AWL_BACKENDS_X11_ASIO_DISPATCHER_HPP_INCLUDED

#include <awl/mainloop/dispatcher.hpp>
#include <awl/mainloop/dispatcher_callback.hpp>
#include <awl/symbol.hpp>
#include <fcppt/function/object.hpp>
#include <fcppt/noncopyable.hpp>
#include <boost/asio/posix/stream_descriptor.hpp>
#include <boost/asio/io_service.hpp>
#include <boost/system/error_code.hpp>

namespace awl
{
namespace backends
{
namespace x11
{

class asio_dispatcher
:
	public mainloop::dispatcher
{
	FCPPT_NONCOPYABLE(
		asio_dispatcher
	)
public:
	AWL_SYMBOL
	explicit asio_dispatcher(	
		boost::asio::io_service &,
		int fd,
		awl::mainloop::dispatcher_callback const &
	);

	AWL_SYMBOL
	~asio_dispatcher();
private:
	void
	register_handler();

	void
	callback(
		boost::system::error_code const &
	);

	boost::asio::posix::stream_descriptor stream_wrapper_;

	awl::mainloop::dispatcher_callback const callback_;
};

}
}
}

#endif

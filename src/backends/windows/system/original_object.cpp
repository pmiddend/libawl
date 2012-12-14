#include <awl/backends/windows/counted_wndclass.hpp>
#include <awl/backends/windows/default_wnd_proc.hpp>
#include <awl/backends/windows/get_focus.hpp>
#include <awl/backends/windows/system/original_object.hpp>
#include <awl/backends/windows/visual/null_object.hpp>
#include <awl/backends/windows/window/original_object.hpp>
#include <awl/visual/object_unique_ptr.hpp>
#include <awl/window/object_unique_ptr.hpp>
#include <awl/window/parameters.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/string.hpp>
#include <fcppt/container/ptr/insert_unique_ptr_map.hpp>
#include <fcppt/config/external_begin.hpp>
#include <functional>
#include <fcppt/config/external_end.hpp>


awl::backends::windows::system::original_object::original_object()
:
	wndclasses_()
{
}

awl::backends::windows::system::original_object::~original_object()
{
}

awl::window::object_unique_ptr
awl::backends::windows::system::original_object::create_window(
	awl::window::parameters const &_param
)
{
	awl::backends::windows::system::original_object::wndclass_map::iterator wndclass_it(
		wndclasses_.find(
			_param.class_name()
		)
	);

	if(
		wndclass_it == wndclasses_.end()
	)
		wndclass_it =
			fcppt::container::ptr::insert_unique_ptr_map(
				wndclasses_,
				_param.class_name(),
				fcppt::make_unique_ptr<
					awl::backends::windows::counted_wndclass
				>(
					_param.class_name(),
					awl::backends::windows::default_wnd_proc
				)
			).first;
	else
		wndclass_it->second->add_ref();

	return
		awl::window::object_unique_ptr(
			fcppt::make_unique_ptr<
				awl::backends::windows::window::original_object
			>(
				_param,
				wndclass_it->second->wndclass(),
				std::bind(
					&awl::backends::windows::system::original_object::unregister_wndclass,
					this,
					_param.class_name()
				)
			)
		);
}

awl::visual::object_unique_ptr
awl::backends::windows::system::original_object::default_visual()
{
	return
		awl::visual::object_unique_ptr(
			fcppt::make_unique_ptr<
				awl::backends::windows::visual::null_object
			>()
		);
}

awl::window::object_unique_ptr
awl::backends::windows::system::original_object::focus_window()
{
	return
		awl::window::object_unique_ptr(
			awl::backends::windows::get_focus()
		);
}

void
awl::backends::windows::system::original_object::unregister_wndclass(
	fcppt::string const &_class_name
)
{
	awl::backends::windows::system::original_object::wndclass_map::iterator const wndclass_it(
		wndclasses_.find(
			_class_name
		)
	);

	if(
		wndclass_it->second->release() == 0u
	)
		wndclasses_.erase(
			wndclass_it
		);
}

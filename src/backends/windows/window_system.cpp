#include <awl/backends/windows/window_system.hpp>
#include <awl/backends/windows/default_wnd_proc.hpp>
#include <awl/backends/windows/counted_wndclass.hpp>
#include <awl/backends/windows/original_window_instance.hpp>
#include <awl/window/parameters.hpp>
#include <fcppt/container/ptr/insert_unique_ptr_map.hpp>
#include <fcppt/tr1/functional.hpp>
#include <fcppt/make_shared_ptr.hpp>
#include <fcppt/make_unique_ptr.hpp>

awl::backends::windows::window_system::window_system()
{
}

awl::backends::windows::window_system::~window_system()
{
}

awl::window::instance_ptr const
awl::backends::windows::window_system::create(
	awl::window::parameters const &_param
)
{
	wndclass_map::iterator wndclass_it(
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
					windows::counted_wndclass
				>(
					_param.class_name(),
					windows::default_wnd_proc
				)
			).first;
	else
		wndclass_it->second->add_ref();
	
	return
		fcppt::make_shared_ptr<
			awl::backends::windows::original_window_instance
		>(
			_param,
			std::tr1::ref(
				wndclass_it->second->wndclass()
			),
			std::tr1::bind(
				&window_system::unregister_wndclass,
				this,
				_param.class_name()
			)
		);
}

void
awl::backends::windows::window_system::unregister_wndclass(
	fcppt::string const &_class_name
)
{
	wndclass_map::iterator const wndclass_it(
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

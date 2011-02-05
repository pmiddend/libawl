#include <awl/backends/x11/window/original_class_hint.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/text.hpp>
#include <fcppt/to_std_string.hpp>
#include <awl/exception.hpp>

class awl::backends::x11::window::original_class_hint::impl
{
public:
	FCPPT_NONCOPYABLE(
		impl
	);
public:
	impl();

	~impl();

	XClassHint *
	get() const;
private:
	XClassHint *const hint_;
};


awl::backends::x11::window::original_class_hint::original_class_hint(
	fcppt::string const &_res_name,
	fcppt::string const &_res_class
)
:
	awl::backends::x11::window::class_hint(),
	impl_(
		fcppt::make_unique_ptr<
			impl
		>()
	),
	res_name_(
		fcppt::to_std_string(
			_res_name
		)
	),
	res_class_(
		fcppt::to_std_string(
			_res_class
		)
	)
{
	XClassHint *const hint(
		get()
	);

	hint->res_name =
		const_cast<
			char *
		>(
			res_name_.c_str()
		);

	hint->res_class =
		const_cast<
			char *
		>(
			res_class_.c_str()
		);
}

awl::backends::x11::window::original_class_hint::~original_class_hint()
{
}

XClassHint *
awl::backends::x11::window::original_class_hint::get() const
{
	return impl_->get();
}

std::string const
awl::backends::x11::window::original_class_hint::res_name() const
{
	return res_name_;
}

std::string const
awl::backends::x11::window::original_class_hint::res_class() const
{
	return res_class_;
}

awl::backends::x11::window::original_class_hint::impl::impl()
:
	hint_(
		::XAllocClassHint()
	)
{
	if(
		!hint_
	)
		throw awl::exception(
			FCPPT_TEXT("XAllocClassHint() failed!")
		);
}

awl::backends::x11::window::original_class_hint::impl::~impl()
{
	::XFree(
		hint_
	);
}

XClassHint *
awl::backends::x11::window::original_class_hint::impl::get() const
{
	return hint_;
}

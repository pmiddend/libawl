#include <awl/backends/x11/class_hint.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/text.hpp>
#include <fcppt/to_std_string.hpp>
#include <awl/exception.hpp>

class awl::backends::x11::class_hint::impl
{
public:
	FCPPT_NONCOPYABLE(impl)
public:
	impl();
	~impl();
	XClassHint *get() const;
private:
	XClassHint *const hint;
};


awl::backends::x11::class_hint::class_hint(
	fcppt::string const &app_name_,
	fcppt::string const &res_name_
)
:
	impl_(
		new impl()
	),
	app_name(
		fcppt::to_std_string(
			app_name_
		)
	),
	res_name(
		fcppt::to_std_string(
			res_name_
		)
	)
{
	XClassHint *const hint(
		get()
	);

	hint->res_name = const_cast<char *>(app_name.c_str());
	hint->res_class = const_cast<char *>(res_name.c_str());
}

awl::backends::x11::class_hint::~class_hint()
{}

XClassHint *
awl::backends::x11::class_hint::get() const
{
	return impl_->get();
}

awl::backends::x11::class_hint::impl::impl()
:
	hint(
		XAllocClassHint()
	)
{
	if(!hint)
		throw exception(
			FCPPT_TEXT("XAllocClassHint() failed!")
		);
}

awl::backends::x11::class_hint::impl::~impl()
{
	XFree(hint);
}

XClassHint *
awl::backends::x11::class_hint::impl::get() const
{
	return hint;
}

#include <awl/cursor/const_optional_object_ref.hpp>
#include <awl/visual/object_fwd.hpp>
#include <awl/window/dim.hpp>
#include <awl/window/optional_dim.hpp>
#include <awl/window/optional_pos.hpp>
#include <awl/window/parameters.hpp>
#include <awl/window/pos.hpp>
#include <fcppt/string.hpp>


awl::window::parameters::parameters(
	awl::visual::object const &_visual
)
:
	visual_(
		_visual
	),
	position_(),
	size_(),
	exact_size_hint_(),
	minimum_size_hint_(),
	maximum_size_hint_(),
	title_(),
	class_name_(),
	cursor_()
{
}

awl::window::parameters &
awl::window::parameters::position(
	awl::window::pos const &_position
)
{
	position_ = _position;

	return *this;
}

awl::window::parameters &
awl::window::parameters::size(
	awl::window::dim const &_size
)
{
	size_ = _size;

	return *this;
}

awl::window::parameters &
awl::window::parameters::exact_size_hint(
	awl::window::dim const &_exact_size_hint
)
{
	exact_size_hint_ = _exact_size_hint;

	return *this;
}

awl::window::parameters &
awl::window::parameters::minimum_size_hint(
	awl::window::dim const &_minimum_size_hint
)
{
	minimum_size_hint_ = _minimum_size_hint;

	return *this;
}

awl::window::parameters &
awl::window::parameters::maximum_size_hint(
	awl::window::dim const &_maximum_size_hint
)
{
	maximum_size_hint_ = _maximum_size_hint;

	return *this;
}

awl::window::parameters &
awl::window::parameters::title(
	fcppt::string const &_title
)
{
	title_ = _title;

	return *this;
}

awl::window::parameters &
awl::window::parameters::class_name(
	fcppt::string const &_class_name
)
{
	class_name_ = _class_name;

	return *this;
}

awl::window::parameters &
awl::window::parameters::cursor(
	awl::cursor::const_optional_object_ref const &_cursor
)
{
	cursor_ = _cursor;

	return *this;
}

awl::visual::object const &
awl::window::parameters::visual() const
{
	return visual_;
}

awl::window::optional_pos const
awl::window::parameters::position() const
{
	return position_;
}

awl::window::optional_dim const
awl::window::parameters::size() const
{
	return size_;
}

awl::window::optional_dim const
awl::window::parameters::exact_size_hint() const
{
	return exact_size_hint_;
}

awl::window::optional_dim const
awl::window::parameters::minimum_size_hint() const
{
	return minimum_size_hint_;
}

awl::window::optional_dim const
awl::window::parameters::maximum_size_hint() const
{
	return maximum_size_hint_;
}

fcppt::string const
awl::window::parameters::title() const
{
	return title_;
}

fcppt::string const
awl::window::parameters::class_name() const
{
	return class_name_;
}

awl::cursor::const_optional_object_ref const &
awl::window::parameters::cursor() const
{
	return cursor_;
}

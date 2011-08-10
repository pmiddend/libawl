#include <awl/window/parameters.hpp>

awl::window::parameters::parameters()
:
	position_(),
	size_(),
	exact_size_hint_(),
	minimum_size_hint_(),
	maximum_size_hint_(),
	title_(),
	class_name_(),
	has_opengl_(
		false
	),
	bit_depth_(),
	stencil_buffer_(),
	depth_buffer_()
{
}

awl::window::parameters &
awl::window::parameters::position(
	window::vector const &_position
)
{
	position_ = _position;

	return *this;
}

awl::window::parameters &
awl::window::parameters::size(
	dim const &_size
)
{
	size_ = _size;

	return *this;
}

awl::window::parameters &
awl::window::parameters::exact_size_hint(
	dim const &_exact_size_hint
)
{
	exact_size_hint_ = _exact_size_hint;

	return *this;
}

awl::window::parameters &
awl::window::parameters::minimum_size_hint(
	dim const &_minimum_size_hint
)
{
	minimum_size_hint_ = _minimum_size_hint;

	return *this;
}

awl::window::parameters &
awl::window::parameters::maximum_size_hint(
	dim const &_maximum_size_hint
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
awl::window::parameters::has_opengl(
	bool const _has_opengl
)
{
	has_opengl_ = _has_opengl;

	return *this;
}

awl::window::parameters &
awl::window::parameters::bit_depth(
	awl::window::bit_depth::type const _bit_depth
)
{
	bit_depth_ = _bit_depth;

	return *this;
}

awl::window::parameters &
awl::window::parameters::stencil_buffer(
	awl::window::stencil_buffer::type const _stencil_buffer
)
{
	stencil_buffer_ = _stencil_buffer;

	return *this;
}

awl::window::parameters &
awl::window::parameters::depth_buffer(
	awl::window::depth_buffer::type const _depth_buffer
)
{
	depth_buffer_ = _depth_buffer;

	return *this;
}

awl::window::optional_position const
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

bool
awl::window::parameters::has_opengl() const
{
	return has_opengl_;
}

fcppt::optional<awl::window::bit_depth::type> const
awl::window::parameters::bit_depth() const
{
	return bit_depth_;
}

fcppt::optional<awl::window::stencil_buffer::type> const
awl::window::parameters::stencil_buffer() const
{
	return stencil_buffer_;
}

fcppt::optional<awl::window::depth_buffer::type> const
awl::window::parameters::depth_buffer() const
{
	return depth_buffer_;
}

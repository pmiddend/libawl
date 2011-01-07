#include <awl/window/parameters.hpp>

awl::window::parameters::parameters()
:
	has_opengl_(
		false)
{
}

awl::window::parameters &
awl::window::parameters::position(
	vector const &v)
{
	position_ = v;

	return *this;
}

awl::window::parameters &
awl::window::parameters::size(
	dim const &v)
{
	size_ = v;

	return *this;
}

awl::window::parameters &
awl::window::parameters::title(
	fcppt::string const &v)
{
	title_ = v;

	return *this;
}

awl::window::parameters &
awl::window::parameters::class_name(
	fcppt::string const &v)
{
	class_name_ = v;

	return *this;
}

awl::window::parameters &
awl::window::parameters::has_opengl(
	bool const _has_opengl)
{
	has_opengl_ = _has_opengl;

	return *this;
}

awl::window::parameters &
awl::window::parameters::bit_depth(
	awl::window::bit_depth::type const t)
{
	bit_depth_ = t;

	return *this;
}

awl::window::parameters &
awl::window::parameters::stencil_buffer(
	awl::window::stencil_buffer::type const t)
{
	stencil_buffer_ = t;

	return *this;
}

awl::window::parameters &
awl::window::parameters::depth_buffer(
	awl::window::depth_buffer::type const t)
{
	depth_buffer_ = t;

	return *this;
}

fcppt::optional<awl::window::vector> const
awl::window::parameters::position() const
{
	return position_;
}

fcppt::optional<awl::window::dim> const
awl::window::parameters::size() const
{
	return size_;
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

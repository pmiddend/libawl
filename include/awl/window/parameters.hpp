#ifndef AWL_WINDOW_PARAMETERS_HPP_INCLUDED
#define AWL_WINDOW_PARAMETERS_HPP_INCLUDED

#include <awl/window/vector.hpp>
#include <awl/window/dim.hpp>
#include <awl/window/bit_depth.hpp>
#include <awl/window/stencil_buffer.hpp>
#include <awl/window/depth_buffer.hpp>
#include <fcppt/math/vector/basic_impl.hpp>
#include <fcppt/math/dim/basic_impl.hpp>
#include <fcppt/optional.hpp>
#include <fcppt/string.hpp>

namespace awl
{
namespace window
{
class parameters
{
public:
	explicit 
	parameters();

	void
	position(
		vector const &);

	void
	size(
		dim const &);

	void
	title(
		fcppt::string const &);

	void
	class_name(
		fcppt::string const &);

	void
	fullscreen(
		bool);

	void
	has_opengl(
		bool);

	void
	bit_depth(
		awl::window::bit_depth::type);

	void
	stencil_buffer(
		awl::window::stencil_buffer::type);

	void
	depth_buffer(
		awl::window::depth_buffer::type);

	fcppt::optional<vector> const
	position() const;

	fcppt::optional<dim> const
	size() const;

	fcppt::string const
	title() const;

	fcppt::string const
	class_name() const;

	bool
	fullscreen() const;

	bool
	has_opengl() const;

	fcppt::optional<awl::window::bit_depth::type> const
	bit_depth() const;

	fcppt::optional<awl::window::stencil_buffer::type> const
	stencil_buffer() const;

	fcppt::optional<awl::window::depth_buffer::type> const
	depth_buffer() const;
private:
	fcppt::optional<vector> position_;
	fcppt::optional<dim> size_;
	fcppt::string title_,class_name_;
	bool fullscreen_;
	bool has_opengl_;
	fcppt::optional<awl::window::bit_depth::type> bit_depth_;
	fcppt::optional<awl::window::stencil_buffer::type> stencil_buffer_;
	fcppt::optional<awl::window::depth_buffer::type> depth_buffer_;
};
}
}

#endif

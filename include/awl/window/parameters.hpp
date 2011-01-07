#ifndef AWL_WINDOW_PARAMETERS_HPP_INCLUDED
#define AWL_WINDOW_PARAMETERS_HPP_INCLUDED

#include <awl/window/vector.hpp>
#include <awl/window/dim.hpp>
#include <awl/window/bit_depth.hpp>
#include <awl/window/stencil_buffer.hpp>
#include <awl/window/depth_buffer.hpp>
#include <awl/symbol.hpp>
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
	AWL_SYMBOL
	explicit 
	parameters();

	AWL_SYMBOL
	parameters &	
	position(
		vector const &);

	AWL_SYMBOL
	parameters &	
	size(
		dim const &);

	AWL_SYMBOL
	parameters &	
	title(
		fcppt::string const &);

	AWL_SYMBOL
	parameters &	
	class_name(
		fcppt::string const &);

	AWL_SYMBOL
	parameters &	
	has_opengl(
		bool);

	AWL_SYMBOL
	parameters &	
	bit_depth(
		awl::window::bit_depth::type);

	AWL_SYMBOL
	parameters &	
	stencil_buffer(
		awl::window::stencil_buffer::type);

	AWL_SYMBOL
	parameters &	
	depth_buffer(
		awl::window::depth_buffer::type);

	AWL_SYMBOL
	fcppt::optional<vector> const
	position() const;

	AWL_SYMBOL
	fcppt::optional<dim> const
	size() const;

	AWL_SYMBOL
	fcppt::string const
	title() const;

	AWL_SYMBOL
	fcppt::string const
	class_name() const;

	AWL_SYMBOL
	bool
	has_opengl() const;

	AWL_SYMBOL
	fcppt::optional<awl::window::bit_depth::type> const
	bit_depth() const;

	AWL_SYMBOL
	fcppt::optional<awl::window::stencil_buffer::type> const
	stencil_buffer() const;

	AWL_SYMBOL
	fcppt::optional<awl::window::depth_buffer::type> const
	depth_buffer() const;
private:
	fcppt::optional<vector> position_;
	fcppt::optional<dim> size_;
	fcppt::string title_,class_name_;
	bool has_opengl_;
	fcppt::optional<awl::window::bit_depth::type> bit_depth_;
	fcppt::optional<awl::window::stencil_buffer::type> stencil_buffer_;
	fcppt::optional<awl::window::depth_buffer::type> depth_buffer_;
};
}
}

#endif

#ifndef AWL_WINDOW_PARAMETERS_HPP_INCLUDED
#define AWL_WINDOW_PARAMETERS_HPP_INCLUDED

#include <awl/window/parameters_fwd.hpp>
#include <awl/window/bit_depth.hpp>
#include <awl/window/depth_buffer.hpp>
#include <awl/window/dim.hpp>
#include <awl/window/optional_dim.hpp>
#include <awl/window/optional_position.hpp>
#include <awl/window/stencil_buffer.hpp>
#include <awl/window/vector.hpp>
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
	parameters();

	AWL_SYMBOL
	parameters &
	position(
		vector const &
	);

	AWL_SYMBOL
	parameters &
	size(
		dim const &
	);

	AWL_SYMBOL
	parameters &
	exact_size_hint(
		dim const &
	);

	AWL_SYMBOL
	parameters &
	minimum_size_hint(
		dim const &
	);

	AWL_SYMBOL
	parameters &
	maximum_size_hint(
		dim const &
	);

	AWL_SYMBOL
	parameters &
	title(
		fcppt::string const &
	);

	AWL_SYMBOL
	parameters &
	class_name(
		fcppt::string const &
	);

	AWL_SYMBOL
	parameters &
	has_opengl(
		bool
	);

	AWL_SYMBOL
	parameters &
	bit_depth(
		awl::window::bit_depth::type
	);

	AWL_SYMBOL
	parameters &
	stencil_buffer(
		awl::window::stencil_buffer::type
	);

	AWL_SYMBOL
	parameters &
	depth_buffer(
		awl::window::depth_buffer::type
	);

	AWL_SYMBOL
	window::optional_position const
	position() const;

	AWL_SYMBOL
	window::optional_dim const
	size() const;

	AWL_SYMBOL
	window::optional_dim const
	exact_size_hint() const;

	AWL_SYMBOL
	window::optional_dim const
	minimum_size_hint() const;

	AWL_SYMBOL
	window::optional_dim const
	maximum_size_hint() const;

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
	window::optional_position position_;

	window::optional_dim size_;

	window::optional_dim exact_size_hint_;

	window::optional_dim minimum_size_hint_;

	window::optional_dim maximum_size_hint_;

	fcppt::string title_;

	fcppt::string class_name_;

	bool has_opengl_;

	fcppt::optional<awl::window::bit_depth::type> bit_depth_;

	fcppt::optional<awl::window::stencil_buffer::type> stencil_buffer_;

	fcppt::optional<awl::window::depth_buffer::type> depth_buffer_;
};

}
}

#endif

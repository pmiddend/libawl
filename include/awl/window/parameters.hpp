#ifndef AWL_WINDOW_PARAMETERS_HPP_INCLUDED
#define AWL_WINDOW_PARAMETERS_HPP_INCLUDED

#include <awl/visual/object_fwd.hpp>
#include <awl/window/dim_fwd.hpp>
#include <awl/window/optional_dim.hpp>
#include <awl/window/optional_position.hpp>
#include <awl/window/parameters_fwd.hpp>
#include <awl/window/vector_fwd.hpp>
#include <awl/symbol.hpp>
#include <fcppt/nonassignable.hpp>
#include <fcppt/string.hpp>


namespace awl
{
namespace window
{

class parameters
{
	FCPPT_NONASSIGNABLE(
		parameters
	);
public:
	AWL_SYMBOL
	explicit
	parameters(
		awl::visual::object const &
	);

	AWL_SYMBOL
	awl::window::parameters &
	position(
		awl::window::vector const &
	);

	AWL_SYMBOL
	awl::window::parameters &
	size(
		awl::window::dim const &
	);

	AWL_SYMBOL
	awl::window::parameters &
	exact_size_hint(
		awl::window::dim const &
	);

	AWL_SYMBOL
	awl::window::parameters &
	minimum_size_hint(
		awl::window::dim const &
	);

	AWL_SYMBOL
	awl::window::parameters &
	maximum_size_hint(
		awl::window::dim const &
	);

	AWL_SYMBOL
	awl::window::parameters &
	title(
		fcppt::string const &
	);

	AWL_SYMBOL
	awl::window::parameters &
	class_name(
		fcppt::string const &
	);

	AWL_SYMBOL
	awl::visual::object const &
	visual() const;

	AWL_SYMBOL
	awl::window::optional_position const
	position() const;

	AWL_SYMBOL
	awl::window::optional_dim const
	size() const;

	AWL_SYMBOL
	awl::window::optional_dim const
	exact_size_hint() const;

	AWL_SYMBOL
	awl::window::optional_dim const
	minimum_size_hint() const;

	AWL_SYMBOL
	awl::window::optional_dim const
	maximum_size_hint() const;

	AWL_SYMBOL
	fcppt::string const
	title() const;

	AWL_SYMBOL
	fcppt::string const
	class_name() const;
private:
	awl::visual::object const &visual_;

	awl::window::optional_position position_;

	awl::window::optional_dim size_;

	awl::window::optional_dim exact_size_hint_;

	awl::window::optional_dim minimum_size_hint_;

	awl::window::optional_dim maximum_size_hint_;

	fcppt::string title_;

	fcppt::string class_name_;
};

}
}

#endif

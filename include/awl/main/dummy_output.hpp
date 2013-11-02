#ifndef AWL_MAIN_DUMMY_OUTPUT_HPP_INCLUDED
#define AWL_MAIN_DUMMY_OUTPUT_HPP_INCLUDED

#include <awl/symbol.hpp>
#include <awl/main/output.hpp>
#include <fcppt/noncopyable.hpp>


namespace awl
{
namespace main
{

class dummy_output
:
	public awl::main::output
{
	FCPPT_NONCOPYABLE(
		dummy_output
	);
public:
	AWL_SYMBOL
	dummy_output();

	AWL_SYMBOL
	~dummy_output()
	override;
};

}
}

#endif

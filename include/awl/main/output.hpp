#ifndef AWL_MAIN_OUTPUT_HPP_INCLUDED
#define AWL_MAIN_OUTPUT_HPP_INCLUDED

#include <awl/symbol.hpp>
#include <awl/main/output_fwd.hpp>
#include <fcppt/class_symbol.hpp>
#include <fcppt/noncopyable.hpp>


namespace awl
{
namespace main
{

class FCPPT_CLASS_SYMBOL output
{
	FCPPT_NONCOPYABLE(
		output
	);
protected:
	AWL_SYMBOL
	output();
public:
	AWL_SYMBOL
	virtual
	~output() = 0;
};

}
}

#endif

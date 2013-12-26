#ifndef AWL_MAIN_SCOPED_OUTPUT_UNIQUE_PTR_HPP_INCLUDED
#define AWL_MAIN_SCOPED_OUTPUT_UNIQUE_PTR_HPP_INCLUDED

#include <awl/main/scoped_output_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <memory>
#include <fcppt/config/external_end.hpp>


namespace awl
{
namespace main
{

typedef
std::unique_ptr<
	awl::main::scoped_output
>
scoped_output_unique_ptr;

}
}

#endif

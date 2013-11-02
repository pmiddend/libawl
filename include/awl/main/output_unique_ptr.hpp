#ifndef AWL_MAIN_OUTPUT_UNIQUE_PTR_HPP_INCLUDED
#define AWL_MAIN_OUTPUT_UNIQUE_PTR_HPP_INCLUDED

#include <awl/main/output_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <memory>
#include <fcppt/config/external_end.hpp>


namespace awl
{
namespace main
{

typedef
std::unique_ptr<
	awl::main::output
>
output_unique_ptr;

}
}

#endif

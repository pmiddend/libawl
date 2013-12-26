#ifndef AWL_MAIN_SCOPED_OUTPUT_SCOPED_PTR_HPP_INCLUDED
#define AWL_MAIN_SCOPED_OUTPUT_SCOPED_PTR_HPP_INCLUDED

#include <awl/main/scoped_output_fwd.hpp>
#include <fcppt/scoped_ptr_impl.hpp>


namespace awl
{
namespace main
{

typedef
fcppt::scoped_ptr<
	awl::main::scoped_output
>
scoped_output_scoped_ptr;

}
}

#endif

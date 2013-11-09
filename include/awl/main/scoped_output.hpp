#ifndef AWL_MAIN_SCOPED_OUTPUT_HPP_INCLUDED
#define AWL_MAIN_SCOPED_OUTPUT_HPP_INCLUDED

#include <awl/symbol.hpp>
#include <awl/main/output_fwd.hpp>
#include <awl/main/scoped_output_fwd.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/scoped_ptr_impl.hpp>
#include <fcppt/io/ostream.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/filesystem/path.hpp>
#include <fcppt/config/external_end.hpp>


namespace awl
{
namespace main
{

class scoped_output
{
	FCPPT_NONCOPYABLE(
		scoped_output
	);
public:
	AWL_SYMBOL
	scoped_output(
		fcppt::io::ostream &,
		boost::filesystem::path const &
	);

	AWL_SYMBOL
	~scoped_output();
private:
	fcppt::scoped_ptr<
		awl::main::output
	> const impl_;
};

}
}

#endif

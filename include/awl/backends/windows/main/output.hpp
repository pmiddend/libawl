#ifndef AWL_BACKENDS_WINDOWS_MAIN_OUTPUT_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_MAIN_OUTPUT_HPP_INCLUDED

#include <awl/symbol.hpp>
#include <awl/main/output.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/io/ofstream.hpp>
#include <fcppt/io/ostream.hpp>
#include <fcppt/io/scoped_rdbuf.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/filesystem/path.hpp>
#include <fcppt/config/external_end.hpp>


namespace awl
{
namespace backends
{
namespace windows
{
namespace main
{

class output
:
	public awl::main::output
{
	FCPPT_NONCOPYABLE(
		output
	);
public:
	AWL_SYMBOL
	output(
		fcppt::io::ostream &,
		boost::filesystem::path const &
	);

	AWL_SYMBOL
	~output()
	override;
private:
	fcppt::io::ofstream stream_;

	fcppt::io::scoped_rdbuf const scoped_rdbuf_;
};

}
}
}
}

#endif

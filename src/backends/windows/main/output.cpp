#include <awl/exception.hpp>
#include <awl/backends/windows/main/output.hpp>
#include <awl/main/output.hpp>
#include <fcppt/text.hpp>
#include <fcppt/filesystem/path_to_string.hpp>
#include <fcppt/io/ostream.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/filesystem/path.hpp>
#include <fcppt/config/external_end.hpp>


awl::backends::windows::main::output::output(
	fcppt::io::ostream &_stream,
	boost::filesystem::path const &_path
)
:
	awl::main::output(),
	stream_(
		_path
	),
	scoped_rdbuf_(
		stream_,
		_stream
	)
{
	if(
		!stream_.is_open()
	)
		throw
			awl::exception(
				FCPPT_TEXT("Failed to open ")
				+
				fcppt::filesystem::path_to_string(
					_path
				)
			);
}

awl::backends::windows::main::output::~output()
{
}

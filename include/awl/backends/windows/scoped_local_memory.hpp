#ifndef AWL_BACKENDS_WINDOWS_SCOPED_LOCAL_MEMORY_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_SCOPED_LOCAL_MEMORY_HPP_INCLUDED

#include <awl/symbol.hpp>
#include <awl/backends/windows/windows.hpp>
#include <fcppt/noncopyable.hpp>


namespace awl
{
namespace backends
{
namespace windows
{

class scoped_local_memory
{
	FCPPT_NONCOPYABLE(
		scoped_local_memory
	);
public:
	AWL_SYMBOL
	explicit
	scoped_local_memory(
		HLOCAL
	);

	AWL_SYMBOL
	~scoped_local_memory();
private:
	HLOCAL const memory_;
};

}
}
}

#endif

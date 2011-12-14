#include <awl/backends/windows/local_free.hpp>
#include <awl/backends/windows/scoped_local_memory.hpp>
#include <awl/backends/windows/windows.hpp>


awl::backends::windows::scoped_local_memory::scoped_local_memory(
	HLOCAL const _memory
)
:
	memory_(
		_memory
	)
{
}

awl::backends::windows::scoped_local_memory::~scoped_local_memory()
{
	awl::backends::windows::local_free(
		memory_
	);
}

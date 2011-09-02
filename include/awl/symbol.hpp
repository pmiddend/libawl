#ifndef AWL_SYMBOL_HPP_INCLUDED
#define AWL_SYMBOL_HPP_INCLUDED

#include <fcppt/config/compiler.hpp>

#if defined(FCPPT_CONFIG_MSVC_COMPILER)
#	if defined(awl_EXPORTS) && defined(AWL_DYN_LINK)
#		error "awl_EXPORTS and AWL_DYN_LINK defined"
#	endif
#	if defined(awl_EXPORTS)
#		include <fcppt/export_symbol.hpp>
#		define AWL_SYMBOL FCPPT_EXPORT_SYMBOL
#	elif defined(AWL_DYN_LINK)
#		include <fcppt/import_symbol.hpp>
#		define AWL_SYMBOL FCPPT_IMPORT_SYMBOL
#	else
#		define AWL_SYMBOL
#	endif
#elif defined(FCPPT_CONFIG_GCC_COMPILER)
#	include <fcppt/export_symbol.hpp>
#	define AWL_SYMBOL FCPPT_EXPORT_SYMBOL
#else
#	error "Don't know what AWL_SYMBOL should be"
#endif

#endif

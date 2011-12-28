#ifndef AWL_SYMBOL_HPP_INCLUDED
#define AWL_SYMBOL_HPP_INCLUDED

#if defined(AWL_STATIC_LINK)
#	define AWL_SYMBOL
#elif defined(awl_EXPORTS)
#	include <fcppt/export_symbol.hpp>
#	define AWL_SYMBOL FCPPT_EXPORT_SYMBOL
#else
#	include <fcppt/import_symbol.hpp>
#	define AWL_SYMBOL FCPPT_IMPORT_SYMBOL
#endif

#endif

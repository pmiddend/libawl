set(CMAKE_ALLOW_LOOSE_LOOP_CONSTRUCTS ON)

set(awl_utils_prototype_main_file
"#include <awl/main/function_context.hpp>
#include <fcppt/config/platform.hpp>

@AWL_UTILS_MAIN_FUNCTION_NAMESPACES_BEGIN@
int
@AWL_UTILS_MAIN_FUNCTION_NAME@(
	awl::main::function_context const &);\;
@AWL_UTILS_MAIN_FUNCTION_NAMESPACES_END@

#ifdef FCPPT_CONFIG_WINDOWS_PLATFORM
int CALLBACK
WinMain(
	HINSTANCE,
	HINSTANCE,
	LPSTR,
	int const _show_command)
{
	awl::main::function_context main_context(
		argc,
		argv,
		awl::main::optional_show_command(
			_show_command))\;
#else
int
main(
	int argc,
	char *argv[])
{
	awl::main::function_context main_context(
		argc,
		argv,
		awl::main::optional_show_command())\;
#endif
	return
		@AWL_UTILS_FULLY_QUALIFIED_MAIN_FUNCTION_NAME@(
			main_context)\;
}
"
)

set(
	awl_utils_prototype_file_name
	${CMAKE_BINARY_DIR}/main_prototype.cpp.in)

file(
	WRITE
	${awl_utils_prototype_file_name}
	${awl_utils_prototype_main_file})

function(
	awl_utils_add_portable_executable
	target_name
	main_function_name)

	set(AWL_UTILS_FULLY_QUALIFIED_MAIN_FUNCTION_NAME "${main_function_name}")

	string(
		REPLACE
		"::"
		";"
		awl_utils_current_namespace_list
		${main_function_name})

	#	message("AWL CMAKE DEBUG: Current namespace list: ${awl_utils_current_namespace_list}")

	list(LENGTH awl_utils_current_namespace_list awl_utils_current_number_of_namespaces)

	#	message("AWL CMAKE DEBUG: List length: ${awl_utils_current_number_of_namespaces}")

	math(EXPR awl_utils_current_number_of_namespaces_minus_one "${awl_utils_current_number_of_namespaces}-1")
	math(EXPR awl_utils_current_number_of_namespaces_minus_two "${awl_utils_current_number_of_namespaces_minus_one}-1")

	set(AWL_UTILS_MAIN_FUNCTION_NAMESPACES_BEGIN "")
	set(AWL_UTILS_MAIN_FUNCTION_NAMESPACES_END "")
	if(${awl_utils_current_number_of_namespaces_minus_two} GREATER 0)
		foreach(i RANGE 0 ${awl_utils_current_number_of_namespaces_minus_two})
			list(GET awl_utils_current_namespace_list ${i} awl_utils_current_namespace)
			#			message("AWL CMAKE DEBUG: Namespace iteration, current element: ${awl_utils_current_namespace}")
			set(AWL_UTILS_MAIN_FUNCTION_NAMESPACES_BEGIN
"${AWL_UTILS_MAIN_FUNCTION_NAMESPACES_BEGIN}namespace ${awl_utils_current_namespace}
{
")
			set(AWL_UTILS_MAIN_FUNCTION_NAMESPACES_END
"${AWL_UTILS_MAIN_FUNCTION_NAMESPACES_END}
}")
		endforeach()
	endif()

	list(GET awl_utils_current_namespace_list ${awl_utils_current_number_of_namespaces_minus_one} AWL_UTILS_MAIN_FUNCTION_NAME)

	set(awl_utils_temp_target_name ${CMAKE_BINARY_DIR}/targets/${target_name}.cpp)

	# @ONLY just for safety purposes. One "replacement style" is better than two.
	configure_file(
		${awl_utils_prototype_file_name}
		${awl_utils_temp_target_name}
		@ONLY)

	#message("Adding executable ${target_name} with source file ${awl_utils_temp_target_name} and files ${ARGN}")

	add_executable(
		${target_name}
		WIN32
		${awl_utils_temp_target_name}
		${ARGN})
endfunction()

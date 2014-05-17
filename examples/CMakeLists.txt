include_directories(
	${CMAKE_SOURCE_DIR}/include
)

add_definitions(
	"${AWL_CONFIG_LINK_MACROS}"
)

function(
	add_awl_example
	EXAMPLE_NAME
	ADDITIONAL_DEPS
)
	add_executable(
		${EXAMPLE_NAME}
		${EXAMPLE_NAME}.cpp
	)

	fcppt_utils_set_target_compiler_flags(
		${EXAMPLE_NAME}
	)

	target_link_libraries(
		${EXAMPLE_NAME}
		${AWL_DEFAULT_LINK_TARGET}
		${ADDITIONAL_DEPS}
	)
endfunction()

add_awl_example(main "${fcppt_core_TARGET}")
add_awl_example(resize "${fcppt_core_TARGET}")
add_awl_example(show "${fcppt_core_TARGET}")

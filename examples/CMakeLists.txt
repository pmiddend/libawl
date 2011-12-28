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

	target_link_libraries(
		${EXAMPLE_NAME}
		${AWL_DEFAULT_LINK_TARGET}
		${ADDITIONAL_DEPS}
	)
endfunction()

add_awl_example(asio "${Fcppt_core_LIBRARY}")
add_awl_example(main "${Fcppt_core_LIBRARY}")
add_awl_example(resize "${Fcppt_core_LIBRARY}")

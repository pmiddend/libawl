include_directories(
	${CMAKE_SOURCE_DIR}/include
)

add_definitions(
	"${AWL_CONFIG_LINK_MACROS}"
)

function(
	add_awl_example
	EXAMPLE_NAME
)
	add_executable(
		${EXAMPLE_NAME}
		${EXAMPLE_NAME}.cpp
	)

	target_link_libraries(
		${EXAMPLE_NAME}
		${AWL_DEFAULT_LINK_TARGET}
	)
endfunction()

add_awl_example(asio)
add_awl_example(main)
add_awl_example(resize)

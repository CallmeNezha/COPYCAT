include( CMakeParseArguments )


function( add_example ARG_NAME )
	# Parse arguments
	cmake_parse_arguments( ARG "COMMON" "" "DIRECTORIES" ${ARGN})

	# Get all source files
	list( APPEND ARG_DIRECTORIES "${KANNA_DIR}/examples/${ARG_NAME}" )
	set( SOURCES "" )
	foreach( DIR ${ARG_DIRECTORIES} )
		file( GLOB GLOB_SOURCES ${DIR}/*.cpp ${DIR}/*.h )
		list( APPEND SOURCES ${GLOB_SOURCES} )
	endforeach()

	if( ARG_COMMON )
		add_library( example-${ARG_NAME} STATIC EXCLUDE_FROM_ALL ${SOURCES} )
		# target_compile_definitions( example-${ARG_NAME} PRIVATE "-D_CRT_SECURE_NO_WARNINGS" "-D__STDC_FORMAT_MACROS" )
		target_include_directories( example-${ARG_NAME} PUBLIC ${KANNA_DIR}/examples/common )
		target_link_libraries( example-${ARG_NAME} PUBLIC KANNA )
	else()
		add_executable( example-${ARG_NAME} WIN32 EXCLUDE_FROM_ALL ${SOURCES} )
		# target_compile_definitions( example-${ARG_NAME} PRIVATE "-D_CRT_SECURE_NO_WARNINGS" "-D__STDC_FORMAT_MACROS" )
		target_link_libraries( example-${ARG_NAME} example-common )
		if( MSVC )
			set_target_properties( example-${ARG_NAME} PROPERTIES LINK_FLAGS "/ENTRY:\"mainCRTStartup\"" )
		endif()
	endif()

	# Directory name
	set_target_properties( example-${ARG_NAME} PROPERTIES FOLDER "KANNA/examples" )

endfunction()

# Add common library for examples
add_example(
	common
	COMMON
	DIRECTORIES
	${KANNA_DIR}/examples/common/entry
)

set(
	KANNA_EXAMPLES
	00-test
)

foreach( EXAMPLE ${KANNA_EXAMPLES} )
	add_example( ${EXAMPLE} )
endforeach()
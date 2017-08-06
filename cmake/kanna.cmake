if( NOT KANNA_DIR )
	message( SEND_ERROR "Could not load kanna, directory does not exist. ${KANNA_DIR}" )
	return()
endif()

# Grab the source files
file( GLOB KANNA_SOURCES ${KANNA_DIR}/src/*.cpp ${KANNA_DIR}/src/*.h )

# Create the target
add_library( KANNA STATIC ${KANNA_SOURCES} )

target_include_directories( KANNA PUBLIC ${KANNA_DIR}/include )

target_link_libraries( KANNA PUBLIC KOBAYAXI )

# Put it in filter
set_target_properties( KANNA PROPERTIES FOLDER "KANNA" )

# Export debug build as _d
set_target_properties( KANNA PROPERTIES OUTPUT_NAME_DEBUG "KANNA_d" )
if( NOT KOBAYAXI_DIR )
	message( SEND_ERROR "Could not load kobayaxi, directory does not exist. ${KOBAYAXI_DIR}" )
	return()
endif()


# Grab the source files
file( GLOB KOBAYAXI_SOURCES ${KOBAYAXI_DIR}/src/*.cpp ${KOBAYAXI_DIR}/src/*.h )

# Create the target
add_library( KOBAYAXI STATIC ${KOBAYAXI_SOURCES} )

target_include_directories( KOBAYAXI PUBLIC ${KOBAYAXI_DIR}/include )

# Build system specific configurations
if( MSVC )
	target_include_directories( KOBAYAXI PUBLIC ${KOBAYAXI_DIR}/include/compat/msvc )
elseif( MINGW )
	target_include_directories( KOBAYAXI PUBLIC ${KOBAYAXI_DIR}/include/compat/mingw )
elseif( APPLE )
	target_include_directories( KOBAYAXI PUBLIC ${KOBAYAXI_DIR}/include/compat/osx )
endif()

# # All configurations
# target_compile_definitions( KOBAYAXI PUBLIC "__STDC_LIMIT_MACROS" )
# target_compile_definitions( KOBAYAXI PUBLIC "__STDC_FORMAT_MACROS" )
# target_compile_definitions( KOBAYAXI PUBLIC "__STDC_CONSTANT_MACROS" )

# Put it in filter
set_target_properties( KOBAYAXI PROPERTIES FOLDER "KANNA" )

# Export debug build as _d
set_target_properties( KOBAYAXI PROPERTIES OUTPUT_NAME_DEBUG "KOBAYAXI_d" )

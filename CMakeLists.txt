cmake_minimum_required( VERSION 3.0 )
project( KANNA )

set_property( GLOBAL PROPERTY USE_FOLDERS ON )

# cross platform settings
if( APPLE )
	set( CMAKE_CXX_FLAGS "-ObjC++ --std=c++11" )
elseif( UNIX )
	set( CMAKE_CXX_STANDARD 11 )
	set( CMAKE_CXX_STANDARD_REQUIRED ON )
endif()

# options
option( KANNA_BUILD_EXAMPLES "Build KANNA examples" ON  )
option( KANNA_BUILD_TOOLS    "Build KANNA tools"    OFF )
option( KANNA_INSTALL        "Install targets"      OFF )


if( NOT KANNA_DIR )
	set( KANNA_DIR "${CMAKE_CURRENT_SOURCE_DIR}/kanna" CACHE PATH "Location of KANNA" ) # Moi moi Q
endif()
if( NOT KOBAYAXI_DIR )
	set( KOBAYAXI_DIR "${CMAKE_CURRENT_SOURCE_DIR}/kobayaxi" CACHE PATH "Location of KOBAYAXI" ) # infrastructrual library
endif()
if( NOT TORU_DIR )
	set( TORU_DIR "${CMAKE_CURRENT_SOURCE_DIR}/toru" CACHE PATH "Location of TORU" ) # image library
endif()

include( cmake/shared.cmake )
include( cmake/kanna.cmake )
include( cmake/toru.cmake )
include( cmake/kobayaxi.cmake )

if( KANNA_BUILD_TOOLS )
	include( cmake/shared.cmake )
endif()

if( KANNA_BUILD_EXAMPLES )
	message( STATUS "build " )
	include( cmake/examples.cmake )
endif()

if( KANNA_INSTALL )
	# install kanna
	install( TARGETS KANNA DESTINATION lib )
	install( DIRECTORY ${KANNA_DIR}/include DESTINATION . )

	# install kobayaxi
	install( TARGETS KOBAYAXI DESTINATION lib )
	install( DIRECTORY ${KOBAYAXI_DIR}/include DESTINATION . )

	# install toru
	install( TARGETS TORU DESTINATION lib )
	install( DIRECTORY ${TORU_DIR}/include DESTINATION . )

	# install tools
	if( KANNA_BUILD_TOOLS )
		install( TARGETS shaderc   DESTINATION  bin )
		install( TARGETS geometryc DESTINATION  bin )
	endif()
endif()
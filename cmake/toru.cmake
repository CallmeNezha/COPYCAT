if( NOT TORU_DIR )
	message( SEND_ERROR "Could not load toru, directory does not exist. ${TORU_DIR}" )
	return()
endif()
# ------ Set Options for Projects --------------- #
MESSAGE( STATUS "OPTION : Set Options for Project")

CMAKE_MINIMUM_REQUIRED(VERSION 3.20)
SET( CMAKE_CXX_STANDARD 14 )
SET( PROJECT_NAME "Example" )
SET( CMAKE_BUILD_TYPE Debug CACHE STRING "Build Type" FORCE )
PROJECT( ${PROJECT_NAME} )

MESSAGE( STATUS "OPTION : CMAKE Min Version ${CMAKE_MINIMUM_REQUIRED_VERSION}")
MESSAGE( STATUS "OPTION : CMAKE CXX_STANDARD ${CMAKE_CXX_STANDARD}")
MESSAGE( STATUS "OPTION : PROJECT NAME ${PROJECT_NAME}")
MESSAGE( STATUS "OPTION : CMAKE_BUILD_TYPE ${CMAKE_BUILD_TYPE}")
MESSAGE( STATUS "OPTION : Setting Done")
# ----------------------------------------------- #



# ------ Set Files ------------------------------ #
MESSAGE( STATUS "FILE : Set Source File")

SET(MAIN_DIR ${CMAKE_SOURCE_DIR})
SET(STYLEJSON_DIR ${MAIN_DIR}/StyleJson)

## Source Files
LIST( APPEND SRCS
    ${MAIN_DIR}/main.cpp

    ${MAIN_DIR}/StyleJson/Style.h   ${MAIN_DIR}/StyleJson/Style.cpp
    ${MAIN_DIR}/StyleJson/StyleInfo.h
    ${MAIN_DIR}/StyleJson/StyleJsonBase.h

    ${MAIN_DIR}/StyleJson/Expression/Expression.h
    ${MAIN_DIR}/StyleJson/Filter/Filter.h

    ${MAIN_DIR}/StyleJson/Layer/Layer.h
    ${MAIN_DIR}/StyleJson/Layout/Layout.h

    ${MAIN_DIR}/StyleJson/Property/Property.h
    
    ${MAIN_DIR}/StyleJson/Variant/Variant.h
)

## Header Filtes
LIST( APPEND INCS
    ${STYLEJSON_DIR}
)

MESSAGE( STATUS "FILE : Source File List")
FOREACH( source ${SRCS} )
    MESSAGE( STATUS "FILE : Source File ${source}" )   
ENDFOREACH()
MESSAGE( STATUS "FILE : Header Folder List")
FOREACH( header ${INCS} )
    MESSAGE( STATUS "FILE : Header Folder ${header}" )   
ENDFOREACH()
MESSAGE( STATUS "FILE : Setting Done ")
# ----------------------------------------------- #



# ------ Set Options for Target Files ----------- #
MESSAGE( STATUS "OPTION : Add Executable by platform")

## Include Header Directories for Target Files
IF ( WIN32 )
    ADD_EXECUTABLE( ${PROJECT_NAME} WIN32 ${SRCS} )
    SET( STATIC_LIB lib )
    SET( DYNAMIC_LIB dll )
    SET( PLATFORM "Windows" )
ELSE ()
    ADD_EXECUTABLE( ${PROJECT_NAME} ${SRCS} )
    SET( STATIC_LIB a )
    SET( DYNAMIC_LIB so )
    SET( PLATFORM "Other")
ENDIF()

MESSAGE( STATUS "OPTION : Platform ${PLATFORM}")
MESSAGE( STATUS "OPTION : Static Library ${STATIC_LIB} / Dynamic Library ${DYNAMIC_LIB}")
MESSAGE( STATUS "OPTION : Setting Done" )
# ----------------------------------------------- #



# ------ Setting for Extenal Project ------------ #
MESSAGE( STATUS "EXT-PROJECT : Set folder list" )

INCLUDE( ExternalProject )

SET( DEP_INCLUDE )
SET( DEP_LIB_DIR )
SET( DEP_LIBS )
SET( DEP_LIST )

SET( EXT_INCLUDE_DIR ${MAIN_DIR}/build/include )
SET( EXT_LIB_DIR ${MAIN_DIR}/build/lib )
SET( EXT_BIN_DIR ${MAIN_DIR}/build/${CMAKE_BUILD_TYPE} )
SET( EXT_ARC_DIR ${MAIN_DIR}/build/arc )

MESSAGE( STATUS "EXT-PROJECT : Include Directory ${EXT_INCLUDE_DIR}")
MESSAGE( STATUS "EXT-PROJECT : Library Directory ${EXT_LIB_DIR}")
MESSAGE( STATUS "EXT-PROJECT : Binary Directory ${EXT_BIN_DIR}")
MESSAGE( STATUS "EXT-PROJECT : Archive Directory ${EXT_ARC_DIR}")
MESSAGE( STATUS "EXT-PROJECT : Set folder list")
# ----------------------------------------------- #



# ------ Download LogProject in Github ---------- #
MESSAGE( STATUS "EXT-PROJECT : Download LogProject")
EXTERNALPROJECT_ADD(
	LogProject
	GIT_REPOSITORY GIT_REPOSITORY https://github.com/Winteradio/Log.git

	PREFIX ${CMAKE_BINARY_DIR}/Prefix/LogProject

	UPDATE_COMMAND "" PATCH_COMMAND "" TEST_COMMAND "" INSTALL_COMMAND ""
	CMAKE_ARGS 
		-DINCLUDE_DIR=${EXT_INCLUDE_DIR}
		-DLIB_DIR=${EXT_LIB_DIR}
		-DBIN_DIR=${EXT_BIN_DIR}
        -DARC_DIR=${EXT_ARC_DIR}
		-DCMAKE_BUILD_TYPE=Debug
		-DBUILD_STATIC_LIBRARY=OFF
 		-DINSTALL_DEMO_FILE=OFF 
)

LIST( APPEND DEP_LIST LogProject )
LIST( APPEND DEP_INCLUDE ${EXT_INCLUDE_DIR} )
LIST( APPEND DEP_LIBS ${EXT_ARC_DIR}/LogProject.${STATIC_LIB} )

MESSAGE( STATUS "EXT-PROJECT : Download LogProject" )
# ----------------------------------------------- #




# ------ Download RapidJson in Github ---------- #
MESSAGE( STATUS "EXT-PROJECT : Download RapidJson")
EXTERNALPROJECT_ADD(
	RapidJson
	GIT_REPOSITORY GIT_REPOSITORY https://github.com/Tencent/rapidjson.git

	PREFIX ${CMAKE_BINARY_DIR}/Prefix/RapidJson

	UPDATE_COMMAND "" PATCH_COMMAND "" TEST_COMMAND "" INSTALL_COMMAND ""
	CMAKE_ARGS 
		-DCMAKE_BUILD_TYPE=Debug
        -DRAPIDJSON_BUILD_DOC=OFF
        -DRAPIDJSON_BUILD_EXAMPLES=OFF
        -DRAPIDJSON_BUILD_TESTS=OFF
        -DRAPIDJSON_BUILD_CXX17=ON
)

LIST( APPEND DEP_LIST RapidJson )
LIST( APPEND DEP_INCLUDE ${EXT_INCLUDE_DIR} )

ADD_CUSTOM_COMMANd(
    TARGET RapidJson
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_BINARY_DIR}/include/RapidJson
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_BINARY_DIR}/Prefix/RapidJson/src/RapidJson/include
        ${CMAKE_BINARY_DIR}/include/RapidJson
    COMMENT "EXT-PROJECT : RapidJson / Copying RapidJson Header to ${CMAKE_BINARY_DIR}/include/RapidJson"
)

MESSAGE( STATUS "EXT-PROJECT : Download RapidJson")
# ----------------------------------------------- #





# ------ Link ExternalProject on Target  ------------- #
MESSAGE(STATUS "EXT-PROJECT : Set Options for Target Files")

TARGET_INCLUDE_DIRECTORIES(${PROJECT_NAME} PUBLIC ${DEP_INCLUDE} ${INCS})
TARGET_LINK_DIRECTORIES(${PROJECT_NAME} PUBLIC ${EXT_LIB_DIR} ${DEP_LIB_DIR} )
TARGET_LINK_LIBRARIES(${PROJECT_NAME} PUBLIC ${DEP_LIBS})
ADD_DEPENDENCIES(${PROJECT_NAME} ${DEP_LIST})

MESSAGE(STATUS "EXT-PROJECT : Setting Done ")
# ----------------------------------------------- #



# ------ Set Executable file -------------------- #
MESSAGE(STATUS "EXEFILE - Set Options for Target Files")

SET( EXE_DIR ${MAIN_DIR}/build )

IF ( CMAKE_BUILD_TYPE MATCHES Debug )
    SET_TARGET_PROPERTIES( ${PROJECT_NAME} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY_DEBUG ${EXE_DIR}/Debug
    )
    MESSAGE( STATUS "EXEFILE - Build exe file on Debug mode" )
ELSEIF ( CMAKE_BUILD_TYPE MATCHES Release )
    SET_TARGET_PROPERTIES( ${PROJECT_NAME} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY_RELEASE ${EXE_DIR}/Release
    )
    MESSAGE( STATUS "EXEFILE - Build exe file on Release mode" )
ELSE()
    SET_TARGET_PROPERTIES( ${PROJECT_NAME} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${EXE_DIR}
    )
    MESSAGE( STATUS "EXEFILE - Build exe file on Other mode" )
ENDIF()

MESSAGE( STATUS "EXEFILE - Setting Done ")
# ----------------------------------------------- #
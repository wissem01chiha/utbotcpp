#
# UnitTestBot
# Copyright 2022 UnitTestBot contributors (utbot.org)
#
cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

if (NOT DEFINED VERSION)
    if (DEFINED ENV{VERSION})
        set(VERSION $ENV{VERSION})
    else ()
        set(VERSION "0.0.1")
    endif ()
endif ()

if (NOT DEFINED RUN_INFO)
    if (DEFINED ENV{RUN_INFO})
        set(RUN_INFO $ENV{RUN_INFO})
    else ()
        set(RUN_INFO "local")
    endif ()
endif ()

project(UTBotCpp 
    DESCRIPTION "Automated unit and integration testing for c and c++"
    HOMEPAGE_URL "https://www.utbot.org" 
    VERSION ${VERSION}
)

set(PROJECT_ORG "UnitTestBot")

list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/config")

include(Options)

configure_file(
    ${PROJECT_SOURCE_DIR}/config/config.h.in 
    ${PROJECT_BINARY_DIR}/config.h 
    @ONLY
)

add_subdirectory(server)
cmake_minimum_required(VERSION 3.12)

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

project(UTBotCpp DESCRIPTION "Tool that generates unit test by C/C++ source code, trying to reach all branches and maximize code coverage"
        HOMEPAGE_URL "https://www.utbot.org" VERSION ${VERSION})
set(PROJECT_ORG "UnitTestBot")

message("Project: ${PROJECT_NAME}")
message("Organisation: ${PROJECT_ORG}")
message("Homepage: ${CMAKE_PROJECT_HOMEPAGE_URL}")
message("Version: ${CMAKE_PROJECT_VERSION}")
message("Run from: ${RUN_INFO}")

add_subdirectory(server)
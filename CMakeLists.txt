cmake_minimum_required(VERSION 3.10)
project(cinderbox VERSION "0.0.0")

include(FetchContent)

# Ensure Cinder is available
if (EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/cinder")
    message(STATUS "Cinder already cloned")
    add_subdirectory(cinder)
else()
    message(STATUS "Cinder does not exist in CinderBox root. Cloning...")
    set(FETCHCONTENT_QUIET FALSE)
    FetchContent_Declare(
            cinder
            GIT_REPOSITORY https://github.com/cinder/Cinder.git
            GIT_PROGRESS TRUE
            USES_TERMINAL_DOWNLOAD TRUE
    )
    FetchContent_MakeAvailable(cinder)
endif()

# Ensure {fmt} is available
if (EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/fmt")
    message(STATUS "{fmt} already cloned")
    add_subdirectory(fmt)
else()
    message(STATUS "{fmt} does not exist in CinderBox root. Cloning...")
    set(FETCHCONTENT_QUIET FALSE)
    FetchContent_Declare(
            fmt
            GIT_REPOSITORY https://github.com/fmtlib/fmt.git
            GIT_PROGRESS TRUE
            USES_TERMINAL_DOWNLOAD TRUE
    )
    FetchContent_MakeAvailable(fmt)
endif()

add_library(cinderbox INTERFACE)

message(STATUS "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(cinderbox INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_link_libraries(cinderbox INTERFACE cinder)
target_link_libraries(cinderbox INTERFACE fmt::fmt)

# Fix a bug with MSVC
if (${MSVC})
    target_link_options(cinderbox INTERFACE /SUBSYSTEM:WINDOWS)
endif()

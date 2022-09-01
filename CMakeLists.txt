cmake_minimum_required(VERSION 3.10)
project(cinderbox VERSION "0.0.0")

include(FetchContent)

# Ensure Cinder is available
if (EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/cinder")
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

# Ensure LibRapid is available
if (EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/librapid")
    add_subdirectory(librapid)
else()
    message(STATUS "{fmt} does not exist in CinderBox root. Cloning...")
    set(FETCHCONTENT_QUIET FALSE)
    FetchContent_Declare(
            librapid
            GIT_REPOSITORY https://github.com/librapid/librapid
            GIT_PROGRESS TRUE
            USES_TERMINAL_DOWNLOAD TRUE
    )
    FetchContent_MakeAvailable(librapid)
endif()

add_library(cinderbox INTERFACE)

target_include_directories(cinderbox INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_link_libraries(cinderbox INTERFACE cinder)
target_link_libraries(cinderbox INTERFACE librapid)

# Fix a bug with MSVC
if (${MSVC})
    target_link_options(cinderbox INTERFACE /SUBSYSTEM:WINDOWS)
endif()

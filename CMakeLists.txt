cmake_minimum_required(VERSION 3.10)

# Project name and version
project(mainapp VERSION 1.0)

# Set default C++ standard
set(CMAKE_CXX_STANDARD 11)

# Set directories
set(SOURCEDIR "src/")
set(UTILDIR "header/")
set(BUILDDIR "build/")
set(DISTDIR "dist/")


# Create build and dist directories if they don't exist
file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/${DISTDIR})
file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/${BUILDDIR})

# Source files (update to .cpp for C++ files)
set(CPPFILES ${SOURCEDIR}main.cpp ${UTILDIR}main.hpp)

# Output file name
set(NAME "Test")

# Include header directories
include_directories(${UTILDIR})

# Executable output directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${DISTDIR})

# Set compiler flags based on the detected compiler
if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    # GCC/Clang specific flags
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    # MSVC specific flags
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4 /WX")
    # Disable MSVC specific warnings (optional)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
else()
    message(FATAL_ERROR "Unsupported compiler: ${CMAKE_CXX_COMPILER_ID}")
endif()

# Check for required tools
find_program(GIT_EXECUTABLE git)

# Build the executable
add_executable(${NAME} ${CPPFILES})

# Set output directories for builds on different platforms
set_target_properties(${NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${DISTDIR}
)

# Custom target for default behavior
add_custom_target(default_target ALL
    DEPENDS ${NAME}
    COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR}
    COMMENT "Building the project..."
)

# Install rules (for cross-platform installation)
install(TARGETS ${NAME} DESTINATION bin)

# Compiler specific settings for MSVC (Visual Studio)
if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    set_target_properties(${NAME} PROPERTIES
        MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
endif()

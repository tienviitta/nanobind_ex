cmake_minimum_required(VERSION 3.9)

# Set a name and a version number for your project:
project(nanobind_ex VERSION 0.0.1 LANGUAGES CXX)

# Initialize some default paths
include(GNUInstallDirs)

# Define the minimum C++ standard that is required
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# Compilation options
option(BUILD_PYTHON "Enable building of Python bindings" ON)
option(BUILD_DOCS "Enable building of documentation" ON)

# compile the library
add_subdirectory(src)

# compile the application
add_subdirectory(app)

# compile the tests
include(CTest)

if(BUILD_TESTING)
    add_subdirectory(ext/Catch2)
    include(./ext/Catch2/contrib/Catch.cmake)
    add_subdirectory(tests)
endif()

if(BUILD_DOCS)
    # Add the documentation
    add_subdirectory(doc)
endif()

if(BUILD_PYTHON)
    # Add Python bindings
    add_subdirectory(ext/pybind11)

    # Compile the Pybind11 module
    pybind11_add_module(_nanobind_ex python/nanobind_ex/_nanobind_ex.cpp)
    target_link_libraries(_nanobind_ex PUBLIC nanobind_ex)

    # Install the Python module shared library
    install(TARGETS _nanobind_ex DESTINATION .)
endif()

# Add an alias target for use if this project is included as a subproject in another project
add_library(nanobind_ex::nanobind_ex ALIAS nanobind_ex)

# Install targets and configuration
install(
    TARGETS nanobind_ex
    EXPORT nanobind_ex-config
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

install(
    EXPORT nanobind_ex-config
    NAMESPACE nanobind_ex::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/nanobind_ex
)

install(
    DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/include/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

# This prints a summary of found dependencies
include(FeatureSummary)
feature_summary(WHAT ALL)

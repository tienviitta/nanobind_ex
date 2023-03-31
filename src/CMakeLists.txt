add_library(nanobind_ex nanobind_ex.cpp)
target_include_directories(nanobind_ex PUBLIC
  $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include/>
  $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

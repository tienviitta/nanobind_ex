// #include <pybind11/pybind11.h>
// #include <pybind11/stl.h>
#include <nanobind/nanobind.h>

#include "nanobind_ex/nanobind_ex.hpp"

// namespace py = pybind11;
namespace nb = nanobind;

namespace nanobind_ex {

// PYBIND11_MODULE(_nanobind_ex, m)
// {
//   m.doc() = "Python Bindings for nanobind_ex";
//   m.def("add_one", &add_one, "Increments an integer value");
// }
NB_MODULE(_nanobind_ex, m) {
    m.doc() = "Python Bindings for nanobind_ex";
    m.def("add_one", &add_one, "Increments an integer value");
}

} // namespace nanobind_ex

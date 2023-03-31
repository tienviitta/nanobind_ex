#include <nanobind/nanobind.h>
#include "nanobind_ex/nanobind_ex.hpp"

namespace nb = nanobind;

namespace nanobind_ex {

NB_MODULE(_nanobind_ex, m) {
    m.doc() = "Python Bindings for nanobind_ex";
    m.def("add_one", &add_one, "Increments an integer value");
}

} // namespace nanobind_ex

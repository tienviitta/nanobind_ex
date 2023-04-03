#include "nanobind_ex/nanobind_ex.hpp"
#include <cstddef>
#include <cstdint>
#include <nanobind/nanobind.h>
#include <nanobind/ndarray.h>

namespace nb = nanobind;

namespace nanobind_ex {

NB_MODULE(_nanobind_ex, m) {
    m.doc() = "Python Bindings for nanobind_ex";
    m.def("add_one", &add_one, "Increments an integer value");
    nb::class_<Fec>(m, "Fec")
        .def(nb::init<>())
        .def_ro("sum", &Fec::m_sum)
        .def_ro("chk", &Fec::m_chk)
        .def("encode",
             [](Fec &m_fec,
                nb::ndarray<uint8_t, nb::shape<nb::any>, nb::c_contig, nb::device::cpu>
                    &bits) { m_fec.encode(bits.data(), bits.shape(0)); })
        .def("decode",
             [](Fec &m_fec,
                nb::ndarray<uint8_t, nb::shape<nb::any>, nb::c_contig, nb::device::cpu>
                    &bits) { m_fec.decode(bits.data(), bits.shape(0)); });
}

} // namespace nanobind_ex

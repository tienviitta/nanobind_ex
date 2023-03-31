#include "nanobind_ex/nanobind_ex.hpp"
#include <cstddef>
#include <cstdint>

namespace nanobind_ex {

int add_one(int x) { return x + 1; }

Fec::Fec() : m_data(nullptr), n_data(0) {}

Fec::~Fec() {
    if (m_data) {
        delete [] m_data;
    }
}

void Fec::encode(uint8_t *bits, size_t n_bits) {
    m_data = bits;
    n_data = n_bits;
}

void Fec::decode(uint8_t *bits, size_t n_bits) {
    for (size_t i = 0; i < n_data; i++) {
        bits[i] = bits[i] ^ m_data[i];
    }
}


} // namespace nanobind_ex
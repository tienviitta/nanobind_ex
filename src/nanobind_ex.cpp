#include "nanobind_ex/nanobind_ex.hpp"
#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <numeric>
#include <spdlog/fmt/ranges.h>
#include <spdlog/spdlog.h>

namespace nanobind_ex {

int add_one(int x) { return x + 1; }

Fec::Fec() : m_data(0), m_sum(0), m_chk(0), n_data(0) {
    // spdlog::set_level(spdlog::level::debug);
    spdlog::set_pattern("[%^%l%$:%s:%!:%#] %v");
}

Fec::~Fec() {}

void Fec::encode(uint8_t *bits, size_t n_bits) {
    // Copy (?) input bits
    m_data.assign(bits, bits + n_bits);
    // Compute check sum
    m_sum = std::accumulate(m_data.begin(), m_data.end(), 0);
    SPDLOG_INFO("bits: {}, sum: {}", m_data, m_sum);
}

void Fec::decode(uint8_t *bits, size_t n_bits) {
    //
    std::vector<uint8_t> data(bits, bits + n_bits);
    m_chk = (m_sum == std::accumulate(data.begin(), data.end(), 0));
    SPDLOG_INFO("bits: {}, chk: {}", data, m_chk);
}

} // namespace nanobind_ex
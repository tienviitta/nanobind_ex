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
    spdlog::set_pattern("[%^%l%$:%s:%!:%#] %v");
}

Fec::~Fec() {}

void Fec::chksum(uint8_t *bits, size_t n_bits) {
    // Copy input bits to member vector
    m_data.assign(bits, bits + n_bits);
    // Compute check sum
    m_sum = std::accumulate(m_data.begin(), m_data.end(), 0);
    SPDLOG_INFO("bits: {}, sum: {}", m_data, m_sum);
}

void Fec::chkchk(uint8_t *bits, size_t n_bits) {
    // Copy input bits to vector
    std::vector<uint8_t> data(bits, bits + n_bits);
    m_chk = (m_sum == std::accumulate(data.begin(), data.end(), 0));
    SPDLOG_INFO("bits: {}, chk: {}", data, m_chk);
}

void Fec::encrypt(uint8_t *bytes, size_t n_bytes, const uint8_t key) {
    for (size_t i = 0; i < n_bytes; i++) {
        bytes[i] ^= key;
    }
    // Copy bytes to vector for logging
    std::vector<uint8_t> data(bytes, bytes + n_bytes);
    SPDLOG_INFO("bytes: {}, key: {}", data, key);
}

} // namespace nanobind_ex
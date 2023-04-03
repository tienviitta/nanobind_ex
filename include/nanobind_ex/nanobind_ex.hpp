#ifndef NANOBIND_EX_H
#define NANOBIND_EX_H

#include <cstddef>
#include <cstdint>
#include <vector>

namespace nanobind_ex {

/** @brief A very interesting function!
 *
 * This function is of course just a self-explanatory placeholder,
 * but surprisingly often, things aren't this easy. You should
 * therefore *really* document your C++ code with Doxygen!
 *
 * @param x The number to increase
 * @returns the successor of x
 */
int add_one(int x);

struct Fec {
    Fec();
    ~Fec();
    void chksum(uint8_t *bits, size_t n_bits);
    void chkchk(uint8_t *bits, size_t n_bits);
    void encrypt(uint8_t *bytes, size_t n_bytes, const uint8_t key);
    std::vector<uint8_t> m_data;
    uint8_t m_sum;
    bool m_chk;
    size_t n_data;
};

} // namespace nanobind_ex

#endif // NANOBIND_EX_H

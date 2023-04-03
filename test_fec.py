import unittest
import numpy as np
import build._nanobind_ex as pb


class Testing(unittest.TestCase):
    def test_chk_pass(self):
        rng = np.random.RandomState(123456)
        fec = pb.Fec()
        x = rng.randint(0, 2, 10, dtype=np.uint8)
        fec.chksum(x)
        fec.chkchk(x)
        self.assertEqual(fec.sum, np.sum(x))
        self.assertEqual(fec.chk, True)

    def test_chk_fail(self):
        rng = np.random.RandomState(123456)
        cef = pb.Fec()
        x = rng.randint(0, 2, 16, dtype=np.uint8)
        cef.chksum(x)
        x[np.random.randint(16)] ^= 1
        cef.chkchk(x)
        self.assertNotEqual(cef.sum, np.sum(x))
        self.assertEqual(cef.chk, False)

    def test_encrypt(self):
        rng = np.random.RandomState(123456)
        fec = pb.Fec()
        x = rng.randint(0, 255, 10, dtype=np.uint8)
        y = x.copy()
        # print("x: {}".format(x))
        key = np.uint8(123)
        fec.encrypt(x, key)
        # print("x: {}".format(x))
        fec.encrypt(x, key)
        # print("x: {}".format(x))
        np.testing.assert_array_equal(y, x)


if __name__ == '__main__':
    unittest.main()

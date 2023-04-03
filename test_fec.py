import unittest
import numpy as np
import build._nanobind_ex as pb


class Testing(unittest.TestCase):
    def test_fec_pass(self):
        rng = np.random.RandomState(123456)
        fec = pb.Fec()
        x = rng.randint(0, 2, 10, dtype=np.uint8)
        fec.encode(x)
        fec.decode(x)
        self.assertEqual(fec.sum, np.sum(x))
        self.assertEqual(fec.chk, True)

    def test_fec_fail(self):
        rng = np.random.RandomState(123456)
        cef = pb.Fec()
        x = rng.randint(0, 2, 16, dtype=np.uint8)
        cef.encode(x)
        x[np.random.randint(16)] ^= 1
        cef.decode(x)
        self.assertNotEqual(cef.sum, np.sum(x))
        self.assertEqual(cef.chk, False)


if __name__ == '__main__':
    unittest.main()

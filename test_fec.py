import numpy as np
import build._nanobind_ex as pb


def test_fec():
    rng = np.random.RandomState(123456)

    fec = pb.Fec()
    x = rng.randint(0, 2, 10, dtype=np.uint8)
    fec.encode(x)
    # print("chk: {}".format(fec.chk))
    fec.decode(x)

    cef = pb.Fec()
    x = rng.randint(0, 2, 16, dtype=np.uint8)
    cef.encode(x)
    # print("chk: {}".format(fec.chk))
    cef.decode(x)

    assert fec != None

if __name__ == "__main__":
    test_fec()

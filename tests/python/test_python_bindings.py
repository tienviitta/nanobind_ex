import nanobind_ex


# def test_nanobind_ex():
#     assert nanobind_ex.add_one(1) == 2
#     assert nanobind_ex.one_plus_one() == 2

def test_fec():
    fec = nanobind_ex.Fec()
    assert fec != None
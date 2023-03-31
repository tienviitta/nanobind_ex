add_executable(tests tests.cpp nanobind_ex_t.cpp)
target_link_libraries(tests PUBLIC nanobind_ex Catch2::Catch2)

# allow user to run tests with `make test` or `ctest`
catch_discover_tests(tests)

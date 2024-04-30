FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
    rforth
    main.c
    token.c
    int_stack.c
    ast.c
    LinkedList.c
    astmap.c)
add_executable(
    int_stack_tests
    int_stack_tests.cc
    int_stack.c
    )
add_executable(
    token_tests
    token_tests.cc
    token.c
    )
target_link_libraries(
    int_stack_tests
    gtest_main
    -lpthread
    )
target_link_libraries(
    token_tests
    gtest_main
    -lpthread
    )

include(GoogleTest)
gtest_discover_tests(int_stack_tests)
gtest_discover_tests(token_tests)

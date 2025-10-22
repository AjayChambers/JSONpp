# Integrate CTest into the Project
include(CTest)
enable_testing()

# Download & Integrate GTest into the Project
include(gtest)
gtest(https://github.com/google/googletest/archive/refs/heads/main.zip)

# Custom Test Generator Script
include(target_unit_test)

# Sandbox Test Executable (For development purposes)
target_unit_test(
    sandbox
    sandbox.test.cpp
    "text_buffer;json_lexer")

# TextCoords Test
target_unit_test(
    coordinates_test
    coordinates.test.cpp
    "GTest::gtest_main;coordinates")

# JSON Lexer Test (exec-name: lexer_test)
target_unit_test(
    lexer_test
    lexer.test.cpp
    "GTest::gtest_main;json_lexer")

target_unit_test(
    text_buffer_test
    text-buffer.test.cpp
    "GTest::gtest_main;text_buffer")
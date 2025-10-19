# Integrate CTest into the Project
include(CTest)
enable_testing()

# Download & Integrate GTest into the Project
include(gtest)
gtest(https://github.com/google/googletest/archive/refs/heads/main.zip)

# Custom Test Generator Script
include(target_unit_test)

# COMPILE & GENERATE EXECUTABLE BINARY: 'sandbox'
target_unit_test(sandbox
  sandbox.test.cpp
  "text_buffer;json_lexer")
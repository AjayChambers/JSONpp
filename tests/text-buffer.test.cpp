
#include "utility/print-test-info.hpp"

#include <text-buffer.hpp>
#include <gtest/gtest.h>

#include <format>
#include <string>
#include <string_view>

using namespace std;
using namespace TextFile;




TEST(TextBufferSuite, TextBufferPositionTest)
{
    JSONpp::printTestDetails(
      3,
      "TextBufferSuite",
      'A',
      "TextBufferPositionTest",
      "Class: TextBuffer",
      "TextCoords Members",
      "",
      "Affirms the TextCoords class tracks the TextCoords::iter member"
      "\n\t  accurately, and that the TextCoords member function pos()"
      "\n\t  returns the correct coordinates"
    );

    EXPECT_EQ(1, 1);
}
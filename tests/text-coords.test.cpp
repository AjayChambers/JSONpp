#include "utility/print-test-info.hpp"

#include <text-coords.hpp>
#include <gtest/gtest.h>

#include <format>
#include <string>
#include <string_view>

using namespace std;
using namespace TextFile;





TEST(TextCoordsSuite, ComparisonOperatorsTest)
{
    /****************************************************************
     * TEST #1: 'ComparisonOperatorsTest'
     *
     * DESCRIPTION:
     *   Executes a series of unique comparisons using five different
     *   TextCoords objects.,
     *
     * REASON FOR TEST:
     *   This test affirms that the TextCoords comparison operators
     *   are working as expected.
     ****************************************************************/

    JSONpp::printTestDetails(
      2,
      "TextCoordsSuite",
      'A',
      "ComparisonOperatorsTest",
      "CLASS: TextCoords",
      "TextCoords Comparison Operators",
      "Executes a series of unique comparisons using 5 different "
      "\n\t  TextCoords objects.",
      "This test affirms that the comparison operators for the "
      "\n\t  TextCoords class are working as expected."
    );

    TextCoords A = { 250, 70 };
    TextCoords B = { 250, 50 };
    TextCoords C = { 99, 1 };
    TextCoords D = { 100, 1 };
    TextCoords E = { 250, 70 };

    // A is { 250, 70 }
    // B is { 250, 50 }
    EXPECT_FALSE(A == B);
    EXPECT_NE(A, B);
    EXPECT_FALSE(C == D);
    EXPECT_NE(C, D);
    EXPECT_EQ(A, E);
    EXPECT_FALSE(A != E);

    EXPECT_GT(A, B);
    EXPECT_GT(D, C);

    EXPECT_LT(B, A);
    EXPECT_FALSE(A < B);
    EXPECT_FALSE(B > A);
    EXPECT_TRUE(A >= B);
    EXPECT_TRUE(B <= A);

    // C is { 99, 1 }
    // D is { 100, 1 }

    EXPECT_LT(C, D);
    EXPECT_FALSE(C > D);
    EXPECT_FALSE(D < C);
    EXPECT_FALSE(C >= D);
    EXPECT_FALSE(D <= C);

    // A is { 250, 70 }
    // E is { 250, 70 }
    EXPECT_FALSE(A > E);
    EXPECT_FALSE(A < E);
    EXPECT_TRUE(A >= E);
    EXPECT_TRUE(A <= E);
}
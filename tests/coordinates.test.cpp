#include "utility/print-test-info.hpp"

#include <coordinates.hpp>
#include <gtest/gtest.h>

#include <format>
#include <string>
#include <string_view>

using namespace std;
using namespace TextFile;

TEST (CoordinatesSuite, ComparisonOperatorsTest) {
    /****************************************************************
     * TEST #1: 'ComparisonOperatorsTest'
     *
     * DESCRIPTION:
     *   Executes a series of unique comparisons using five different
     *   Coordinates objects.,
     *
     * REASON FOR TEST:
     *   This test affirms that the Coordinates comparison operators
     *   are working as expected.
     ****************************************************************/

    JSONpp::printTestDetails (
     2,
     "CoordinatesSuite",
     'A',
     "ComparisonOperatorsTest",
     "CLASS: Coordinates",
     "Coordinates Comparison Operators",
     "Executes a series of unique comparisons using 5 different "
     "\n\t  Coordinates objects.",
     "This test affirms that the comparison operators for the "
     "\n\t  Coordinates class are working as expected."
    );

    Coordinates A = { 250, 70 };
    Coordinates B = { 250, 50 };
    Coordinates C = { 99, 1 };
    Coordinates D = { 100, 1 };
    Coordinates E = { 250, 70 };
    Coordinates F = { 1, 2 };
    Coordinates G = { 2, 1 };
    Coordinates H = { 987654321, 123456789 };

    EXPECT_FALSE (A == B);
    EXPECT_FALSE (C == D);
    EXPECT_FALSE (A != E);
    EXPECT_FALSE (E != A);
    EXPECT_FALSE (A != A);

    EXPECT_NE (C, D);
    EXPECT_EQ (A, E);
    EXPECT_GE (A, A);
    EXPECT_LE (A, A);
    EXPECT_GT (A, B);
    EXPECT_GT (A, C);
    EXPECT_GT (A, D);
    EXPECT_GE (A, E);
    EXPECT_LE (A, E);
    EXPECT_GE (E, A);
    EXPECT_LE (E, A);
    EXPECT_GT (A, F);
    EXPECT_GT (A, G);
    EXPECT_LT (A, H);
    EXPECT_EQ (A, A);
    EXPECT_NE (A, B);
    EXPECT_NE (A, C);
    EXPECT_NE (A, D);
    EXPECT_EQ (A, E);
    EXPECT_NE (A, F);
    EXPECT_NE (A, G);
    EXPECT_NE (A, H);

    EXPECT_LT (B, A);
    EXPECT_LE (B, B);
    EXPECT_GE (B, B);
    EXPECT_GT (B, C);
    EXPECT_GT (B, D);
    EXPECT_LT (B, E);
    EXPECT_GT (B, F);
    EXPECT_GT (B, G);
    EXPECT_LT (B, H);

    EXPECT_NE (B, A);
    EXPECT_NE (B, C);
    EXPECT_NE (B, D);
    EXPECT_NE (B, E);

    EXPECT_LT (B, A);
    EXPECT_FALSE (A < B);
    EXPECT_FALSE (B > A);
    EXPECT_TRUE (A >= B);
    EXPECT_TRUE (B <= A);

    EXPECT_LT (C, D);
    EXPECT_FALSE (C > D);
    EXPECT_FALSE (D < C);
    EXPECT_FALSE (C >= D);
    EXPECT_FALSE (D <= C);

    // A is { 250, 70 }
    // E is { 250, 70 }
    EXPECT_FALSE (A > E);
    EXPECT_FALSE (A < E);
    EXPECT_TRUE (A >= E);
    EXPECT_TRUE (A <= E);
}










TEST (CoordinatesSuite, IndividualRowColInteractionsTest) {
    /****************************************************************
     * TEST #1: 'IndividualRowColInteractionsTest'
     *
     * DESCRIPTION:
     *   Executes a series of unique comparisons using five different
     *   Coordinates objects.,
     *
     * REASON FOR TEST:
     *   This test affirms that the Coordinates row & col reference
     *   getters work as intended, and that row & col are capable of
     *   tracking coordinates accurately.
     ****************************************************************/

    JSONpp::printTestDetails (
     2,
     "CoordinatesSuite",
     'B',
     "ComparisonOperatorsTest",
     "CLASS: Coordinates",
     "&row()/&col(), getRow()/getCol(), and coords (@private)",
     "Executes a series of unique comparisons using 5 different "
     "\n\t  Coordinates objects.",
     "This test affirms that the Coordinates row & col reference"
     "\n\t  getters work as intended, and that row & col are capable of"
     "\n\t  tracking coordinates accurately."
    );


    Coordinates coords = { 10, 20 };
    // Coordinates B = { 30, 40 };
    // Coordinates C = { 50, 60 };

    size_t row    = ++coords.row();
    size_t expect = 11;

    EXPECT_EQ (row, expect);
    --coords.row();
    --coords.row();
    --coords.row();
    --coords.row();

    row    = --coords.row();
    expect = 6;
    EXPECT_EQ (row, expect);

    row    += coords.row();
    expect  = 12;
    EXPECT_EQ (row, expect);

    size_t col    = ++coords.col();
    expect = 21;
    EXPECT_EQ (col, expect);


    /*
        row = ++A.row();
        expect = 11;
        EXPECT_EQ (row, expect);

        row = ++A.row();
        expect = 11;
        EXPECT_EQ (row, expect);

        row = ++A.row();
        expect = 11;
        EXPECT_EQ (row, expect);

        row = ++A.row();
        expect = 11;
        EXPECT_EQ (row, expect);
    */
}
#include "../src/utility/jpp-exception.hpp"

#include <json/lexer.hpp>
#include <json/token.hpp>
#include <text-buffer.hpp>
#include <gtest/gtest.h>

#include <iostream>
#include <map>
#include <stdexcept>
#include <string>

using namespace std;
using namespace Json;
using namespace JSONpp;

const string TEST_SUITE = "Token Test Suite";


TEST(TokenTestSuite, tokenFactoryThrows)
{
    // TEST SET #1
    // TESTING WHAT: Func tokenFactory parameter 'TokenId tokenId'
    // ASSERTION TYPE: Expect Throw

    cout
      << "\nTEST SUITE: TOKEN_TEST_SUITE"
         "\n\n\n\n"
         "\nEXECUTING TEST SET # 1"
         "\n"
         "\nWHAT DOES THE SET TEST?"
         "\n  - Fn Sig: \"Token tokenFactory(TokenId tokenId, TextCoords position)\""
         "\n"
         "\nWHAT ASSERTION TYPE(S) ARE USED:"
         "\n  - Expect to throw"
         "\n  - Throw Type Expected: 'JSONpp::Ex'"
         "\n\n\n";

    // TEST: 1a --------------------------------------------------------
    //   AFFIRMS: tokenFactory throws a JSONpp::Ex object when used to
    //   create a String token.
    // -----------------------------------------------------------------
    TokenId tokenId;
    tokenId = TokenId::String;

    auto expectThrow_A
      = [&tokenId]() -> void { Token token = tokenFactory(tokenId, { 49, 85 }); };

    EXPECT_THROW(expectThrow_A(), Ex);

    // TEST: 1a --------------------------------------------------------
    //   AFFIRMS: tokenFactory throws a JSONpp::Ex object when used to
    //   create a String token.
    // -----------------------------------------------------------------
    tokenId = TokenId::Number;

    auto expectThrow_B
      = [&tokenId]() -> void { Token token = tokenFactory(tokenId, { 49, 85 }); };

    EXPECT_THROW(expectThrow_B(), Ex);
}


TEST(TokenTest, tokenFactoryTokenIdNumber)
{}
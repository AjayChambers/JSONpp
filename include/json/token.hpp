

#pragma once
#ifndef TOKEN_HPP
#define TOKEN_HPP

#include <string>
#include <text-coords.hpp>
#include <utility>

namespace Json {

enum class TokenType {
    CurlyBraceOpen  = 1,
    CurlyBraceClose = 2,
    SqBracketOpen   = 3,
    SqBracketClose  = 4,
    ColonOperator   = 5,
    CommaDelimeter  = 6,
    TrueLiteral     = 7,
    FalseLiteral    = 8,
    NullLiteral     = 9,
    StringValue     = 10,
    NumericValue    = 11,
};


std::string toString(TokenType tokenType);


class Token {
    TokenType   type_;
    std::string value_;
    TextCoords  coords;

   public:
    Token(TokenType type, std::string value = "", TextCoords pos = { 0, 0 });
    Token(const Token &other);
    Token(const Token &&other);

    Token &operator = (const Token &other);
    Token &operator = (const Token &&other);

    Token &copy(const Token &other);
    Token &changeLoc(const TextCoords &row_col_pair);

    TokenType   type() noexcept;
    std::string value() noexcept;
    TextCoords  loc() noexcept;
};

}

#endif
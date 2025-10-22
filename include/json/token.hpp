#pragma once
#ifndef TOKEN_HPP
#define TOKEN_HPP

#include <coordinates.hpp>

#include <string>
#include <utility>


using namespace TextFile;


namespace Json {

// Adding Enums to Json Namespace
enum class TokenType { Structural = 1, Literal = 2, DynamicValue = 3 };

enum class TokenId {
    CurlyBraceOpen  = 1,
    CurlyBraceClose = 2,
    SqBracketOpen   = 3,
    SqBracketClose  = 4,
    Colon           = 5,
    Comma           = 6,
    TrueLiteral     = 7,
    FalseLiteral    = 8,
    NullLiteral     = 9,
    String          = 10,
    Number          = 11,
};

// Adding Token class to Json Namespace
class Token {
    TokenId     id_;
    TokenType   type_;
    std::string value_;
    Coordinates  position_;

  public:
    Token(TokenId type, std::string value = "", Coordinates pos = { 0, 0 });
    Token(const Token &other);
    Token(const Token &&other);

    Token &operator = (const Token &other);
    Token &operator = (const Token &&other);

    Token &copy(const Token &other);
    Token &updateCoordinates(size_t row, size_t col);

    TokenId     id() noexcept;
    std::string value() noexcept;
    Coordinates  position() noexcept;

  private:
    TokenType associatedType(TokenId id);
};

// Adding Functions to Json Namespace
std::string to_string(const TokenType &type);
std::string to_string(TokenId tokenType);

Token genToken(TokenId tokenId, Coordinates position);
Token genStringToken(std::string tokenValue, Coordinates position);
Token genNumberToken(std::string numberAsString, Coordinates position);

}  // Ns: Json
#endif
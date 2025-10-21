/****************************************************************
 * FILE:   'token.cpp'
 * AUTHOR: 'Andrew Chambers (w3dojo@gmail.com)'
 * REPO:   'https:://www.GitHub.com/AjayChambers/JSONpp
 * DESCRIPTION:
 * This file contains the definitions for the Token class member
 * declared in 'Token.hpp'. The Token class is used to create
 * abstractions that represent the Tokens defined in the
 * ECMA-404 (2017) standard.
 *
 * -------------------------------------------------------------
 * Copyright (C) 2025 Andrew J Chambers Jr
 *
 * This program is free software: you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation, either version 3 of
 * the License, or the License, or (at your option) any later
 * version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 ****************************************************************/
#include "utility/jpp-exception.hpp"

#include <json/token.hpp>

#include <string>
#include <utility>


using namespace JSONpp;
namespace Json {




Token::Token(TokenId id, std::string value, TextCoords pos)
 : id_(id)
 , type_(associatedType(id))
 , value_(std::move(value))
 , position_(std::move(pos))
{}




Token::Token(const Token &other)
 : id_(other.id_)
 , type_(other.type_)
 , value_(other.value_)
 , position_(other.position_)
{}




Token::Token(const Token &&other)
 : id_(other.id_)
 , type_(other.type_)
 , value_(other.value_)
 , position_(other.position_)
{}




Token &Token::operator = (const Token &other)
{
    copy(other);
    return *this;
}




Token &Token::operator = (const Token &&other)
{
    copy(other);
    return *this;
}




Token &Token::copy(const Token &other)
{
    if (this == &other) { return *this; }
    id_       = other.id_;
    type_     = other.type_;
    value_    = other.value_;
    position_ = other.position_;
    return *this;
}




Token &Token::updateCoordinates(size_t row, size_t col)
{
    position_ = { row, col };
    return *this;
}




TokenId Token::id() noexcept
{ return id_; }




std::string Token::value() noexcept
{ return value_; }




TextCoords Token::position() noexcept
{ return position_; }




/*****************************************************************
 * @private
 * sets the tokens type during construction
 *****************************************************************/
TokenType Token::associatedType(TokenId id)
{
    switch (id)
    {
        // Structural Tokens
        case TokenId::CurlyBraceOpen : return TokenType::Structural;
        case TokenId::CurlyBraceClose: return TokenType::Structural;
        case TokenId::SqBracketOpen  : return TokenType::Structural;
        case TokenId::SqBracketClose : return TokenType::Structural;
        case TokenId::Colon          : return TokenType::Structural;
        case TokenId::Comma          : return TokenType::Structural;
        // Literal Tokens
        case TokenId::TrueLiteral : return TokenType::Literal;
        case TokenId::FalseLiteral: return TokenType::Literal;
        case TokenId::NullLiteral : return TokenType::Literal;
        // Value Tokens
        case TokenId::String: return TokenType::DynamicValue;
        case TokenId::Number: return TokenType::DynamicValue;
    }
}

}



// 'token.hpp' FUNCTIONS
namespace Json {


/*****************************************************************
 * @public
 * @brief Converts an enumerated TokenType type to a std::string
 * @param type The TokenType type to convert
 * @returns A std::string value that represents the TokenType type
 *****************************************************************/
std::string to_string(const TokenType &type)
{
    switch (type)
    {
        case TokenType::Structural  : return "Structural";
        case TokenType::Literal     : return "Literal";
        case TokenType::DynamicValue: return "DynamicValue";
    }
}




/*****************************************************************
 * @brief Overloads toString w/ a TokenType argument enabling
 * it convert an enum TokenType type into std::string type
 * @param tokenType <TokenType> Takes a Json::TokenType
 * @returns A string that replicates the input. In other words, if
 * toString were to be passed `TokenType::Comma_Delimiter` as an
 * arg, then it would return "TokenType::Comma_Delimiter" as a
 * string.
 *****************************************************************/
std::string to_string(const TokenId &tokenType)
{
    switch (tokenType)
    {
        case TokenId::CurlyBraceOpen : return "CurlyBraceOpen";
        case TokenId::CurlyBraceClose: return "CurlyBraceClose";
        case TokenId::SqBracketOpen  : return "SqBracketOpen";
        case TokenId::SqBracketClose : return "SqBracketClose";
        case TokenId::Colon          : return "Colon";
        case TokenId::Comma          : return "Comma";
        case TokenId::TrueLiteral    : return "TrueLiteral";
        case TokenId::FalseLiteral   : return "FalseLiteral";
        case TokenId::NullLiteral    : return "NullLiteral";
        case TokenId::String         : return "String";
        case TokenId::Number         : return "Number";
    }
}





Token genToken(TokenId tokenId, TextCoords position)
{
    switch (tokenId)
    {
        case TokenId::CurlyBraceOpen:
        {
            return Token(TokenId::CurlyBraceOpen, "{", position);
        }

        case TokenId::CurlyBraceClose:
        {
            return Token(TokenId::CurlyBraceClose, "}", position);
        }

        case TokenId::SqBracketOpen:
        {
            return Token(TokenId::SqBracketOpen, "[", position);
        }

        case TokenId::SqBracketClose:
        {
            return Token(TokenId::SqBracketClose, "]", position);
        }

        case TokenId::Colon:
        {
            return Token(TokenId::Colon, ":", position);
        }

        case TokenId::Comma:
        {
            return Token(TokenId::Comma, ",", position);
        }

        case TokenId::TrueLiteral:
        {
            return Token(TokenId::TrueLiteral, "true", position);
        }

        case TokenId::FalseLiteral:
        {
            return Token(TokenId::FalseLiteral, "false", position);
        }

        case TokenId::NullLiteral:
        {
            return Token(TokenId::NullLiteral, "null", position);
        }

        case TokenId::String:
        {
            throw Ex(
              "'genToken(...)' cannot create 'TokenId::String'"
              + exLb
              + "tokens. Use 'genStringToken()' instead");
        }

        case TokenId::Number:
        {
            throw Ex(
              "'genToken(...)' cannot create 'TokenId::Number'"
              + exLb
              + "tokens. Use 'genNumberToken()' instead");
        }
    }
}




Token genStringToken(std::string tokenValue, TextCoords position)
{ return Token(TokenId::String, tokenValue, position); }



Token genNumberToken(std::string tokenValue, TextCoords position)
{ return Token(TokenId::Number, tokenValue, position); }

// Token genNumberToken(TokenId tokenId, TextCoords position){}

}
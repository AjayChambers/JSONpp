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
#include <json/token.hpp>

#include <string>
#include <utility>


namespace Json {

/*****************************************************************
 * @brief Overloads toString w/ a TokenType argument enabling
 * it convert an enum TokenType type into std::string type
 * @param tokenType <TokenType> Takes a Json::TokenType
 * @returns A string that replicates the input. In other words, if
 * toString were to be passed `TokenType::Comma_Delimiter` as an
 * arg, then it would return "TokenType::Comma_Delimiter" as a
 * string.
 *****************************************************************/
std::string toString(const TokenType &tokenType)
{
    switch (tokenType)
    {
        case TokenType::CurlyBraceOpen : return "CurlyBraceOpen";
        case TokenType::CurlyBraceClose: return "CurlyBraceClose";
        case TokenType::SqBracketOpen  : return "SqBracketOpen";
        case TokenType::SqBracketClose : return "SqBracketClose";
        case TokenType::ColonOperator  : return "ColonOperator";
        case TokenType::CommaDelimeter : return "CommaDelimeter";
        case TokenType::TrueLiteral    : return "TrueLiteral";
        case TokenType::FalseLiteral   : return "FalseLiteral";
        case TokenType::NullLiteral    : return "NullLiteral";
        case TokenType::StringValue    : return "StringValue";
        case TokenType::NumericValue   : return "NumericValue";
    }
}


Token::Token(TokenType type, std::string value, TextCoords pos)
: type_(type)
, value_(std::move(value))
, coords(std::move(pos))
{}


Token::Token(const Token &other)
: type_(other.type_)
, value_(other.value_)
, coords(other.coords)
{}


Token::Token(const Token &&other)
: type_(other.type_)
, value_(other.value_)
, coords(other.coords)
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
    type_  = other.type_;
    value_ = other.value_;
    coords = other.coords;
    return *this;
}


Token &Token::changeLoc(const TextCoords &row_col_pair)
{
    coords = row_col_pair;
    return *this;
}


TokenType Token::type() noexcept
{ return type_; }


std::string Token::value() noexcept
{ return value_; }


TextCoords Token::loc() noexcept
{ return coords; }

}
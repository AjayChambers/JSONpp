#pragma once
#ifndef LEXER_HPP
#define LEXER_HPP

#include <json/diagnostics.hpp>
#include <json/token.hpp>

#include <iostream>
#include <string>
#include <string_view>
#include <text-buffer.hpp>
#include <utility>
#include <variant>
#include <vector>


namespace Json {

using LexResult_T = std::variant<Token, TDR>;
using Tokenize_T  = std::variant<std::vector<Token>, TDR>;


class JsonLexer {
    TextBuffer         buffer;
    std::vector<Token> tokens;
    std::string        json;

   public:
    JsonLexer();
    JsonLexer(const std::string &json);

    Tokenize_T  tokenize();
    LexResult_T lexString();
    LexResult_T lexNumber();
};

}


#endif
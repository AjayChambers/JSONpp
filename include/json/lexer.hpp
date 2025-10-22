#pragma once
#ifndef LEXER_HPP
#define LEXER_HPP

#include <json/diagnostics.hpp>
#include <json/token.hpp>
#include <coordinates.hpp>

#include <iostream>
#include <string>
#include <string_view>
#include <utility>
#include <variant>
#include <vector>


namespace Json {

using Report    = DiagnosticReport;
using TokenRes  = std::variant<Token, Report>;
using LexObjRes = std::variant<std::vector<Token>, Report>;


LexObjRes jsonLexer(const std::string &json);


}  // Ns Json
#endif
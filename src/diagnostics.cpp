#include <json/diagnostics.hpp>
#include <json/token.hpp>

#include <format>
#include <string>
#include <string_view>

namespace Json {

std::string toString(const ErrType &id)
{
    switch (id)
    {
        case ErrType::UNEXPECTED: return "UNEXPECTED";
        case ErrType::NOT_FOUND : return "NOT_FOUND";
        case ErrType::INVALID   : return "INVALID";
    }
}

DiagnosticReport::DiagnosticReport(ErrType errType, Token token, std::string cause)
 : errorType(errType)
 , token(token)
 , tokenPosition(token.position())
 , tokenId(token.id())
 , tokenValue(token.value())
 , cause(cause)
{}


void DiagnosticReport::formatReport()
{
    // DiagnosticReport properties as std::string
    const std::string ERI = toString(errorType);                  // errorType
    const std::string ROW = std::to_string(tokenPosition.row());  // tokenPosition
    const std::string COL = std::to_string(tokenPosition.col());  // tokenPosition
    const std::string TKI = to_string(tokenId);                   // tokenId
    const std::string TKT = to_string(tokenType);                 // tokenType
    const std::string TKV = tokenValue;
    const std::string MSG = cause;

    constexpr std::string_view FMT
      = "\n\n\n"
        "\nJSON++ found an error in a JSON text during lexical analysis."
        "\n"
        "\n  REPORT ID: {}"  // ERI (errorId)
        "\n"
        "\n  TOKEN DESCRIPTION:"
        "\n    | Type: [{}]"   // TKT (tokenType)
        "\n    | Id:   [{}]"   // TKI (tokenId)
        "\n    | Value: '{}'"  // TKV (tokenValue)
        "\n"
        "\n  TOKEN COORDINATES:"
        "\n    | Line @({})"  // ROW (tokenPosition)
        "\n    | Char @({})"  // COL (tokenPosition)
        "\n"
        "\n  CAUSE: {}"       // MSG (mesg from dev)
        "\n\n";

    std::string report = std::format(FMT, ERI, TKT, TKI, TKV, ROW, COL, MSG);

    setReport(report);
}


void DiagnosticReport::setReport(std::string report) noexcept
{ this->report = report; }



/*
//
// ||--------------------------------||
//        [ TOKEN DIAGNOSTIC ]
// ||--------------------------------|| */

}
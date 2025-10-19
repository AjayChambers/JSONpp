#include <json/diagnostics.hpp>
#include <format>
#include <string_view>


namespace Json {


  std::string toString(const ErrorType &id)
  {
    switch (id)
    {
      case ErrorType::UNEXPECTED: return "UNEXPECTED";
      case ErrorType::NOT_FOUND : return "NOT_FOUND";
      case ErrorType::INVALID   : return "INVALID";
    }
  }

  DiagnosticReport::DiagnosticReport(ErrorType id, std::string cause)
   : id_(id)
   , cause_(cause)
  {}


  ErrorType DiagnosticReport::id() const noexcept
  { return id_; }


  std::string DiagnosticReport::report() const noexcept
  { return report_; }


  std::string DiagnosticReport::cause() const noexcept
  { return report_; }


  void DiagnosticReport::formatReport()
  {}


  void DiagnosticReport::setReport(std::string report) noexcept
  { this->report_ = report; }



  /*
  //
  // ||--------------------------------||
  //        [ TOKEN DIAGNOSTIC ]
  // ||--------------------------------|| */

  TDR::TDR(ErrorType id, Token token, std::string cause)
   : DiagnosticReport(id, cause)
   , token(token)
   , location(token.loc())
   , tokenType(token.type())
   , tokenValue(token.value())
  {}




  void TDR::formatReport()
  {

    constexpr std::string_view fmt
       = "\n\n\n"
         "\nJSON++ found an error in the JSON text it was analyzing."
         "\n"
         "\n"
         "\nPRINTING JSON DIAGNOSTIC REPORT:"
         "\n  "
         "\n  ERROR ID: {}"
         "\n  "
         "\n "
         "\n   @Line #{}"
         "\n   @Char  #{}"
         "\n  "
         "\n  "
         "\n  "
         "\n  "
         "\n  "
         "\n  "
         "\n  "
         "\n  "
         "\n  "
         "\n  "

         "\n";

    std::string report = std::format(
       fmt, toString(id()), location.row(), location.col(), toString(tokenType));

    setReport(report);
  }

}
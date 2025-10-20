#pragma once
#ifndef JPP_EXCEPTION_HPP
#define JPP_EXCEPTION_HPP

#include <format>
#include <source_location>
#include <string>

using src_loc = std::source_location;

namespace JSONpp {

inline std::string exLb = "\n\t       ";

class Ex : public std::exception {
    src_loc           loc;
    const std::string cause;
    const std::string mesg;

  public:
    inline Ex(const std::string &cause, src_loc loc = src_loc::current())
     : loc(loc)
     , cause(cause)
     , mesg(fmtMesg())
    {}

    inline const char *what() const noexcept override
    { return mesg.c_str(); }

  protected:
    inline std::string fmtMesg() const
    {
        return format(
          "\n\n"
          "\n!! ERROR: An error caused the program to terminate unexpectedly."
          "\n"
          "\n    * Coordinates: [Line# {} | Char# {}]"
          "\n    * File Location: \"{}\""
          "\n    * Func Location: \"{}\""
          "\n"
          "\n\tCAUSE: {}"
          "\n\t       "  // "\n\t        " <- use to add line break (JSONpp::exLb)
          "\n\n",
          loc.line(),
          loc.column(),
          loc.file_name(),
          loc.function_name(),
          cause);
    }
};


}  // Nmsp
#endif
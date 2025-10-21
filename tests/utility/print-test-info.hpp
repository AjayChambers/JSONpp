#pragma once

#ifndef PRINT_TEST_INFO_HPP
#define PRINT_TEST_INFO_HPP

#include <iostream>
#include <string>



namespace JSONpp {

inline void printTestDetails(
  int         suiteNum,
  std::string suiteName,
  char        testChar,
  std::string testName,
  std::string entity,
  std::string member,
  std::string reason,
  std::string desc)
{
    constexpr std::string_view FMT
      = "\n\n\n"
        "\nSuite: #{}: '{}'"
        "\n"
        "\n[TEST {}{}: '{}']__________________________________________"
        "\n"
        "\n\tWHAT ENTITY IS BEING TESTED?"
        "\n\t  | ENTITY   ->  '{}'"
        "\n\t  | SPECIFIC ->  '{}'"
        "\n"
        "\n\tHOW DOES THE TEST WORK?"
        "\n\t  \"{}\""
        "\n"
        "\n\tWHAT PURPOSE DOES THE TEST SERVE?"
        "\n\t  \"{}\""
        "\n\n";

    std::cout << format(
      FMT,
      suiteNum,
      suiteName,
      suiteNum,
      testChar,
      testName,
      entity,
      member,
      reason,
      desc);
}

}

#endif
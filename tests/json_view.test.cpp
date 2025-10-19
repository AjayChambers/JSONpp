#include <text-buffer.hpp>

#include <gtest/gtest.h>

#include <iostream>
#include <string_view>

using namespace std;

TEST(JsonAnalysisTest, LexicalAnalysis)
{
  cout << "\nExecuting Test: Sandbox Dev Test...\n";

  // const string jsonString(
  //  "{\n"
  //  "  \"LEVEL: 1\": {\n"
  //  "    \"LEVEL: 2\": {\n"
  //  "      \"LEVEL: 3\": {\n"
  //  "        \"LEVEL: 4\": {\n"
  //  "          \"LEVEL: 5\": {\n"
  //  "            \"LEVEL: 6\": {\n"
  //  "              \"LEVEL: 7\": {\n"
  //  "                \"LEVEL: 8\": [\n"
  //  "                  \"LEVEL: 9\",\n"
  //  "                ]\n"
  //  "              }\n"
  //  "            }\n"
  //  "          }\n"
  //  "        }\n"
  //  "      }\n"
  //  "    }\n"
  //  "  }\n"
  //  "}");

  const string STR = "{ \"Hello \": \"World!\" }";

  EXPECT_EQ(1, 1);
}
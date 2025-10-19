#include <iostream>
#include <string>
#include <text-buffer.hpp>
#include <variant>
using namespace std;

int main()
{
    cout << "\nExecuting Test: Sandbox Dev Test...\n";

    const string json =
   "{\n"
   "  \"Level-1\": {\n"
   "    \"Level-2\": {\n"
   "      \"Level-3\": {\n"
   "        \"Level-4\": {\n"
   "          \"Level-5\": {\n"
   "            \"Level-6\": {\n"
   "              \"Level-7\": {\n"
   "                \"Level-8\": [true, 532, \"Hello World!\", null, 12 ]\n"
   "              }\n"
   "            }\n"
   "          }\n"
   "        }\n"
   "      }\n"
   "    }\n"
   "  }\n"
   "}";

    // JsonLexer lexer(json);

    // lexer.tokenize();

    return 0;
}



#include "text-buffer.hpp"

#include <json/lexer.hpp>

#include <format>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

using namespace TextFile;
using namespace std;


namespace Json {

LexObjRes jsonLexer(const std::string &jsonInput) {
    TextBuffer    json(jsonInput);
    vector<Token> tokens;
    int32_t       objCount = 0;

    // Lambda helper: Detects a string's end, or the JSON text's end,
    // in the event the JSON text ends before the string does.
    auto end_of_string = [&json]() -> bool {
        return json.peekCurrent() == '"' && json.peekPrev() != '\\';
    };

    // Loop that walks the JSON Test
    while (!json.endReached())
    {
        char current = json.mvFwd();

        switch (current)  // current char iter points to
        {
            // WHITESPACE
            case ' ' :
            {
                break;
            }

            // OBJECT OPENED
            case '{' :
            {
                objCount++;
                Token token = genToken(TokenId::CurlyBraceOpen, json.pos());
                tokens.push_back(token);
                break;
            }

            // OBJECT CLOSED
            case '}' :
            {
                objCount++;
                Token token = genToken(TokenId::CurlyBraceOpen, json.pos());
                tokens.push_back(token);
                break;
            }

            // WHITESPACE
            case '"' :
            {
                string str = "";

                while (!json.endReached() && !end_of_string())
                { str += json.mvFwd(); };

                Token t = genStringToken(str, json.pos());
            }
        }
    }


    return tokens;
}

}
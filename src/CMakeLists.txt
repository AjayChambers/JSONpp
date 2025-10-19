add_library(text_coords STATIC "text-coords.cpp")
target_include_directories(text_coords PUBLIC ${CMAKE_SOURCE_DIR}/include)

add_library(text_buffer STATIC "text-buffer.cpp")
target_include_directories(text_buffer PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(text_buffer PUBLIC text_coords)

add_library(json_lexer STATIC "lexer.cpp" "token.cpp")
target_include_directories(json_lexer PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(json_lexer PUBLIC text_buffer)

#pragma once
#ifndef JSON_VIEW_HPP
#define JSON_VIEW_HPP

#include <filesystem>
#include <string>
#include <string_view>
#include <text-coords.hpp>
#include <utility>

namespace fs = std::filesystem;


namespace Json {

class TextBuffer {
   public:
    using Const_Iter = std::string_view::iterator;

   private:
    std::string      data;
    std::string_view text;
    size_t           size_;
    Const_Iter       iter;
    Const_Iter       end_;
    TextCoords       pos;

   public:
    explicit TextBuffer(const std::string &str);
    TextBuffer(const TextBuffer &other);
    TextBuffer(const fs::path &filepath);

    TextBuffer &operator = (const TextBuffer &other);
    TextBuffer &operator = (const std::string &str);

    size_t     size() const noexcept;
    TextCoords currentPosition() const noexcept;

    // Move iterator
    char mvFwd() noexcept;              // Move iter fwd  (+1)
    char mvBack();                      // Move iter back (-1)
    char peek() const noexcept;         // Char in index right of iter
    char peekPrev() const noexcept;     // Char in index left of iter
    char currentChar() const noexcept;  // Char in index iter points to
    bool endReached() const noexcept;
    void reset();  // Rebind iterators to their original starting positions

   private:
    std::string read(const fs::path &filepath) const;
};

}  // namespace Json

#endif

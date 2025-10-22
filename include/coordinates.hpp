#pragma once

#include <cstddef>
#ifndef TEXT_COORDS_HPP
#define TEXT_COORDS_HPP

#include <string>
#include <utility>

namespace TextFile {

class Coordinates
{
   private:
    std::pair<size_t, size_t> coords;

   public:
    Coordinates (const Coordinates &other);
    Coordinates (size_t row = 0, size_t col = 0);

    size_t &row() noexcept;
    size_t &col() noexcept;
    size_t &line_num() noexcept;
    size_t &char_num() noexcept;

    size_t getRow() noexcept;
    size_t getCol() noexcept;

    std::string to_string() const noexcept;
    void        print() const noexcept;

    // Assignment Operator
    Coordinates &operator = (const Coordinates &other);  // Assignment Op
    // Comparison Operators
    friend bool operator == (const Coordinates &left, const Coordinates &right) noexcept;
    friend bool operator == (const Coordinates &L, std::pair<size_t, size_t> R) noexcept;
    friend bool operator != (const Coordinates &left, const Coordinates &right) noexcept;
    friend bool operator < (const Coordinates &left, const Coordinates &right) noexcept;
    friend bool operator > (const Coordinates &left, const Coordinates &right) noexcept;
    friend bool operator >= (const Coordinates &left, const Coordinates &right) noexcept;
    friend bool operator <= (const Coordinates &left, const Coordinates &right) noexcept;
};

}

#endif

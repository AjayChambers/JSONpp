#pragma once

#ifndef TEXT_COORDS_HPP
#define TEXT_COORDS_HPP

#include <string>
#include <utility>


namespace TextFile {

class TextCoords {
   private:
    std::pair<size_t, size_t> coordinates;

   public:
    TextCoords();
    TextCoords(const TextCoords &other);
    TextCoords(size_t row, size_t col);

    TextCoords &operator = (const TextCoords &other);

    size_t row() noexcept;
    size_t col() noexcept;

    void print() const noexcept;
};

}

#endif

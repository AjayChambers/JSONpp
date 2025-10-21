#pragma once

#ifndef TEXT_COORDS_HPP
#define TEXT_COORDS_HPP

#include <string>
#include <utility>


namespace TextFile {

class TextCoords {
   private:
    std::pair<size_t, size_t> coords;

   public:
    TextCoords(const TextCoords &other);
    TextCoords(size_t row = 0, size_t col = 0);

    size_t row() noexcept;
    size_t col() noexcept;

    // Assignment Ops
    TextCoords &operator = (const TextCoords &other);

    // Comparison Ops
    bool operator == (const TextCoords &other) const noexcept;
    bool operator != (const TextCoords &other) const noexcept;
    bool operator < (const TextCoords &other) const noexcept;
    bool operator > (const TextCoords &other) const noexcept;
    bool operator >= (const TextCoords &other) const noexcept;
    bool operator <= (const TextCoords &other) const noexcept;

    void print() const noexcept;
};

}

#endif

#include <format>
#include <iostream>
#include <text-coords.hpp>

using namespace std;

namespace Json {



TextCoords::TextCoords()
: coordinates({ 0, 0 })
{}



TextCoords::TextCoords(size_t row, size_t col)
: coordinates(row, col)
{}



TextCoords::TextCoords(const TextCoords &other)
: coordinates(other.coordinates)
{}



TextCoords &TextCoords::operator = (const TextCoords &other)  // Assignment
{
    coordinates = { other.coordinates.first, other.coordinates.second };
    return *this;
}



size_t TextCoords::row() noexcept
{ return coordinates.first; }



size_t TextCoords::col() noexcept
{ return coordinates.second; }



void TextCoords::print() const noexcept
{
    string str = format(
    "\n\t| LINE #{}\n\t| CHAR #{}\n\n", coordinates.first, coordinates.second);
    cout << "\n\n  Printing Text Coordinates: " << str;
}

}
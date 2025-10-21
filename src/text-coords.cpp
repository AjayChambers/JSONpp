#include <format>
#include <iostream>
#include <text-coords.hpp>



namespace TextFile {



//////////////////////////////////////////////////////////////
// ||=====================================================||//
// ||        COORDINATE CLASS MEMBER DEFINITIONS          ||//
// ||=====================================================||//
//////////////////////////////////////////////////////////////

/*****************************************************************
 * @public
 * @brief Construct TextCoords obj using two 'size_t' arguments.
 * @param num Sets the coordinate's numeric value.
 *****************************************************************/
Coordinate::Coordinate(size_t num)
 : num(num)
{}

TextCoords::TextCoords(size_t row, size_t col)
 : coords(row, col)
{}




/*****************************************************************
 * @public
 * @overload
 * @brief Copy constructor that creates a TextCoords object from
 * the property values of another TextCoords object.
 * @param other Takes a TextCords object.
 *****************************************************************/
TextCoords::TextCoords(const TextCoords &other)
 : coords(other.coords)
{}




size_t TextCoords::row() noexcept
{
    return coords.first;
}




size_t TextCoords::col() noexcept
{
    return coords.second;
}




TextCoords &TextCoords::operator = (const TextCoords &other)  // Assignment
{
    coords = { other.coords.first, other.coords.second };
    return *this;
}




/*****************************************************************
 * @public
 * @overload
 * @brief Equality operator overload
 * @param other The other TextCoords obj to test against.
 * @returns true if the two TextCoords objects are equal.
 *****************************************************************/
bool TextCoords::operator == (const TextCoords &other) const noexcept
{
    auto [rowA, colA] = coords;
    auto [rowB, colB] = other.coords;

    return rowA == rowB && colA == colB;
}




/*****************************************************************
 * @public
 * @overload
 * @brief Equality operator overload
 * @param other The other TextCoords obj to test against.
 * @returns true if the two TextCoords objects are equal.
 *****************************************************************/
bool TextCoords::operator != (const TextCoords &other) const noexcept
{
    auto [rowA, colA] = coords;
    auto [rowB, colB] = other.coords;

    return rowA != rowB || colA != colB;
}




/*****************************************************************
 * @public
 * @overload
 * @brief Greater-than operator overload.
 * @param other The other TextCoords obj to test against.
 * @returns true if the left TextCoords obj is greater
 *****************************************************************/
bool TextCoords::operator > (const TextCoords &other) const noexcept
{
    auto [rowA, colA] = coords;
    auto [rowB, colB] = other.coords;

    if (rowA > rowB) return true;
    if (rowA == rowB && colA > colB) return true;
    return false;
}




/*****************************************************************
 * @public
 * @overload
 * @brief Lesser-than operator overload.
 * @param other The other TextCoords obj to test against.
 * @returns true if the left TextCoords obj is lesser
 *****************************************************************/
bool TextCoords::operator < (const TextCoords &other) const noexcept
{
    auto [rowA, colA] = coords;
    auto [rowB, colB] = other.coords;

    if (rowA < rowB) return true;
    if (rowA == rowB && colA < colB) return true;
    return false;
}




/*****************************************************************
 * @public
 * @overload
 * @brief 'Equal-to or Greater-than' operator overload.
 * @param other The other TextCoords obj to test against.
 * @returns true if the left TextCoords obj is equal to or greater
 * than
 *****************************************************************/
bool TextCoords::operator >= (const TextCoords &other) const noexcept
{ return *this == other || *this > other; }




/*****************************************************************
 * @public
 * @overload
 * @brief 'Equal-to or Lesser-than' operator overload.
 * @param other The other TextCoords obj to test against.
 * @returns true if the left TextCoords obj is lesser than or
 * equal to
 *****************************************************************/
bool TextCoords::operator <= (const TextCoords &other) const noexcept
{ return *this == other || *this < other; }





/*****************************************************************
 * @public
 * @overload
 * @brief Prints the TextCoords object's coordinate pair in the
 * console attached to the output stream.
 *****************************************************************/
void TextCoords::print() const noexcept
{
    string str
      = format("\n\t| LINE #{}\n\t| CHAR #{}\n\n", coords.first, coords.second);
    cout << "\n\n  Printing Text Coordinates: " << str;
}

}
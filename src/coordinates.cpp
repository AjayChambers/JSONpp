#include <coordinates.hpp>

#include <format>
#include <iostream>

namespace TextFile {



/****************************************************************
 * @public
 * @brief Constructor that creates a Coordinates object with
 * specified row and column values.
 * @param row The row coordinate (Default: row = 0).
 * @param col The column coordinate (Default: col = 0).
 ****************************************************************/
Coordinates::Coordinates (size_t row, size_t col)
 : coords (std::make_pair (row, col)) {}




/****************************************************************
 * @public
 * @overload
 * @brief Copy constructor that creates a Coordinates object from
 * the property values of another Coordinates object.
 * @param other Takes a TextCords object.
 ****************************************************************/
Coordinates::Coordinates (const Coordinates &other)
 : coords (other.coords) {}




/****************************************************************
 * @public
 * @brief Getter for row coordinate.
 * @returns <size_t> The row coordinate.
 ****************************************************************/
size_t Coordinates::getRow() noexcept { return coords.first; }




/****************************************************************
 * @public
 * @brief Getter for column coordinate.
 * @returns <size_t> The column coordinate.
 ****************************************************************/
size_t Coordinates::getCol() noexcept { return coords.second; }




/****************************************************************
 * @public
 * @brief Assignment operator overload.
 * @param other The other Coordinates obj to assign from.
 * @returns Coordinates& A reference to this Coordinates obj.
 ****************************************************************/
Coordinates &Coordinates::operator = (const Coordinates &other) {
    coords = { other.coords.first, other.coords.second };
    return *this;
}




/****************************************************************
 * @public
 * @brief Provides reference access to the row coordinate.
 * @returns <const size_t&> reference to the row coordinate.
 ****************************************************************/
size_t &Coordinates::row() noexcept { return coords.first; }




/****************************************************************
 * @public
 * @brief Provides reference access to the column coordinate.
 * @returns <const size_t&> reference to the column coordinate.
 ****************************************************************/
size_t &Coordinates::col() noexcept { return coords.second; }




/****************************************************************
 * @public
 * @see Coordinates::row() and Coordinates::col() for functional
 * details
 * @note Alternate for Coordinates::row()
 * @brief Coordinates::line_num() & Coordinates::char_num() provide
 * alternate semantics when using Coordinates. Depending on the
 * context, row/col or line_num/char_num, may feel more
 * intuitive.
 ****************************************************************/
size_t &Coordinates::line_num() noexcept { return row(); }




/****************************************************************
 * @public
 * @see Coordinates::row() and Coordinates::col() for functional
 * details
 * @note Alternate for Coordinates::col()
 * @brief Coordinates::line_num() & Coordinates::char_num() provide
 * alternate semantics when using Coordinates. Depending on the
 * context, row/col or line_num/char_num, may feel more
 * intuitive.
 ****************************************************************/
size_t &Coordinates::char_num() noexcept { return col(); }

}  // TextFile Namespace










////////////////////////////////////////////////////////////////
// ||======================================================|| //
// ||      Coordinates Comparison Operator Overloads       || //
// ||======================================================|| //
////////////////////////////////////////////////////////////////

using namespace TextFile;

/****************************************************************
 * @public
 * @overload
 * @brief Equality operator overload
 * @param other The other Coordinates obj to test against.
 * @returns true if the two Coordinates objects are equal.
 ****************************************************************/
bool TextFile::operator == (const Coordinates &L, const Coordinates &R) noexcept {
    const auto [ROW_L, COL_L] = L.coords;
    const auto [ROW_R, COL_R] = R.coords;

    return ROW_L == ROW_R && COL_L == COL_R;
}




bool TextFile::operator == (const Coordinates &L, std::pair<size_t, size_t> R) noexcept {
    const auto [ROW_L, COL_L] = L.coords;
    const auto [ROW_R, COL_R] = R;

    return ROW_L == ROW_R && COL_L == COL_R;
}



/****************************************************************
 * @public
 * @overload
 * @brief Equality operator overload
 * @param other The other Coordinates obj to test against.
 * @returns true if the two Coordinates objects are equal.
 ****************************************************************/
bool TextFile::operator != (const Coordinates &L, const Coordinates &R) noexcept {
    const auto [ROW_L, COL_L] = L.coords;
    const auto [ROW_R, COL_R] = R.coords;

    return ROW_L != ROW_R || COL_L != COL_R;
}




/****************************************************************
 * @public
 * @overload
 * @brief Greater-than operator overload.
 * @param other The other Coordinates obj to test against.
 * @returns true if the left Coordinates obj is greater
 ****************************************************************/
bool TextFile::operator > (const Coordinates &L, const Coordinates &R) noexcept {
    const auto [ROW_L, COL_L] = L.coords;
    const auto [ROW_R, COL_R] = R.coords;

    if (ROW_L > ROW_R) return true;
    if (ROW_L == ROW_R && COL_L > COL_R) return true;
    return false;
}




/****************************************************************
 * @public
 * @overload
 * @brief Lesser-than operator overload.
 * @param other The other Coordinates obj to test against.
 * @returns true if the left Coordinates obj is lesser
 ****************************************************************/
bool TextFile::operator < (const Coordinates &L, const Coordinates &R) noexcept {
    const auto [ROW_L, COL_L] = L.coords;
    const auto [ROW_R, COL_R] = R.coords;

    if (ROW_L < ROW_R) return true;
    if (ROW_L == ROW_R && COL_L < COL_R) return true;
    return false;
}




/****************************************************************
 * @public
 * @overload
 * @brief 'Equal-to or Greater-than' operator overload.
 * @param other The other Coordinates obj to test against.
 * @returns true if the left Coordinates obj is equal to or greater
 * than
 ****************************************************************/
bool TextFile::operator >= (const Coordinates &L, const Coordinates &R) noexcept {
    return L > R || L == R;
}




/****************************************************************
 * @public
 * @overload
 * @brief 'Equal-to or Lesser-than' operator overload.
 * @param other The other Coordinates obj to test against.
 * @returns true if the left Coordinates obj is lesser than or
 * equal to
 ****************************************************************/
bool TextFile::operator <= (const Coordinates &L, const Coordinates &R) noexcept {
    return L < R || L == R;
}

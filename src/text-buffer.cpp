#include "utility/jpp-exception.hpp"

#include <coordinates.hpp>
#include <text-buffer.hpp>

#include <cstddef>
#include <cstring>
#include <format>
#include <fstream>
#include <iostream>
#include <iterator>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;
using namespace JSONpp;

using Const_Iter = string_view::iterator;


namespace TextFile {

/**
 *****************************************************************
 * @public
 * @brief TextBuffer is a container that lets the developer walk
 * through the text char by char w/ complete control over the
 * iteration.
 * @param json_ a string that contains the JSON formatted text.
 *****************************************************************/
TextBuffer::TextBuffer(const string &str)
 : data(str)
 , text(str)
 , size_(text.size())
 , iter(text.begin())
 , end(text.end())
 , pos_(1, 1)
{}


// Construct from a text file's data
TextBuffer::TextBuffer(const fs::path &filepath)
 : data(read(filepath))
 , text(data)
 , size_(text.size())
 , iter(text.begin())
 , end(text.end())
 , pos_({ 1, 1 })
{}


/// Constructor (Copy Ctor)
TextBuffer::TextBuffer(const TextBuffer &other)
 : data(other.data)
 , text(other.text)
 , size_(other.size_)
 , iter(other.iter)
 , end(other.end)
 , pos_(other.pos_)
{}



/// Overloaded assignment (Copy Assignment)
TextBuffer &TextBuffer::operator = (const TextBuffer &other)
{
    if (this != &other)
    {
        text  = other.text;
        iter  = other.iter;
        end  = other.end;
        size_ = other.size_;
        pos_   = other.pos_;
    }

    return *this;
}



/**
 * ****************************************************************
 * @public
 * @brief Moves the iterator fwd (+1) so that it points at the next
 * index's char.
 * @returns Returns char if iter isn't at the end of its range.
 * @returns '\0' if the iter cannot traverse any further.
 ******************************************************************/
char TextBuffer::mvFwd() noexcept
{
    if (iter == end) { return '\0'; }
    return *(++iter);
}



/**
 * ****************************************************************
 * @public
 * @brief Moves the iterator fwd (+1) so that it points at the next
 * index's char.
 * @returns Returns char if iter isn't at the end of its range.
 * @returns '\0' if the iter cannot traverse any further.
 ******************************************************************/
char TextBuffer::mvBack()
{
    if (iter == text.begin())
    {
        throw range_error(
          "Iter attempted to move one index left while pointing at index pos 0.");
    }

    return *(--iter);
}



/**
 *****************************************************************
 * @public
 * @brief View the char that the iter will point at next.
 * @returns The index to the right of the current iter pos (+1).
 *****************************************************************/
char TextBuffer::peekNext() const noexcept
{ return *std::next(iter, 1); }



/**
 *****************************************************************
 * @public
 * @brief View the last char the iter pointed to.
 * @returns The index to the left of the current iter pos (-1).
 *****************************************************************/
char TextBuffer::peekPrev() const noexcept
{ return *std::prev(iter, 1); }



/**
 *****************************************************************
 * @public
 * @brief View the current char pointed to by the built in iter.
 * @returns The char in the index the iter points to.
 *****************************************************************/
char TextBuffer::peekCurrent() const noexcept
{ return *iter; }



/**
 *****************************************************************
 * @public
 * @brief get the size of THE json text
 * @return Returns the amount of chars contained in the json_view.
 *****************************************************************/
size_t TextBuffer::size() const noexcept
{ return size_; }



/**
 *****************************************************************
 * @public
 * @brief Returns a pair of coordinates that point to the location
 * of the 'Const_Iter iter'
 * @returns pair<size_t,size_t> first is row, second is col.
 * @example `auto [row, col] = json.iterPosition();`
 *****************************************************************/
Coordinates TextBuffer::pos() const noexcept
{ return pos_; }



/**
 *****************************************************************
 * @public
 * @brief returns true if the builtin iter traversed the entire
 * string.
 *****************************************************************/
bool TextBuffer::endReached() const noexcept
{ return (iter == end); }



/**
 *****************************************************************
 * @public
 * @brief Resets the view, as if the built-in iterators were never
 * moved.
 *****************************************************************/
void TextBuffer::reset()
{
    iter      = text.begin();
    end      = text.end();
    size_     = text.size();
    this->pos_ = { 1, 1 };  // reset row/col tracking
}



/**
 *****************************************************************
 * @private
 * @brief Read text into the buffer from a file.
 * @param filepath The filepath of the file to be read from.
 *****************************************************************/
std::string TextBuffer::read(const fs::path &filepath) const
{
    std::string text = "";

    if (!fs::exists(filepath))  // Validate filepath
    {
        throw Ex("Attempted to read a file that does not exist.");
    }

    if (!fs::is_regular_file(filepath))  // Validate readable file type
    {
        throw Ex("Attempted to read a file type that cannot be read from.");
    }

    ifstream file(filepath, ios::binary);
    if (!file) { throw Ex("Failed to open file"); }  // Validate file is open

    char ch;

    while (file.get(ch))
    {
        if (file.fail()) throw Ex("File read failed: Unexpected data detected.");
        if (file.bad()) throw Ex("File read failed: Bad bit detected.");
        text.push_back(ch);
    }

    return text;
}

}  // Close Json

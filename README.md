# JSONpp
JSONpp is a collection of libraries, types, and tools for working with JSON in C++
environments. It takes advantage of features released in C++17, C++20 & C++23 to
deliver a syntax that looks & feels like JSON. Its not a perfect solution, but
JSONpp is very close to the real thing. Its also 100% type safe, and it doesn't
use outdated (and frankly dangerous) features like 'union' to write recursive
behaving JSON objects. It uses modern C++ features like generics, variants, optional
variants, standardized aliases, and traits.

JSONpp doesn't just add support though, it has a plethora of tools at its disposal,
including:
- json_view
- json_file
- json_algorithms
- JNova CLI
- json_cpp_code_generator
- json_formatter
- and more.



## **Section #3: Development**

#### TOOLCHAIN
JSONpp (as you've likely already figured out) is a CMake project. It is a C++23
project. JSONpp won't compile in any environment that doesn't support at-least C++20.
The toolchain I used to build it can be found in the `projRoot/cmake/toolchain` dir.
If you look in the toolchain file you'll quickly deduce that I have always compiled
the project using clang++ on an x86 64B intel machine running Linux. However, the
toolchain file can use a buddy. If someone decides they want to step up and help out,
they are welcome to compile and build JSONpp using any CMake supported environment &
compiler they want, that's the beauty of CMake. Your also welcome to push your own
toolchain configuration through.

#### DEV ENV: VS Code
Like the toolchain, your welcome to develop in any environment that works for you,
however, I have preconfigured tasks, as well as gtest setup, to get going quickly
and smoothly from inside of VS Code. That being said, I am a big fan of CLion, and
Visual Studio 2022. Its completely understandable if you prefer one of those
environments

#### To help email me at Ajay-Chambers@outlook.com
# Alpha Infection

## Description

## Goals
This is just a hobby game. It's nothing fancy, but if people ever start using it and enjoying it, I'd be more than happy to keep developing it.

This project started becasue I wanted to grow my C skills and have always wanted to do game development. I'm a web developer by trade, so it's a substantial change in concerns during development.

## Requirements
Copy-Paste Ready Command:

    sudo apt-get install \
        libsdl2{,-net,-ttf,-mixer,-gfx,-image}-dev \
        cmake libconfuse-dev doxygen \
        clang-8{,-doc} clang-{tools,tidy}-8 lldb-8 \
        libboost1.67-all-dev


Explanations:

 * `libsdl2*-dev` - Libraries for rendering the game engine. Build on SDL for
 portability and ease of development, but it isn't a proper engine. Work to be
 done on that is in the codebase.
 * `cmake` - Alpha Infection's build system
 * `libconfuse-dev` - The configuration parsing library
 * `doxygen` - Code documentation tooling
 * `clang-8{,-doc} clang-{tools,tidy}-8 lldb-8` - CLang compiler tools for building the app


# Thanks!
 * [rxi](https://github.com/rxi/log.c)
 * [tcbrindle](https://github.com/tcbrindle/sdl2-cmake-scripts)

# File Naming Conventions

Found initially at: http://forums.codeguru.com/showthread.php?397010-What-s-with-*-cxx-files-instead-of-*-cpp

It is probably due to a project using libraries (in form of source code) that don't use the same naming convention the programmer(s) of the project.

There are at least four different extensions usable for C++ files:

    .C
    Not very popular since it requires a case-sensitive file system (otherwise, it would clash with old .c file names), and even a few modern OS are not case-sensitive.
    .c++
    Some OS or file systems don't support the + character in file names.
    .cpp
    That's very portable across file systems.
    But, it might be less consistent than .cxx
    .cxx
    Very portable across file systems (not more than .cpp)
    Using the name CXX for C++ is quite popular because CPP usually designates the C (and C++) pre-processor.
    For example, these environment variables/makefile macros
        CPPFLAGS
        Represents the flags passed to the pre-processor.
        CFLAGS
        Flags passed to the C compiler.
        CXXFLAGS
        Flags passed to the C++ compiler.
        LDFLAGS
        Flags passed to the linker.
        CC
        The path to the C compiler.
        CPP
        The path to the pre-processor.
        CXX
        The path to the C++ compiler.
        LD
        The path to the linker.

    That's why, with the above notations, it's very natural to give the .cxx extension to C++ files.



For headers, there are at least five extensions:

    .h
    Traditional C header files.
    Since the compiler doesn't do anything based on this extension, it can be used for C++ header files too.
    Furthermore, there are a lot of header files that are designed to be included by both C and C++ translation units.
    In that case, it's natural to give them this extension.

    .H, .hpp or .hxx
    That's very natural to give one of these extensions for C++ header files (being consistent with the name of C++ translation units).
    That's not a bad idea to use one of these name for pure C++ header files only (containing class definitions, or templates, or any other feature not supported by C).

    No extension
    That's internally used by a number of C++ compilers for iostream, vector, algorithm and all others new-style C++ headers.

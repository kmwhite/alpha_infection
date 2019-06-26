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
        clang-8{,-doc} clang-{tools,tidy}-8 lldb-8


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

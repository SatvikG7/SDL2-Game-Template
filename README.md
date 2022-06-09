# SDL2 Game Template

[![SDL2](http://libsdl.org/media/SDL_logo.png "visit")](http://libsdl.org/)

## Introduction

This repository contains the template for a SDL2 project which does the following things:

- Implements Game loop for 60 fps
- Creates window
- Sets window icon and title
- Creates and Renders background texture
- Creates and Renders sprite
- Handles keypress events


## Requirements

- MinGW toolkit (g++) (required)
- Python (>=3.8.x) (optional)


## Libraries Required
- SDL2
- SDL_image


## How to compile?

1. Install and Extract 
    - SDL2 development libraries from https://libsdl.org/download-2.0.php
    - Compiler specific development libraries of SDL_image from https://www.libsdl.org/projects/SDL_image/

2. Copy
    - SDL2/bin/* to bin/debug/ and bin/release/
    - SDL2/include/* to include/
    - SDL2/lib/* to lib/
    - SDL_image/bin/* to bin/debug/ and bin/release/
    - SDL_image/include/* to include/
    - SDL_image/lib/* to lib/

3. ```sh
    make res

    make run # to build and run debug executable
    # or
    make release # to build release executable
    ```

4. (Optional) You can make changes to generate_sprite.py files to make changes to sprite
    ```sh
    python generate_sprite.py

    make res
    ```

5. Feel free to open an issue in this repo if you get any error

# C++ Nanodegree: Capstone Snake Game

This is a modified version of [the starter Snake game code provided by Udacity](https://github.com/udacity/CppND-Capstone-Snake-Game) with some bug fixes and added functionality.

<img src="snake_game.gif"/>

## Bug fixes
* Fixed a bug in Game::PlaceFood() that caused food not getting placed at all if the place where it is going to be placed is occupied by the snake.
* Fixed a bug in the Game constructor that made food to be able to get placed outside of the grid and thus become unreachable.

## New functionality
* Now it is possible for the user to temporarily change launch options via console input (refer to main.cpp, lines 15-30).
  * This also makes the project pass **"The project accepts user input and processes the input"** rubric criterion.
* Added sound effects for eating food and dying (audio handling: audio_player.h/.cpp, the sound effects: "sounds" folder).

# Code structure
* **controller.h/.cpp** files describe the Controller class that handles the user input (arrow keys) and changes the direction of the snake accordingly.
* **audio_player.h/.cpp** files define the AudioPlayer class that is used in the Game class to play audio when snake eats food or dies.
* **renderer.h/.cpp** files include the Renderer class that creates the window, renders the snake and places and renders the food.
* **snake.h/.cpp** files have the Snake class that has the information about the snake like its current size and speed, also it has some functions that can change these values.
* **game.h/.cpp** files contain information about the Game class that has the AudioPlayer class as one of its member variables and has the Run(Controller const &controller, Renderer &renderer, std::size_t target_frame_duration) method that contains the game loop.
* Finally, **main.cpp** file saves the default launch options and gives the opportunity to change them via console, then creates Renderer, Controller and Game instances, executes Game::Run method and outputs the score and the size of the snake after the window is closed.

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  * Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source.
* SDL_mixer >= 2.0
  * All installation instructions can be found [here](https://lazyfoo.net/tutorials/SDL/06_extension_libraries_and_loading_other_image_formats/index.php)
  * These instructions are actually for installing SDL_image, but the same algorithm applies for installing SDL_mixer.
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`.

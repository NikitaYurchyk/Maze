# Maze Game

## Overview
The Maze Game is a console-based application developed in C++ that allows users to generate and explore a maze. It features an interactive interface for creating a maze of specified dimensions, setting a random generation seed, and discovering a path through the maze.

## Getting Started

### Prerequisites
- C++ Compiler (e.g., GCC, Clang)
- CMake (optional, for building)

### Compilation
1. **Compile the Program**
   - Open your terminal and navigate to the program's directory.
   - Compile the program using a C++ compiler. For GCC, you can use:
     ```
     g++ -o MazeGame main.cpp program.cpp maze.cpp -I.
     ```

### Running the Application
- Execute the game by running the compiled output:
  ```
  ./MazeGame
  ```

### How to Use
- **Create a Maze**
  - At the main menu, choose `1` to generate a new maze. You'll be prompted to enter the maze's width and height.
- **Specify Seed**
  - Select `2` at the main menu to set a seed number for the maze's random number generator. This choice influences the maze layout.
- **Find a Path**
  - After generating a maze, opt for `1` when asked if you wish to find a path to the maze's end. The path will then be displayed.
- **Exit the Game**
  - Choose `3` to exit the application.



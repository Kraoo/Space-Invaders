# Simple Space Invaders Game

Simple Space Invaders is a minimalistic command-line game written in C++. In this game, you control a player character and shoot bullets to destroy enemy invaders. Your objective is to score as many points as possible by shooting down the enemies before they reach the bottom of the screen.

## How to Play

1. **Controls**:
    - Move left: Press the 'a' key.
    - Move right: Press the 'd' key.
    - Fire bullet: Press the spacebar (' ').
    - Quit game: Press the 'q' key.

## Setup

To run the game, you need a C++ compiler installed on your system. Follow these steps:

1. Clone the repository or download the source code files.
2. Compile the source code using your preferred C++ compiler. For example:
    ```
    g++ main.cpp -o space_invaders
    ```
3. Run the compiled executable:
    ```
    ./space_invaders
    ```

## Dependencies

This game relies on the following libraries:
- `iostream`: Standard input-output library for C++.
- `cstdlib`: Standard library for functions involving memory allocation, random numbers, and other general utilities.
- `ctime`: Standard library for manipulating time.
- `unistd.h`: Provides access to the POSIX operating system API for functions like `usleep`.
- `termios.h`: Terminal input/output control library for POSIX-compliant operating systems.


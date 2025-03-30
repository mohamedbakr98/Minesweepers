# Minesweeper Game

A classic Minesweeper game implementation in C, featuring a console-based interface with ASCII graphics and player score tracking.

## Screenshots

[![image](https://github.com/user-attachments/assets/29b867e6-a333-448b-8c17-56e066798d13)]
<!-- Add your game screenshot here -->
<!-- Example: ![Game Screenshot](assets/screenshots/game.png) -->

## Project Overview

This Minesweeper implementation is built with modular architecture, separating concerns into distinct components for better maintainability and extensibility. The game features a traditional Minesweeper gameplay with additional features like player statistics and high score tracking.

## Architecture

The project is organized into the following components:

### Core Components

- **Board Module** (`board.c`, `Board.h`)
  - Manages the game board state
  - Handles mine placement and board initialization
  - Controls board display and element updates
  - Implements game logic for revealing cells

- **Game Module** (`game.c`, `game.h`)
  - Controls the main game loop
  - Manages game state and progression
  - Handles win/lose conditions
  - Coordinates between different game components

- **Player Module** (`player.c`, `player.h`)
  - Manages player information and statistics
  - Handles player score tracking
  - Implements high score system
  - Manages player data persistence

### UI Components

- **Frames Module** (`frames.c`, `frames.h`)
  - Handles game UI elements
  - Manages screen frames and borders
  - Provides visual feedback for game state
  - Implements ASCII-based graphics

- **Input Module** (`input.c`, `input.h`)
  - Processes user input
  - Handles keyboard interactions
  - Manages cursor movement
  - Provides input validation

### Main Program

- **Main Module** (`main.c`)
  - Entry point of the application
  - Initializes game components
  - Manages program flow
  - Handles program termination

## Features

- Classic Minesweeper gameplay
- Console-based ASCII graphics interface
- Player score tracking and high scores
- Multiple difficulty levels
- Persistent player statistics
- Intuitive keyboard controls

## Building the Project

### Prerequisites

- GCC compiler
- Windows operating system (for Windows-specific features)

### Compilation

To build the project, use the following command:

```bash
gcc -o minesweeper.exe main.c board.c frames.c game.c input.c player.c -D_WIN32_WINNT=0x0500
```

## Project Structure

```
Minesweeper/
├── src/           # Source files
├── include/       # Header files
├── lib/          # External libraries
├── tests/        # Test files
├── assets/       # Game assets
└── build/        # Build output directory
```

## Game Controls

- Arrow keys: Move cursor
- Enter: Reveal cell
- Space: Flag/unflag cell
- ESC: Exit game

## Technical Details

- Written in C
- Uses Windows Console API for display
- Implements modular architecture
- Uses file I/O for score persistence
- Implements object-oriented design patterns in C

## Contributing

Feel free to submit issues and enhancement requests!

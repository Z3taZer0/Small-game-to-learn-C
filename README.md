# Small C Game

A project to learn C programming by building a windowed game using **Raylib**.

## How to Play

### 1. Ready to Play?
If the `game` file is already compiled in the root directory, simply run it from your terminal:
```bash
./game
```

### 2. Controls
The game uses a windowed interface. Use your keyboard for the following actions:

**In the Menu:**
- **[P]**: Play Game (Starts the gameplay)
- **[E]**: Exit (Closes the game)

**In Game:**
- **[M]**: Return to Menu
- **[Q]**: Close the window (Exit)

## Development

### Prerequisites
The project uses a local version of **Raylib** located in the `vendor/` directory. On Linux, you may still need some system display libraries:
- OpenGL (`libGL`)
- X11 libraries (`libX11`, `libXcursor`, `libXrandr`, etc.)

### Building from Source
To compile the game yourself, use the provided Makefile:
```bash
make clean
make
```

## Project Structure
- `src/`: Source code (.c files)
- `include/`: Header files (.h)
- `vendor/`: Local Raylib binaries and includes
- `assets/`: Directory for game assets (textures, sounds, etc.)
- `tests/`: Directory for future unit tests
- `docs/`: Project documentation
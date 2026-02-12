# C Small Game

## Getting Started

### Prerequisites

You need a C compiler installed. Recommended options:
- **MinGW-w64** (most common for C on Windows)
- **Visual Studio** with C++ workload

### Building

If you have MinGW/GCC installed:
Run `build.bat` or `make`.

If you have Visual Studio:
Open a "Developer Command Prompt for VS" and run:
`cl src/main.c /Fe:game.exe /Iinclude`

### Structure
- `src/main.c`: The main entry point of the game. Start coding here!
- `include/`: Header files (.h)
- `assets/`: Images, sounds, etc.
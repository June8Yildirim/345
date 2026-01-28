# compilation_units/comp_units

A C++ project with proper structure and build system.

## Project Structure

```
compilation_units/comp_units/
├── src/                    # Source files (.cpp)
├── include/                # Header files (.h)
├── build/                  # Build artifacts (auto-generated)
├── tests/                  # Test files
├── docs/                   # Documentation
├── lib/                    # External libraries
├── Makefile                # Build configuration
└── compile_commands.json   # LSP configuration
```

## Build and Run

```bash
make        # Build the project
make run    # Build and run
make clean  # Clean build artifacts
```

## Testing

```bash
cd tests
clang++ -std=c++17 -I../include test_example.cpp ../src/project.cpp -o test
./test
```

## Development

### Prerequisites

- clang++ or g++ compiler
- C++17 support
- Make

### IDE Setup

This project includes `compile_commands.json` for LSP support.

**Neovim/LazyVim:**
- Make sure clangd is installed (`:Mason`)
- Open the project: `nvim .`

**VS Code:**
- Install C/C++ extension
- The `compile_commands.json` will be auto-detected

### Adding New Files

1. Add `.cpp` files to `src/`
2. Add `.h` files to `include/`
3. Update `compile_commands.json` if needed for LSP
4. The Makefile uses wildcards, so it will auto-detect new source files

## License

MIT License

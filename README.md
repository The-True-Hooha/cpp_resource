# C++ Development Setup Guide

This README outlines the setup for a professional C++ development environment using modern tools and practices.

## Environment

- **Compiler**: Clang 19.1.7 (Windows/MinGW)
- **Standard**: C++20
- **Build System**: CMake
- **IDE**: Visual Studio Code

## Initial Setup

### Configuring clangd for C++20

Create a `.clangd` file in your project root:

```yaml
CompileFlags:
  Add: [--std=c++20]
  CompilationDatabase: .
```

For Visual Studio Code, set up a project-specific configuration in `.vscode/settings.json`:

```json
{
  "clangd.arguments": [
    "--std=c++20",
    "--clang-tidy",
    "--compile-commands-dir=."
  ],
  "C_Cpp.default.cppStandard": "c++20"
}
```

### Build System Configuration (CMake)

Create a `CMakeLists.txt` in your project root:

```cmake
cmake_minimum_required(VERSION 3.16)
project(MyProject VERSION 1.0.0 LANGUAGES CXX)

# Set C++20 as the required standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Define source files
set(SOURCES
    src/main.cpp
    # Add other source files here
)

# Add executable target
add_executable(${PROJECT_NAME} ${SOURCES})

# Include directories
target_include_directories(${PROJECT_NAME} PRIVATE include)

# Set output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Export compile commands for clangd
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
```

### VS Code Task Configuration

Create `.vscode/tasks.json` for build and run tasks:

```json
{
  "version": "2.0.0",
  "tasks": [
    {
      "label": "build",
      "type": "shell",
      "command": "clang++",
      "args": ["-std=c++20", "main.cpp", "-o", "myprogram"],
      "group": {
        "kind": "build",
        "isDefault": true
      }
    },
    {
      "label": "run",
      "type": "shell",
      "command": "./myprogram",
      "group": {
        "kind": "test",
        "isDefault": true
      },
      "dependsOn": ["build"]
    },
    {
      "label": "cmake build",
      "type": "shell",
      "command": "cmake --build build",
      "group": "build"
    },
    {
      "label": "run cmake build",
      "type": "shell",
      "command": "${workspaceFolder}/build/MyProject",
      "group": "test",
      "dependsOn": ["cmake build"]
    }
  ]
}
```

## Workflow

### Initial CMake Configuration

```bash
cmake -B build -S .
```

### Building the Project

Using CMake:

```bash
cmake --build build
```

Or directly with clang++ for simple projects:

```bash
clang++ -std=c++20 main.cpp -o myprogram
```

### Running the Project

CMake build:

```bash
./build/bin/MyProject
```

Direct build:

```bash
./myprogram
```

Or use VS Code tasks:

- `Ctrl+Shift+B` to build
- Use Command Palette (`Ctrl+Shift+P`) and run "Tasks: Run Test Task" to build and run

## Common C++20 Features

```cpp
#include <format>
#include <iostream>

int main() {
    std::string name = "Developer";
    std::cout << std::format("Hello, {}!\n", name);
    return 0;
}
```

## Project Organization

```bash
MyProject/
├── .vscode/               # VS Code configuration
├── .clangd                # clangd configuration
├── .gitignore             # Git ignore file
├── CMakeLists.txt         # CMake configuration
├── main.cpp               # Header files             # Source files
├── build/                 # Build directory (generated)
└── README.md              # Project documentation
```

## Notes

- Remember to use a `.gitignore` file to exclude build artifacts
- For professional C++ development, use CMake for complex projects
- Setting standards on a per-project basis is recommended for better portability
- VS Code tasks help streamline the build and run process

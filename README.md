# Game of Life 

A C++ implementation of [Conway's Game of Life](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life), rendered with [SFML 2.5.1](https://www.sfml-dev.org/).

Built as a project for the course [Data structures and Algorithms] at Algebra University, Zagreb (2022).


## 🛠️ Tech Stack

* C++
* Console (text-based) output

## How to Run

### Requirements

- Windows
- Visual Studio 2022 with the **Desktop development with C++** workload (platform toolset v143)

SFML is bundled in `SFML-2.5.1/`, so you don't need to install anything else.

### Build and run in Visual Studio

### 1. Clone the repository

```
git clone https://github.com/bkoren/game-of-life.git
cd game-of-life
```

1. Open `HomeWork_BrunoKoren.sln`.
2. Set the configuration to **Debug** and the platform to **x64**. This is the only configuration that links SFML.
3. Press **F5** (or **Ctrl+F5** to run without debugging).

A post-build step copies the required SFML DLLs into `x64\Debug\`.

### 2. Run the prebuilt executable

If the project has already been built, run it directly:

```
x64\Debug\HomeWork.exe
```

The SFML `*-d-2.dll` files and `openal32.dll` must stay in the same folder as the executable.

Close the window to exit.

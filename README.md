# DSA — Data Structures & Algorithms (Multi-language)

![DSA](https://img.shields.io/badge/DSA-multi--language-6f42c1) ![C++](https://img.shields.io/badge/C%2B%2B-Working_On-0078D7) ![Python](https://img.shields.io/badge/Python-Planned-ffd343) ![Java](https://img.shields.io/badge/Java-Planned-e11f21)

![Build](https://img.shields.io/badge/build-g%2B%2B%20%7C%20CMake-green) ![License](https://img.shields.io/badge/license-MIT-blue)

A practical, growing collection of fundamental data structures and algorithms implemented across multiple languages. Each language folder is self-contained with its own README, examples, and build/run steps.

## Languages
- C++: Implementations and demos (ready) → [CPP_DSA/](CPP_DSA/)
- Python: Coming soon 
- Java: Coming soon 

Note: Each language follows a consistent pattern: core implementation files plus small "App" demos that showcase usage.

## Repository structure

```
├── CPP_DSA/       # C++ implementations + demos (ready)
├── python/        # Python implementations + demos (planned)
├── java/          # Java implementations + demos (planned)
└── LICENSE        # License for the entire repository
```

## Quick start (C++)
See the C++ folder’s README for full details. Short version:

- Quick build with g++

```bash
g++ -std=c++11 -o output/main CPP_DSA/main.cpp && ./output/main
```

- CMake build

```bash
cmake -S CPP_DSA -B CPP_DSA/build
cmake --build CPP_DSA/build

# Run from repo root
./CPP_DSA/build/ADSA_24203

# Or from inside the build directory
cd CPP_DSA/build
./ADSA_24203
```

Notes:
- Some demos (e.g., Priority Queue) are interactive and prompt for input.
- Requires a C++11-capable compiler and CMake ≥ 3.10 if using CMake.

## What’s included (C++)
- Bag, Stack, Fixed-size Stack, Queue
- Priority Queue (heap-backed), Heapify
- Heap Sort (Bottom-Up and Top-Down) and more.
- Clean separation of core logic and demo apps

See details in [CPP_DSA/](CPP_DSA/).

## Roadmap
- Python: mirror C++ set (with tests and simple CLI demos)
- Java: mirror C++ set (using standard collections where helpful)
- Shared docs: complexity tables and cross-language comparisons
- CI: basic build/test matrices per language

## License
This repository is licensed under the MIT License. See the [LICENSE](./LICENSE) file for more details.

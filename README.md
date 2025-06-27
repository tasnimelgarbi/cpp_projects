# C++ Projects

This repository contains a collection of individual C++ mini-projects, each located in a separate Git branch. These projects were developed for learning and practice purposes using object-oriented and procedural programming concepts.

## Available Projects (Branches)

| Branch Name     | Description                          |
|------------------|--------------------------------------|
| `quran_player`   |Console-based Qur’an recitation player*| 
| `contact_book`   | Contact management system            |
| `calculater`     | Basic arithmetic calculator          |
| `employment`     | Simple employee record system        |
| `shapes`         | Area and perimeter calculator        |
| `chess_game`     | Console-based chess piece movement   |
| `name`           | Name formatting or related utility   |

## Technologies

- **Language:** C++
- **Compiler:** GCC / Clang / MSVC
- **Build tools:** `g++`, optional Makefiles


## Author

Tasnim Elgarbi – Zagazig University – Faculty of Computers and Information

## Hint
\* `quran_player` lists local `.mp3` files found in an `audio/` folder and plays the chosen recitation.  
Audio files are **not** included in the repository—see that branch’s README for download instructions.

## How to Use

To access any project:

```bash
git clone https://github.com/tasnimelgarbi/cpp_projects.git
cd cpp_projects
git checkout <branch-name>
g++ -std=c++17 *.cpp -o app
./app            # or .\app.exe on Windows


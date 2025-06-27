# Quran Player

A lightweight, console-based Qur’an recitation player written in modern C++.  
The application scans a local folder for MP3 files, lists the available recitations, and plays the one you select.

---

## Directory Structure

```text
quran_player/
├── src/            # C++ source files
├── bin/            # Compiled executable
├── audio/          # ADD YOUR MP3 FILES HERE 
└── README.md
```

---

## Audio Files (NOT included)

Large audio assets are excluded to keep the repository size small.

1. Download any MP3 recitations you prefer.  
2. Create an **`audio/`** folder in the project root.  
3. Copy your `.mp3` files into `audio/` (e.g. `001_fatiha.mp3`).  

> The program will list every `.mp3` inside `audio/` at runtime.

---

## Build

```bash
cd quran_player
g++ -std=c++17 -O2 src/*.cpp -o bin/quran_player
```

*Requires a C++17-compatible compiler (GCC 10+, Clang 12+, MSVC 19.28+).  
No external libraries.*

---

## Run

```bash
./bin/quran_player          # Linux / macOS
bin\quran_player.exe        # Windows
```

Sample session
```
[1] 001_fatiha.mp3
[2] 002_baqara.mp3
Select a number to play: 1
Playing 001_fatiha.mp3 …
```

The program spawns your OS default player; ensure MP3 playback is supported.

---

## Configuration

| Constant     | Purpose                              | File            |
|--------------|--------------------------------------|-----------------|
| `AUDIO_DIR`  | Relative path to the audio folder    | `constants.hpp` |
| `PLAYER_CMD` | Shell command used to play an MP3    | `player.cpp`    |

---

## Contributing

1. Fork the repository and create a feature branch.  
2. Keep each contribution self-contained and formatted with `clang-format`.  
3. **Do not commit audio files**; share a download link instead.  
4. Submit a pull request with a clear description of changes.

---

## License

MIT — see `LICENSE`.

---

## Author

team member \ FCI-ZU

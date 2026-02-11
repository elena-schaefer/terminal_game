# terminal_game
2D-game to run in terminal.
Player on a map that is chased by a monster.

---

## Project-Structure

.
├── assets/
│ ├── map.txt
├── build/
├── config/
│ ├── symbol.hpp
├── include/
│ ├── game.h
│ ├── ...
│ ├── spawnPoint.hpp
├── src/
│ ├── game
│ ├── player
│ ├── monster
│ ├── map
│ ├── renderer
│ └── main.cpp
├── CMakeLists.txt
└── README.md

---

## Branches

- Feature/add_monster:
  Implements a monster that chases player in through the map. 

---

## Build

```bash
mkdir build
cd build
cmake ..
cmake --build .
```

---

## Movement

WASD movement

- W - up
- A - left
- S - down
- D - right
- Q - quit

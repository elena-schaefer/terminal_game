# terminal_game
2D-game to run in terminal. <br>
Player on a map that has to collect all items to win the game and is chased by monster. <br>

---

## Project-Structure

```bash
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
```

---

## Branches

- Feature/add_monster: <br>
  Implements a monster that chases player through a map. 

- Feature/add_item: <br>
  Implements items that has to be collected by player. 

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

---

## Explainer 

'#' - wall <br>
'@' - player <br>
'M' - monster <br>
'o' - item <br>
'.' - floor <br>
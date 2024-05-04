# NODEPP-SQLITE
Run sqlite in Nodepp

## Dependencies
- libsqlite3-dev
  - 🪟: `pacman -S mingw-w64-ucrt-x86_64-sqlite3`
  - 🐧: `sudo apt install libsqlite3-dev`

## Compilation
`g++ -o main main.cpp -I ./include -lsqlite3 ; ./main`

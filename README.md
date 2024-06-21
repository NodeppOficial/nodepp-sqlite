# NODEPP-SQLITE
Run sqlite in Nodepp

## Dependencies
- libsqlite3-dev
  - 🪟: `pacman -S mingw-w64-ucrt-x86_64-sqlite3`
  - 🐧: `sudo apt install libsqlite3-dev`

## Example
```cpp
#include <nodepp/nodepp.h>
#include <sqlite.h>

using namespace nodepp;

void onMain() {

    sqlite_t db ("myDB.db");

    db.exec(R"(
        CREATE TABLE COMPANY(
        ID INT PRIMARY KEY     NOT NULL,
        NAME           TEXT    NOT NULL,
        AGE            INT     NOT NULL,
        ADDRESS        CHAR(50),
        SALARY         REAL );
    )");

    db.exec(R"(
        INSERT INTO COMPANY ( ID, NAME, AGE, ADDRESS, SALARY )
        VALUES (1, 'Paul', 32, 'California', 20000.00 );
    )");

    db.exec(R"(
        INSERT INTO COMPANY ( ID, NAME, AGE, ADDRESS, SALARY )
        VALUES (2, 'John', 32, 'California', 20000.00 );
    )");

    db.exec(R"(
        INSERT INTO COMPANY ( ID, NAME, AGE, ADDRESS, SALARY )
        VALUES (3, 'Mery', 32, 'California', 20000.00 );
    )");

    db.exec(R"(
        INSERT INTO COMPANY ( ID, NAME, AGE, ADDRESS, SALARY )
        VALUES (4, 'Pipi', 32, 'California', 20000.00 );
    )");

    db.exec("SELECT * from COMPANY",[]( sql_item_t args ){
        for( auto &x: args.keys() ){
             console::log( x, "->", args[x] );
        }
    });

}
```

## Compilation
`g++ -o main main.cpp -I ./include -lsqlite3 ; ./main`

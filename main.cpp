#include <nodepp/nodepp.h>
#include <sqlite.h>

using namespace nodepp;

void onMain() {

    sqlite_t db ("test.db");

    db.exec("SELECT * from COMPANY",[]( sql_item_t args ){
        for( auto &x: args.keys() ){
             console::log( x, "->", args[x] );
        }
    });

}
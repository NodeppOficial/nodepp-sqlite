#include <nodepp/nodepp.h>
#include <nodepp/fs.h>
#include <sqlite.h>

using namespace nodepp;

void onMain() {

    auto cin = fs::std_input();
    sqlite_t db ("myDB.db");

    cin.onData([=]( string_t data ){
        try {

        db.exec( data, []( sql_item_t args ){
            for( auto &x: args.keys() ){
                conio::log( x, "->", args[x], "-" );
            }   conio::log("\n");
        });

        } catch( except_t err ){
            console::error( err );
        }
    });
    
    stream::pipe( cin );

}
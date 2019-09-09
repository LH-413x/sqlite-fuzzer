//
// Created by Hao Liu on 2019-09-08.
//

#include <table.h>
#include <expr/cast_expr_as_generator.h>
#include <expr/literal_value_generator.h>
#include <expr/stc_generator.h>

void create_table(){
    std::string sql("CREATE TABLE IF NOT EXISTS \"albums\"\n"
                    "(\n"
                    "    [AlbumId] INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,\n"
                    "    [Title] NVARCHAR(160)  NOT NULL,\n"
                    "    [ArtistId] INTEGER  NOT NULL,\n"
                    "    FOREIGN KEY ([ArtistId]) REFERENCES \"artists\" ([ArtistId])\n"
                    "                ON DELETE NO ACTION ON UPDATE NO ACTION\n"
                    ");\n"
                    "CREATE INDEX [IFK_AlbumArtistId] ON \"albums\" ([ArtistId]);"
                    );
}

int main(){
    create_table();
    expr_generator expr(20);
    for(int i=0;i<0x10;i++)
        debug_print(expr.generate());

}
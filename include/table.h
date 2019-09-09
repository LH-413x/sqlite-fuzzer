//
// Created by Hao Liu on 2019-09-08.
//

#ifndef SQLITE_MUTATOR_TABLE_H
#define SQLITE_MUTATOR_TABLE_H
#include <iostream>
#include <vector>
class table{
private:
    std::string table_name;
    std::vector<std::string> columes;
    std::string schema_name;
public:
    table(std::string & tname, std::vector<std::string> & col):
            table_name(tname),columes(col){}
    std::string get_table_name(){
        return table_name;
    }
    std::vector<std::string> get_columes(){
        return columes;
    }
    std::string get_schema_name(){
        return schema_name;
    }
    virtual ~table()= default;
};
#endif //SQLITE_MUTATOR_TABLE_H

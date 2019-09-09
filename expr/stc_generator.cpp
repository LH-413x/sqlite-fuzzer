//
// Created by Hao Liu on 2019-09-09.
//

#include "expr/stc_generator.h"

std::string stc_generator::generate() {
    std::string stc;
    auto schema=tb->get_schema_name();
    auto name=tb->get_table_name();
    auto cols=tb->get_columes();
    return stc+"."+name+"."+cols[getRand() % cols.size()];
}

//
// Created by Hao Liu on 2019-09-09.
//

#include <expr/cast_expr_as_generator.h>
#include <expr/expr_generator.h>

std::string cast_expr_as_generator::generate() {
    std::string sql;
    append_word(sql,"CAST");
    append_word(sql, "(");
    std::shared_ptr<expr_generator> eg =
            std::make_shared<expr_generator>(cur_level-1);
    eg->generate();
    append_word(sql, "");
}
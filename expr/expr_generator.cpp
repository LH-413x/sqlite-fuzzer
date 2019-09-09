//
// Created by Hao Liu on 2019-09-09.
//

#include <expr/expr_generator.h>
#include <expr/literal_value_generator.h>
#include <expr/stc_generator.h>
#include <expr/cast_expr_as_generator.h>

std::shared_ptr<generator> expr_generator::get_expr_by_types(exprType name){
    int next_level=cur_level-1;
    std::shared_ptr<generator> gen;
    switch(name){
        case exprType::literal_value:
            gen=std::make_shared<literal_value_generator>(next_level);
            break;
        case exprType::schema_table_column:
            gen=std::make_shared<stc_generator>(next_level);
            break;
        case exprType::cast_EXPR_as:
            gen=std::make_shared<cast_expr_as_generator>(next_level);
            break;

    }
    return gen;
}

//todo: when level <= 0 return better than ""
std::string expr_generator::generate() {
    if(cur_level<=0){
    return std::string("");
    }
    exprType type=RAND_FROM(expr_types);
    std::shared_ptr<generator> gen=get_expr_by_types(type);
    return gen->generate();
}
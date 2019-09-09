//
// Created by Hao Liu on 2019-09-09.
//

#ifndef SQLITE_MUTATOR_GENERATOR_H
#define SQLITE_MUTATOR_GENERATOR_H


#include <utils.h>
#include <table.h>

enum exprType{
    literal_value,
    bind_parametor,
    schema_table_column,
    unary_operator_EXPR,
    EXPR_binary_operator_EXPR,
    function_distinct_EXPR,
    EXPR,
    cast_EXPR_as,
    EXPR_collact,
    EXPR_EXPR,
    EXPR_null,
    EXPR_is_EXPR,
    EXPR_between_EXPR,
    EXPR_in,
    select_stmt,
    case_when,
    raise_function,
    window_function
};

exprType expr_types[]{
        literal_value,
        //bind_parametor,
        schema_table_column,
        unary_operator_EXPR,
        EXPR_binary_operator_EXPR,
        function_distinct_EXPR,
        EXPR,
        cast_EXPR_as,
        EXPR_collact,
        EXPR_EXPR,
        EXPR_null,
        EXPR_is_EXPR,
        EXPR_between_EXPR,
        EXPR_in,
        select_stmt,
        case_when,
        raise_function,
        window_function
};

class generator{
public:
    virtual ~generator()=default;
    virtual std::string generate()=0;
};

#endif //SQLITE_MUTATOR_GENERATOR_H

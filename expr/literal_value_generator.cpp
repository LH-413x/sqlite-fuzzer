//
// Created by Hao Liu on 2019-09-09.
//

#include "expr/literal_value_generator.h"

const char* literal_values[]={
        "123",//number
        "\'aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\'",//string
        "x\'aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\'",//blob
        "NULL",
        "TRUE",
        "FALSE",
        "CURRENT_TIME",
        "CURRENT_DATE",
        "CURRENT_TIMESTAMP"
};

std::string literal_value_generator::generate() {
    return RAND_FROM(literal_values);
}

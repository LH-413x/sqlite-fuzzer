//
// Created by Hao Liu on 2019-09-09.
//

#ifndef SQLITE_MUTATOR_CAST_EXPR_AS_GENERATOR_H
#define SQLITE_MUTATOR_CAST_EXPR_AS_GENERATOR_H

#include <expr/generator.h>

class cast_expr_as_generator: public generator{
private:
    int cur_level;

public:
    explicit cast_expr_as_generator(int _level):cur_level(_level){}

    std::string generate() override ;
};

#endif //SQLITE_MUTATOR_CAST_EXPR_AS_GENERATOR_H

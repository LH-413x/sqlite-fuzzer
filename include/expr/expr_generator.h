//
// Created by Hao Liu on 2019-09-09.
//

#ifndef SQLITE_MUTATOR_EXPR_GENERATOR_H
#define SQLITE_MUTATOR_EXPR_GENERATOR_H

#include <expr/generator.h>

class expr_generator: public generator{
private:
    int cur_level;
public:
    explicit expr_generator(int level):cur_level(level){}
    std::shared_ptr<generator> get_expr_by_types(exprType name);
    //todo: when level <= 0 return better than ""
    std::string generate() override ;
};
#endif //SQLITE_MUTATOR_EXPR_GENERATOR_H

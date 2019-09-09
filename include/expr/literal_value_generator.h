//
// Created by Hao Liu on 2019-09-09.
//

#ifndef SQLITE_MUTATOR_LITERAL_VALUE_GENERATOR_H
#define SQLITE_MUTATOR_LITERAL_VALUE_GENERATOR_H

#include <expr/generator.h>

class literal_value_generator: public generator{
public:
    explicit literal_value_generator(int level):cur_level(level){}
    std::string generate() override ;
private:
    int cur_level;
};


#endif //SQLITE_MUTATOR_LITERAL_VALUE_GENERATOR_H

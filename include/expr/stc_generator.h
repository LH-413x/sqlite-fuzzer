//
// Created by Hao Liu on 2019-09-09.
//

#ifndef SQLITE_MUTATOR_STC_GENERATOR_H
#define SQLITE_MUTATOR_STC_GENERATOR_H

#include <expr/generator.h>

class stc_generator:public generator{
public:
    explicit stc_generator(int level):cur_level(level){}
    explicit stc_generator(std::shared_ptr<table> _tb):tb(std::move(_tb)){}
    std::string generate() override ;
private:
    int cur_level;
    std::shared_ptr<table> tb;
};


#endif //SQLITE_MUTATOR_STC_GENERATOR_H

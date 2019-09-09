//
// Created by Hao Liu on 2019-09-08.
//

#ifndef SQLITE_MUTATOR_GENERATOR_H
#define SQLITE_MUTATOR_GENERATOR_H

#include "utils.h"
class generator{
public:
    virtual ~generator()=default;
    virtual std::string generate()=0;
};

#endif //SQLITE_MUTATOR_GENERATOR_H

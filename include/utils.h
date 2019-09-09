//
// Created by Hao Liu on 2019-09-08.
//

#ifndef SQLITE_MUTATOR_UTILS_H
#define SQLITE_MUTATOR_UTILS_H

#include <iostream>
#include <string>
#include <vector>
#include <random>

inline int getRand(){
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> dis(0, 0x100);
    return dis(gen);
}

#define ELEM_NUM(a) sizeof((a))/sizeof((a)[0])
#define RAND_FROM(x) (x)[getRand()%ELEM_NUM((x))]

void debug_print(const std::string & s){
    std::cout << s << std::endl;
}

inline void append_word(std::string & sql, const char* word){
    sql+=word;
    sql+=" ";
}

inline void append_word(std::string & sql, const std::string & word){
    sql+=word;
    sql+=" ";
}


#endif //SQLITE_MUTATOR_UTILS_H

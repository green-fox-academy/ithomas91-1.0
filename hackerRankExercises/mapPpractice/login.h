//
// Created by Tamas Nemeth on 2019. 05. 03..
//
#include<vector>


#ifndef MAPPPRACTICE_LOGIN_H
#define MAPPPRACTICE_LOGIN_H

typedef struct
{
    std::vector<std::string> userName;
    std::vector<int> password;
    int numberOfUser;

}userData_t;

#endif //MAPPPRACTICE_LOGIN_H

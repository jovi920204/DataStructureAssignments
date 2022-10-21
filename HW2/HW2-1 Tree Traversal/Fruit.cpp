#pragma once
#include "Fruit.h"

Fruit::Fruit()
{
    _name = "apple";
    _number = 0;
}
Fruit::Fruit(string name, int number){
    _name = name;
    _number = number;
}
Fruit::~Fruit()
{
}

int Fruit::getNumber(){
    return _number;
}
string Fruit::getName(){
    return _name;
}
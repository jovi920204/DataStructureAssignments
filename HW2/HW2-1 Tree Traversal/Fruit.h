#pragma once
#include <iostream>
using namespace std;

class Fruit
{
private:
    string _name;
    int _number;
public:
    Fruit();
    Fruit(string name, int number);
    int getNumber();
    string getName();
    ~Fruit();
};

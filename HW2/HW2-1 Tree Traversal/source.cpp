#include <iostream>
#include "Fruit.cpp"
using namespace std;

int main(){
    Fruit box("apple", 5);
    cout << "The content of the box is " << box.getName() << endl;
    cout << "The number of content is " << box.getNumber() << endl;
    return 0;
}
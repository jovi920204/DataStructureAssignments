#include <iostream>
using namespace std;

struct Node{
    int num;
};

int toNumber(string str);

int main(){
    string str = "1 2 3 4 5 ";
    cout << str.substr(0,str.size());
    return 0;
}

int toNumber(string str){
    int len = str.size();
    int retNum = 0;
    for (int i=len-1, weight = 1;i>=0;i--, weight*=10){
        retNum += (str[i]-'0')*weight;
    }
    return retNum;
}
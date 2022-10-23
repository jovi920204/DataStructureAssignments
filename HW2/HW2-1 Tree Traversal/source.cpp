#include <iostream>
using namespace std;

struct Node{
    int num;
    Node* left;
    Node* right;
};

class Stack
{
private:
    Node* array[1000];
    int topIndex;
public:
    Stack(){ topIndex = -1; };
    ~Stack(){};
    void push(Node* node){
        array[++topIndex] = node;
    }
    void pop(){
        if (topIndex != -1){
            topIndex--;
        }
    }
    bool isEmpty(){
        if (topIndex != -1) return 0;
        return 1;
    }
    Node* top(){
        return array[topIndex];
    }
};

void insert(Node* node, int insertNum);
void inorder(Node* root);
int toNumber(string str);

int main(){
    string inputString;
    getline(cin, inputString);
    Node* root = nullptr;
    string numString = "";
    for (int i=0;i<inputString.size();i++){
        if (inputString[i] == ' '){
            insert(root, toNumber(numString));
            numString = "";
            continue;
        }
        numString += inputString[i];
    }
    inorder(root);
}

int toNumber(string str){
    int len = str.size();
    int retNum = 0;
    for (int i=len-1, weight = 1;i>=0;i--, weight*=10){
        retNum += (str[i]-'0')*weight;
    }
    return retNum;
}

void insert(Node* node, int insertNum){
    if (node == nullptr){
        node = new Node;
        node->num = insertNum;
        node->left = node->right = nullptr;
        return;
    }
    if (insertNum > node->num){ // put into right side
        insert(node->right, insertNum);
    }
    else{ // put into left side
        insert(node->left, insertNum);
    }
}

void inorder(Node* node){
    if (node == nullptr) return;
    inorder(node->left);
    cout << node->num;
    inorder(node->right);
}
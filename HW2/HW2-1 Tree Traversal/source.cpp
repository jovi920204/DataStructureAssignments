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

int main(){
    // int inputArray[1000];
    // int tmpNum;
    // int arrayIndex = 0;
    
    Node* root = new Node;
    for (int i=0;i<7;i++){
        int inputNum;
        cin >> inputNum;
        insert(root, inputNum);
    }
    inorder(root);
}

void insert(Node* node, int insertNum){
    if (node == nullptr){
        node->num = insertNum;
        return;
    }
    if (insertNum > node->num){ // put into right side
        if (node->right == nullptr){
            Node* insertNode = new Node;
            insertNode->num = insertNum;
            insertNode->left = nullptr;
            insertNode->right = nullptr;
            node->right = insertNode;
        }
        else{
            insert(node->right, insertNum);
        }
    }
    else{ // put into left side
        if (node->left == nullptr){
            Node* insertNode = new Node;
            insertNode->num = insertNum;
            insertNode->left = nullptr;
            insertNode->right = nullptr;
            node->left = insertNode;
        }
        else{
            insert(node->left, insertNum);
        }
    }
}

void inorder(Node* root){
    if (!root) return;
    Stack stk;
    Node* cur = root;
    while(cur || !stk.isEmpty()){
        cout << "top = " << stk.top()->num << endl;
        if (cur){
            stk.push(cur);
            cur = cur->left;
        }
        else{
            Node* node = stk.top();
            stk.pop();
            cout << node->num << " " << endl;
            cur = node->right;
        }
    
    }
}
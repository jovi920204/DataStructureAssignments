#include <iostream>
using namespace std;

struct Node{
    Node(int _num){
        num = _num;
        left = nullptr;
        right = nullptr;
    }
    int num;
    Node* left;
    Node* right;
};

int rotationCount = 0;
string rotationRecord = "";

int toNumber(string str);
Node* insertValue(Node* node, int insertNum);
int heightOfNode(Node* node);
int balanceFactor(Node* node);
Node* rotationJudge(Node* root);
void deleteValue(Node* node, int deleteNum);
Node* findLargestNode(Node* node);

int main(){
    string inputString;
    string numString = "";
    getline(cin, inputString);
    inputString += ",";
    Node* root = nullptr;
    for (int i=0;i<inputString.size();i++){
        if (inputString[i] == ','){
            root = insertValue(root, toNumber(numString));
            root = rotationJudge(root);
            numString = "";
            continue;
        }
        numString += inputString[i];
    }
    char type;
    int num;
    while(cin >> type >> num){
        if (type == 'I'){
            root = insertValue(root, num);
            root = rotationJudge(root);
        }
        else if (type == 'D'){
            deleteValue(root, num);
        }
        // cout << rotationCount << endl;
        // cout << rotationRecord;
    }
    cout << rotationCount << endl;
    cout << rotationRecord;
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

Node* insertValue(Node* node, int insertNum){
    if (node == nullptr){
        return new Node(insertNum);
    }
    if (insertNum > node->num){
        node->right = insert(node->right, insertNum);
    }
    else{
        node->left = insert(node->left, insertNum);
    }
    return node;
}

void deleteValue(Node* node, int deleteNum){
    if (node == nullptr){
        return;    
    }
    else if (deleteNum < node->num){ // goto left node
        deleteValue(node->left, deleteNum);
    }
    else if (deleteNum > node->num){
        deleteValue(node->right, deleteNum);
    }// deleteNum found!
    else if (node->left && node->right){ // has two child
        Node* temp  = findLargestNode(node->left);
        node->num = temp->num;
        deleteValue(node->left, temp->num);
    }
    else{
        Node* temp = node;
        if (node->left == nullptr && node->right == nullptr){
            node = nullptr;
        }
        else if (node->left){
            node = node->left;
        }
        else{
            node = node->right;
        }
        delete(temp);
    }
}

Node* findLargestNode(Node* node){
    if (node->right != nullptr) return findLargestNode(node->right);
    return node;
}

int heightOfNode(Node* node){
    if (!node) return 0;
    return max(heightOfNode(node->left), heightOfNode(node->right)) + 1;
}

int balanceFactor(Node* node){
    return heightOfNode(node->left) - heightOfNode(node->right);
}

Node* rotationJudge(Node* node){
    if (balanceFactor(node) >= 2){
        if (balanceFactor(node->left) >= 2) node->left = rotationJudge(node->left);
        else if(balanceFactor(node->left) == 1){
            // do LL rotation;
            rotationCount++;
            if (rotationRecord.size() != 0) rotationRecord += ",";
            rotationRecord += "LL";
            Node* bNode = node->left;
            node->left = bNode->right;
            bNode->right = node;
            return bNode;
        }
        else{
            // do LR rotation;
            rotationCount++;
            if (rotationRecord.size() != 0) rotationRecord += ",";
            rotationRecord += "LR";
            Node* bNode = node->left;
            Node* cNode = bNode->right;
            node->left = cNode->right;
            bNode->right = cNode->left;
            cNode->right = node;
            cNode->left = bNode;
            return cNode;
        }
    }
    else if (balanceFactor(node) <= -2){
        if (balanceFactor(node->right) <= -2) node->right = rotationJudge(node->right);
        else if (balanceFactor(node->right) == -1){
            // do RR;
            rotationCount++;
            if (rotationRecord.size() != 0) rotationRecord += ",";
            rotationRecord += "RR";
            Node* bNode = node->right;
            node->right = bNode->left;
            bNode->left = node;
            return bNode;
        }
        else{
            // do RL
            rotationCount++;
            if (rotationRecord.size() != 0) rotationRecord += ",";
            rotationRecord += "RL";
            Node* bNode = node->right;
            Node* cNode = bNode->left;
            node->right = cNode->left;
            bNode->left = cNode->right;
            cNode->right = bNode;
            cNode->left = node;
            return cNode;
        }
    }
    return node;
}

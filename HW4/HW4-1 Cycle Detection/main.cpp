#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool checkCycle(int sourceNode);

int main(){
    int nodeNumber;
    cin >> nodeNumber;
    vector<vector<int> > graph(nodeNumber);
    int startNode, endNode;
    while(cin >> startNode >> endNode){
        graph[startNode].push_back(endNode);
    }

    for (int i=0;i<nodeNumber;i++){
        cout << i << " : ";
        for (int j=0;j<graph[i].size();j++){
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }

    for (int i=0;i<nodeNumber;i++){
        if (checkCycle(i)){
            cout << "Cycle";
            break;
        }
    }
    cout << "No Cycle";
    

    return 0;
}

bool checkCycle(int sourceNode){
    // TODO
}

/*

3
0 1
1 2
2 0

*/
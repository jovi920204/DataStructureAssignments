#include <iostream>
#include <vector>
#include <string>
using namespace std;

int vertexNum;
int edgeNum;
vector<vector<int> > graph;

bool isFinished(vector<int>& visited, int vertexNum);

int main() {
    cin >> vertexNum >> edgeNum;
    graph.resize(vertexNum, vector<int>(vertexNum, 0));
    bool alphaFlag = 0;
    for (int i = 0; i < edgeNum; i++) {
        char startNode, endNode;
        int weight;
        cin >> startNode >> endNode >> weight;
        if (isdigit(startNode)) {
            alphaFlag = false;
            graph[atoi(&startNode)][atoi(&endNode)] = weight;
            graph[atoi(&endNode)][atoi(&startNode)] = weight;
        }
        else {
            alphaFlag = true;
            graph[startNode - 'A'][endNode - 'A'] = weight;
            graph[endNode - 'A'][startNode - 'A'] = weight;
        }
    }
    vector<int> predecessor(vertexNum,-1);
    vector<int> key(vertexNum, 10000000000);
    vector<int> visited(vertexNum,0);
    int currNode = 0;
    key[currNode] = 0;
    while (!isFinished(visited, vertexNum)) {
        // cout << "currNode = " << currNode << endl;
        visited[currNode] = 1;
        for (int i = 0; i < graph[currNode].size(); i++) {
            if (graph[currNode][i] == 0) {
                continue;
            }
            else {
                if (visited[i] == 0 && key[i] > graph[currNode][i]) {
                    predecessor[i] = currNode;
                    key[i] = graph[currNode][i];
                }
            }
        }
        int minLength = 10000000000;
        int nextNode = currNode;
        for (int i = 0; i < vertexNum; i++) {
             if (visited[i] == 0){
                if (minLength > key[i]) {
                    minLength = key[i];
                    nextNode = i;
                }
            }
        }
        currNode = nextNode;

        /*
        for (int i = 0; i < vertexNum; i++) {
            cout << i << " ";
        }
        cout << endl;
        for (int i = 0; i < vertexNum; i++) {
            cout << predecessor[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < vertexNum; i++) {
            cout << key[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < vertexNum; i++) {
            cout << visited[i] << " ";
        }
        cout << endl;
        cout << endl;
        */
    }

    // for (int i=0;i<graph[0].size();i++){
    //     for (int j=0;j<graph[i].size();j++){
    //         cout << graph[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    vector<vector<int> > MST(vertexNum, vector<int>(vertexNum, 0));
    int totalWeight = 0;
    for (int i = 1; i < vertexNum; i++) {
        int v1 = i;
        int v2 = predecessor[i];
        if (v1 < v2) {
            MST[v1][v2] = key[v1];
        }
        else {
            MST[v2][v1] = key[v1];
        }
        totalWeight += key[i];
    }
    cout << totalWeight << endl;
    int count = 0;
    for (int i = 0; i < vertexNum; i++) {
        for (int j = 0; j < vertexNum; j++) {
            if (MST[i][j] == 0) continue;
            if (alphaFlag == 1) {
                count++;
                cout << (char)(i + 'A') << " " << (char)(j + 'A') << " " << MST[i][j];
            }
            else {
                count++;
                cout << i << " " << j << " " << MST[i][j];
            }
            if (count < vertexNum - 1) {
                cout << endl;
            }
        }
    }
    return 0;
}

bool isFinished(vector<int>& visited, int vertexNum) {
    // cout << "Q" << endl;
    for (int i = 0; i < vertexNum; i++) {
        if (visited[i] == 0) {
            return 0;
        }
    }
    return 1;
}


/*
7 11
A B 6
B C 7
A D 4
D B 8
B E 6
C E 4
D F 5
F E 7
D E 14
E G 8
F G 10
*/

/*
7 11
0 1 5
0 5 3
5 4 6
1 4 1
1 6 4
4 6 2
1 2 10
6 2 8
4 3 7
6 3 9
3 2 5
*/
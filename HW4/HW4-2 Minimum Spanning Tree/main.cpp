#include <iostream>
#include <vector>
#include <string>
using namespace std;

int vertexNum;
int edgeNum;
vector<vector<int> > graph;

bool isFinished(int visited[], int vertexNum);

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
    int predecessor[26];
    int key[26] = { 0 };
    int visited[26] = { 0 };
    for (int i = 0; i < vertexNum; i++) {
        predecessor[i] = -1;
        key[i] = 10000000000;
        visited[i] = 0;
    }
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
                if (key[i] > graph[currNode][i]) {
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
        */
    }

    // for (int i=0;i<graph[0].size();i++){
    //     for (int j=0;j<graph[i].size();j++){
    //         cout << graph[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    int MST[26][26] = { {0} };
    int totalWeight = 0;
    for (int i = 0; i < vertexNum; i++) {
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
    for (int i = 0; i < vertexNum; i++) {
        for (int j = 0; j < vertexNum; j++) {
            if (MST[i][j] == 0) continue;
            if (alphaFlag == 1) {
                cout << (char)(i + 'A') << " " << (char)(j + 'A') << " " << MST[i][j] << endl;
            }
            else {
                cout << i << " " << j << " " << MST[i][j] << endl;
            }
        }
    }
    return 0;
}

bool isFinished(int visited[], int vertexNum) {
    // cout << "Q" << endl;
    for (int i = 0; i < vertexNum; i++) {
        if (visited[i] == 0) {
            return 0;
        }
    }
    return 1;
}
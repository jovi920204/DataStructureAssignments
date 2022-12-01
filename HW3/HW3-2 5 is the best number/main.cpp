#include <iostream>
#include <vector>
#include <string>
using namespace std;

void bubble_sort(vector<int>& data);
void insertion_sort(vector<int>& data);

int main(){
    vector<int> data;
    int temp;
    while(cin >> temp){
        data.push_back(temp);
    }
    // for (auto val : data){
    //     cout << val << " ";
    // }
    // cout << endl;
    bubble_sort(data);
    return 0;
}
// 21 24 28 15 20 19 30 41 20 28 13 12 33 25 7
void bubble_sort(vector<int>& data){
    int a, b;
    int count = 0;
    for(int i=0;i<data.size();i++){
        for (int j=0;j<data.size()-i-1;j++){
            if (data[j] > data[j+1]){
                count++;
                int temp = data[j];
                data[j] = data[j+1];
                data[j+1] = temp;
                a = data[j];
                b = data[j+1];
            }
            if (count == 5){
                break;
            }
        }
        if (count == 5){
            break;
        }
    }
    cout << "Bubble: " << a << ", " << b << "; ";
    for (int i=0;i<data.size()-1;i++){
        cout << data[i] << " ";
    }
    cout << data[data.size()-1] << endl;
}

void insertion_sort(vector<int>& data){

}
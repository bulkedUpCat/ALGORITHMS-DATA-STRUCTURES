#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> warshall(vector<vector<int>> adj){
    vector<vector<int>> result = adj;

    for (int k = 0; k < adj.size(); k++){
        for (int i = 0; i < adj.size(); i++){
            for (int j = 0; j < adj[i].size(); j++){
                result[i][j] |= result[i][k] & result[k][j];
            }
        }
    }

    return result;
}

int main(){
    vector<vector<int>> adj{ 
        {0, 1, 0, 0}, 
        {0, 0, 0, 1}, 
        {0, 0, 0, 0}, 
        {1, 0, 1, 0}};
    vector<vector<int>> result = warshall(adj);

    for (int i = 0; i < result.size(); i++){
        for (int j = 0; j < result[i].size(); j++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
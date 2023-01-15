#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> floyd_warshall(vector<vector<int>> adj){
    vector<vector<int>> result = adj;

    for (int k = 0; k < adj.size(); k++){
        for (int i = 0; i < adj.size(); i++){
            for (int j = 0; j < adj[i].size(); j++){
                result[i][j] = min(result[i][j], result[i][k] + result[k][j]);
            }
        }
    }

    return result;
}

int main(){
    const int INF = int(1e6);
    vector<vector<int>> adj{ 
        {0, INF, 3, INF}, 
        {2, 0, INF, INF}, 
        {INF, 7, 0, 1}, 
        {6, INF, INF, 0}};
    vector<vector<int>> result = floyd_warshall(adj);

    for (int i = 0; i < result.size(); i++){
        for (int j = 0; j < result[i].size(); j++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
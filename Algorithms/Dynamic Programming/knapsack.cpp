#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int knapsack(vector<int> weights, vector<int> prices, int capacity){
    vector<vector<int>> dp(weights.size() + 1);

    for (int i = 0; i < weights.size() + 1; i++){
        vector<int> row(capacity + 1);
        dp[i] = row;
    }

    for (int i = 1; i < dp.size(); i++){
        for (int j = 1; j < dp[i].size(); j++){
            if (weights[i - 1] > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weights[i - 1]] + prices[i - 1]);
            }
        }
    }

    return dp[weights.size()][capacity];
}

int bounded_knapsack(vector<int> weights, vector<int> prices, vector<int> quantity, int capacity){
    vector<vector<int>> dp(weights.size() + 1);

    for (int i = 0; i < weights.size() + 1; i++){
        vector<int> row(capacity + 1);
        dp[i] = row;
    }

    for (int i = 1; i < dp.size(); i++){
        for (int j = 1; j < dp[i].size(); j++){
            for (int k = 0; k < min(quantity[i - 1] + 1, j / weights[i - 1] + 1); k++){
                dp[i][j] = max(dp[i][j], dp[i - 1][j - k * weights[i - 1]] + k * prices[i - 1]);
            }
        }
    }

    return dp[weights.size()][capacity];
}

int unbounded_knapsack(vector<int> weights, vector<int> prices, int capacity){
    vector<int> dp(capacity + 1);

    for (int j = 1; j < capacity + 1; j++){
        for (int i = 0; i < weights.size(); i++){
            if (weights[i] <= j){
                dp[j] = max(dp[j], dp[j - weights[i]] + prices[i]);
            }
        }
    }  

    return dp[capacity];
}

int main(){
    vector<int> weights = { 10, 20, 30 };
    vector<int> prices = { 60, 100, 120 };
    vector<int> quantity = {3, 1, 1};
    int capacity = 50;

    int answer1 = knapsack(weights, prices, capacity);
    cout << answer1 << endl;

    int answer2 = unbounded_knapsack(weights, prices, capacity);
    cout << answer2 << endl;

    int answer3 = bounded_knapsack(weights, prices, quantity, capacity);
    cout << answer3;

    return 0;
}
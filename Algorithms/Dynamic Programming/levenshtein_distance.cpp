#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int levenshtein_distance(
    string a, 
    string b)
{
    char* arr_a = new char(a.length());
    char* arr_b = new char(b.length());

    strcpy(arr_a, a.c_str());
    strcpy(arr_b, b.c_str());

    vector<vector<int>> dp(a.length() + 1);

    for (int i = 0; i < a.length() + 1; i++){
        vector<int> row(b.length() + 1);
        dp[i] = row;
    }

    for (int i = 1; i < a.length() + 1; i++){
        dp[i][0] = i;
    }

    for (int i = 1; i < b.length() + 1; i++){
        dp[0][i] = i;
    }

    for (int i = 1; i < dp.size(); i++){
        for (int j = 1; j < dp[i].size(); j++){
            if (arr_a[i - 1] == arr_b[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = min(
                    min(
                        dp[i - 1][j] + 1,
                        dp[i][j - 1] + 1
                    ),
                    dp[i - 1][j - 1] + 1
                );
            }
        }
    }

    return dp[a.length()][b.length()];
}

int main(){
    string a = "sunday";
    string b = "saturday";
    
    int result = levenshtein_distance(a, b);
    cout << result;
    return 0;
}
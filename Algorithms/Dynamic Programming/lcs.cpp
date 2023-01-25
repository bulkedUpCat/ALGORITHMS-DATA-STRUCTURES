#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int lcs(string a, string b){
    char* arr_a = new char(a.length());
    char* arr_b = new char(b.length());

    strcpy(arr_a, a.c_str());
    strcpy(arr_b, b.c_str());

    vector<vector<int>> dp(a.size() + 1);

    for (int i = 0; i < a.length() + 1; i++){
        vector<int> row(b.length() + 1);
        dp[i] = row;
    }

    for (int i = 1; i < a.length() + 1; i++){
        for (int j = 1; j < b.length() + 1; j++){
            char ch_a = arr_a[i - 1];
            char ch_b = arr_b[j - 1];

            if (ch_a == ch_b)
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[a.length()][b.length()];
}

int main(){
    string a = "EBTBCADF";
    string b = "ABBCDGF";

    int result = lcs(a, b);
    cout << result;
    return 0;
}
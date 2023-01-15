#include <iostream>
#include <vector>

using namespace std;

int binomial_coefficient(int n, int m)
{
    vector<vector<int>> vec(n + 1);
    
    for (int i = 0; i < n + 1; i++)
    {
        vector<int> v1(n + 1);
        v1[0] = 1;
        vec[i] = v1;
        vec[i][i] = 1;
    }

    for (int i = 2; i < n + 1; i++)
    {
        for (int j = 1; j < i; j++)
        {
            vec[i][j] = vec[i - 1][j - 1] + vec[i - 1][j];
        }
    }

    return vec[n][m];
}

int main(){
    int result = binomial_coefficient(4, 2);
    cout << result;
    return 0;
}
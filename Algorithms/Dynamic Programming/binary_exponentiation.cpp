#include <iostream>

using namespace std;

int binary_exponentiation(long long a, long long b){
    long long result = 1;

    while (b > 0)
    {
        if (b & 1)
        {
            result *= a;
        }

        a = a * a;
        b >>= 1;
    }

    return result;
}

int main(){
    long long result = binary_exponentiation(3, 13);
    cout << result;
    return 0;
}
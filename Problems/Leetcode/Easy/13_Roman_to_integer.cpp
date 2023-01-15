#include <map>

class Solution {
public:
    int romanToInt(string s) {
        int result = 0;
        map<char, int> letters = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}};
        
        for (int i = 0; i < s.size(); i++){
            if (letters[s[i]] >= letters[s[i+1]]){
                result += letters[s[i]];
            }
            else{
                result -= letters[s[i]];
            }
        }

        return result;
    }
};
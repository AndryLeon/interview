#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> hash;
        hash['I'] = 1;
        hash['V'] = 5;
        hash['X'] = 10;
        hash['L'] = 50;
        hash['C'] = 100;
        hash['D'] = 500;
        hash['M'] = 1000;

        int r = 0;
        for(int i = s.size()-1; i >= 0; --i){
            if(i == s.size()-1){
                r = hash[s[i]];
                continue;
            }
            if(hash[s[i]] < hash[s[i+1]]){
                r -= hash[s[i]];
            }else{
                r += hash[s[i]];
            }
        }
        return r;
    }
};

int main(){
    Solution s;
    cout << s.romanToInt("IV");
}

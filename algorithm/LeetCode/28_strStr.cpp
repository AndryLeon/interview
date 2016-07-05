#include <iostream>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int sz = needle.size();
        bool jug = true;
        for(int i = 0; i+sz <= haystack.size(); ++i){
            jug = true;
            for(int j = 0; j < sz; ++j){
                if(haystack[i+j] != needle[j]){
                    jug = false;
                    break;
                }
            }
            if(jug)
                return i;
        }
        return -1;
    }
};

int main(){
    Solution s;
    cout << s.strStr("hello", "ello");
}

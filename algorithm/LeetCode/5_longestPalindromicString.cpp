#include <vector>
#include <iostream>

using namespace std;

//O(n2)
class Solution{
public:
    string longestPalindrome(string s) {
        int sizes = s.size();
        string v(2*sizes+1, '*');
        for(int i = 0; i < sizes; ++i){
            v[2*i+1] = s[i];
        }
        int mx = 0;
        string ans;
        sizes = 2*sizes+1;
        for(int i = 0;i < sizes; ++i){
            int len = 0;
            while(i-len >= 0 && i+len < sizes && v[i-len] == v[i+len])
                ++len;
            --len;
            if(len > mx){
                mx = len;
                ans = s.substr((i-len)/2, (i+len)/2-(i-len)/2);
            }
        }
        return ans;
    }
};

int main(){
    Solution s;
    cout << s.longestPalindrome("asfsds");
}

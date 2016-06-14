#include <vector>
#include <string>
#include <iostream>

using namespace std;

//O(n)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> hash(128, -1);
        int mx = 0, last = -1;
        for(int i = 0; i < s.size(); i++){
            last = max(last, hash[s[i]]);
            mx = max(mx, i-last);
            hash[s[i]] = i;
        }
        return mx;
    }
};

int main(){
    Solution s;
    cout << s.lengthOfLongestSubstring("abcabcbb") << endl;
}

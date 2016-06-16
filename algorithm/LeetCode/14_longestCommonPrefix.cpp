#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() <= 1)
            return strs.size() == 0? "" : strs[0];
        string cmpStr = strs[0];
        for(int i = 1; i < strs.size(); ++i){
            if(cmpStr.size() > strs[i].size()){
                cmpStr = strs[i];
            }
        }
        for(int i = 0; i < cmpStr.size(); ++i){
            for(int j = 0; j < strs.size(); ++j){
                if(strs[j][i] != cmpStr[i]){
                    return cmpStr.substr(0, i);
                }
            }
        }
        return cmpStr;
    }
};

int main(){
    Solution s;
    vector<string> strs{"adc", "adcc", "adb"};
    cout << s.longestCommonPrefix(strs);
}

#include <iostream>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int right = 0, left = 0, cnt = 0, res = 0;
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == '('){
                left++;
                cnt++;
            }else{
                cnt--;
            }
            if(cnt == 0){
                res = max(res, left);
            }else if(cnt < 0){
                left = cnt = 0;
            }
        }

        cnt = 0;
        for(int i = s.size()-1; i >= 0; --i){
            if(s[i] == ')'){
                right++;
                cnt++;
            }else{
                cnt--;
            }
            if(cnt == 0){
                res = max(res, right);
            }else if(cnt < 0){
                right = cnt = 0;
            }
        }
        return res*2;
    }
};

int main(){
    Solution s;
    cout << s.longestValidParentheses(")()())");
}

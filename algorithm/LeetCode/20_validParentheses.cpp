#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> sta;
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')
                sta.push(s[i]);
            else{
                if(!sta.empty() && ((sta.top() == '(' && s[i] == ')') || (sta.top() == '[' && s[i] == ']') || (sta.top() == '{' && s[i] == '}')))
                    sta.pop();
                else
                    return false;
            }
        }
        if(sta.empty())
            return true;
        return false;
    }
};

int main(){
    Solution s;
    cout << s.isValid("[]())");
}

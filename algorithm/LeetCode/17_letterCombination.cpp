#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.size() == 0)
            return res;
        unordered_map<char, string> m;
        m['2'] = "abc";
        m['3'] = "def";
        m['4'] = "ghi";
        m['5'] = "jkl";
        m['6'] = "mno";
        m['7'] = "pqrs";
        m['8'] = "tuv";
        m['9'] = "wxyz";
        queue<string> q;
        for(int j = 0; j < m[digits[0]].size(); ++j){
            string s;
            s += m[digits[0]][j];
            q.push(s);
        }
        int i = 1;
        while(i < digits.size()){
            string tmp = q.front();
            if(tmp.size() != i){
                ++i;
                continue;
            }
            q.pop();
            for(int j = 0; j < m[digits[i]].size(); ++j){
                q.push(tmp + m[digits[i]][j]);
            }
        }
        while(!q.empty()){
            res.push_back(q.front());
            q.pop();
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<string> v = s.letterCombinations("9527");
    for(int i = 0; i < v.size(); ++i){
        cout << v[i] << " ";
    }
}

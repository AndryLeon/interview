#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void dfs(vector<string>& res, string str, int cntL, int cntR, int n){
        if(cntL < cntR || cntL > n)
            return;
        if(cntL == n && cntR == n){
            res.push_back(str);
            return;
        }
        dfs(res, str+"(", cntL+1, cntR, n);
        dfs(res, str+")", cntL, cntR+1, n);
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        dfs(res, "", 0, 0, n);
        return res;
    }
};

int main(){
    Solution s;
    vector<string> res = s.generateParenthesis(3);
    for(auto a : res){
        cout << a << endl;
    }
    return 0;
}

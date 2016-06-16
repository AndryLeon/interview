#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>

using namespace std;

class Solution {
public:
/*
    //当s长度为0时， p只能为0或’A*B*'
    //对'*'需要特殊处理
    //递归+记忆
    bool isMatch(string s, string p){
        vector<vector<bool>> v(s.size()+1, vector<bool>(p.size()+1, false));
        vector<vector<bool>> isVisit(s.size()+1, vector<bool>(p.size()+1, false));
        return isMatched(s, p, v, isVisit);
    }

    bool isMatched(string s, string p, vector<vector<bool>>& v, vector<vector<bool>>& isVisit) {
        int sizes = s.size(), sizep = p.size();
        if(isVisit[sizes][sizep]){
            return v[sizes][sizep];
        }

        if(0 == sizes){
            if(1 & sizep){
                isVisit[sizes][sizep] = true;
                v[sizes][sizep] = false;
                return false;
            }else{
                for(int i = 1; i < p.size(); i += 2){
                    if(p[i] != '*'){
                        isVisit[sizes][sizep] = true;
                        v[sizes][sizep] = false;
                        return false;
                    }
                }
            }
            isVisit[sizes][sizep] = true;
            v[sizes][sizep] = true;
            return true;
        }
        if(0 == sizep){
            isVisit[sizes][sizep] = true;
            v[sizes][sizep] = false;
            return false;
        }
        if(sizep > 1 && p[1] == '*'){
            if(p[0] == '.' || p[0] == s[0]){
                isVisit[sizes][sizep] = true;
                v[sizes][sizep] = isMatched(s, p.substr(2), v, isVisit) || isMatched(s.substr(1), p, v, isVisit);
                return v[sizes][sizep];
            }else{
                isVisit[sizes][sizep] = true;
                v[sizes][sizep] = isMatched(s, p.substr(2), v, isVisit);
                return v[sizes][sizep];
            }
        }else{
            if(p[0] == '.' || p[0] == s[0]){
                isVisit[sizes][sizep] = true;
                v[sizes][sizep] = isMatched(s.substr(1), p.substr(1), v, isVisit);
                return v[sizes][sizep];
            }else{
                isVisit[sizes][sizep] = true;
                v[sizes][sizep] = false;
                return false;
            }
        }
    }
*/
/*
    //递归
    bool isMatch(string s, string p) {
        if(0 == s.size()){
            if(1 & p.size())
                return false;
            else{
                for(int i = 1; i < p.size(); i += 2){
                    if(p[i] != '*')
                        return false;
                }
            }
            return true;
        }
        if(0 == p.size())
            return false;
        if(p.size() > 1 && p[1] == '*'){
            if(p[0] == '.' || p[0] == s[0])
                return isMatch(s, p.substr(2)) || isMatch(s.substr(1), p);
            else
                return isMatch(s, p.substr(2));
        }else{
            if(p[0] == '.' || p[0] == s[0])
                return isMatch(s.substr(1), p.substr(1));
            else
                return false;
        }
    }
*/
    //dp
    bool isMatch(string s, string p){
        int sizes = s.size(), sizep = p.size();
        if(sizes == 0 || sizep == 0)
            return sizes == 0 && sizep == 0;
        vector<vector<bool>> dp(sizes+1, vector<bool>(sizep+1, false));
        dp[0][0] = true;
        for(int j = 1;j <= sizep; ++j){
            if('*' == p[j-1]){
                dp[0][j] = dp[0][j-2];
            }
        }
        for(int i = 1; i <= sizes; ++i){
            for(int j = 1; j <= sizep; ++j){
                if(p[j-1] == '.')
                    dp[i][j] = dp[i-1][j-1];
                else if(p[j-1] == '*'){
                    dp[i][j] = dp[i][j-2] || dp[i][j-1] || (dp[i-1][j] && (p[j-2] == '.' || s[i-1] == p[j-2]));
                }else{
                    dp[i][j] = dp[i-1][j-1] && s[i-1] == p[j-1];
                }
            }
        }
        return dp[sizes][sizep];
    }

};

int main(){
    Solution s;
    cout << s.isMatch("aab", "c*a*b") << endl;
    cout << s.isMatch("aaa","aa") << endl;
    cout << s.isMatch("aa", ".*") << endl;
    cout << s.isMatch("aa", "a*") << endl;
}

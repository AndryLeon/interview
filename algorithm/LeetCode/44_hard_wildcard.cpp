#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
/*
    解法1
    //递归+记忆
    bool isMatch(string s, string p){
        string p1;
        char last = '#';
        for(int i = 0; i < p.size(); ++i){
            if(last != '*'){
                last = p[i];
                p1 += p[i];
            }else{
                if(p[i] != '*'){
                    last = p[i];
                    p1 += p[i];
                }
            }
        }
        vector<vector<bool>> v(s.size()+1, vector<bool>(p1.size()+1, false));
        vector<vector<bool>> isVisit(s.size()+1, vector<bool>(p1.size()+1, false));
        return isMatched(s, p1, v, isVisit);
    }
    bool isMatched(string s, string p, vector<vector<bool>>& v, vector<vector<bool>>& isVisit) {
        int sizes = s.size(), sizep = p.size();
        if(isVisit[sizes][sizep]){
            return v[sizes][sizep];
        }
        if(sizes == 0){
            if(sizep == 0){
                isVisit[sizes][sizep] = true;
                v[sizes][sizep] = true;
                return true;
            }else{
                for(int i = 0; i < p.size(); ++i){
                    if(p[i] != '*'){
                        isVisit[sizes][sizep] = true;
                        v[sizes][sizep] = false;
                        return false;
                    }
                }
                isVisit[sizes][sizep] = true;
                v[sizes][sizep] = false;
                return false;
            }
        }

        if(sizep == 0){
            isVisit[sizes][sizep] = true;
            v[sizes][sizep] = false;
            return false;
        }

        if(p[0] == '?' || p[0] == s[0]){
            isVisit[sizes][sizep] = true;
            v[sizes][sizep] = isMatched(s.substr(1), p.substr(1), v, isVisit);
            return v[sizes][sizep];
        }else if(p[0] == '*'){
            isVisit[sizes][sizep] = true;
            v[sizes][sizep] =isMatched(s.substr(1), p, v, isVisit) || isMatched(s, p.substr(1), v, isVisit);
            return v[sizes][sizep];
        }else{
            isVisit[sizes][sizep] = true;
            v[sizes][sizep] = false;
            return false;
        }
    }
*/
/*
    //解法2
    //递归
    bool isMatch(string s, string p){
        string p1;
        char last = '#';
        for(int i = 0; i < p.size(); ++i){
            if(last != '*'){
                last = p[i];
                p1 += p[i];
            }else{
                if(p[i] != '*'){
                    last = p[i];
                    p1 += p[i];
                }
            }
        }
        return isMatched(s, p1);
    }
    bool isMatched(string s, string p) {
        if(s.size() == 0){
            if(p.size() == 0){
                return true;
            }else{
                for(int i = 0; i < p.size(); ++i){
                    if(p[i] != '*')
                        return false;
                }
                return true;
            }
        }

        if(p.size() == 0)
            return false;
        if(p[0] == '?' || p[0] == s[0]){
            return isMatched(s.substr(1), p.substr(1));
        }else if(p[0] == '*'){
            return isMatched(s.substr(1), p) || isMatched(s, p.substr(1));
        }else{
            return false;
        }
    }
*/
    //解法3
    //回溯
    bool isMatch(string s, string p){
        int sizes = s.size(), sizep = p.size();
        int i = 0, j = 0, stari, starj;
        bool hasStar = false;
        while(i < sizes){
            if(p[j] == '?'){
                ++i;
                ++j;
            }else if(p[j] == '*'){
                stari = i;
                starj = ++j;
                hasStar = true;
            }else{
                if(s[i] == p[j]){
                    ++i;
                    ++j;
                }else if(hasStar){
                    j = starj;
                    i = ++stari;
                }else
                    return false;
            }
        }
        while(p[j] == '*')
            ++j;
        if(j != sizep)
            return false;
        return true;
    }
};

int main(){
    Solution s;
    cout << s.isMatch("babaaababaabababbbbbbaabaabbabababbaababbaaabbbaaab", "***bba**a*bbba**aab**b") <<endl;
}

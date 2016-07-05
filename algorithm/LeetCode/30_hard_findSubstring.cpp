#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> hash;
        vector<int> res;
        int sz = words.size();
        if(sz == 0){
            return res;
        }
        for(int i = 0; i < words.size(); ++i){
            if(hash.find(words[i]) == hash.end()){
                hash[words[i]] = 1;
            }else{
                ++hash[words[i]];
            }
        }

        int len = words[0].size();
        for(int i = 0; i < len; ++i){
            unordered_map<string, int> get;
            int cnt = 0;
            for(int j = i; j+len <= s.size(); j += len){
                string tmp = s.substr(j, len);
                if(hash.find(tmp) == hash.end()){
                    get.clear();
                    cnt = 0;
                }else{
                    cnt++;
                    if(get.find(tmp) == get.end()){
                        get[tmp] = 1;
                    }else{
                        ++get[tmp];
                    }

                    while(hash[tmp] < get[tmp]){
                        string rm = s.substr(j-(cnt-1)*len, len);
                        --get[rm];
                        --cnt;
                    }
                    if(cnt == sz){
                        res.push_back(j-(cnt-1)*len);
                    }
                }
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    string str = "wordgoodgoodgoodbestword";
    vector<string> v{"word","good","best","good"};
    vector<int> res = s.findSubstring(str, v);
    for( auto a : res) {
        cout << a << " ";
    }
}

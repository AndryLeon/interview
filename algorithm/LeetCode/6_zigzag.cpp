#include <iostream>

using namespace std;

//O(n)
class Solution {
public:
    string convert(string s, int numRows) {
        if(1 >= numRows){
            return s;
        }
        int sz = s.size();
        string r;
        for(int i = 0; i < numRows; ++i){
            for(int j = i; j < sz; j += 2*numRows-2){
                r += s[j];
                if(0 < i && i < numRows-1 && j+(numRows-1-i)*2 < sz){
                    r += s[j+(numRows-1-i)*2];
                }
            }
        }
        return r;
    }
};

int main(){
    Solution s;
    cout << s.convert("PAYPALISHIRING", 3);
}

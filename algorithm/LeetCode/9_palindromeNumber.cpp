#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        int tmp = 0, r = x;
        while(r){
            tmp = 10*tmp + r%10;
            r /= 10;
        }
        if(tmp != x)
            return false;
        return true;
    }
};

int main(){
    Solution s;
    cout << s.isPalindrome(12321);
}

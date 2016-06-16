#include <iostream>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        int r = 0;
        while(x){
            if((10*r)/10 != r)
                return 0;
            r = 10*r + x%10;
            x /= 10;
        }
        return r;
    }
};

int main(){
    Solution s;
    cout << s.reverse(-321);
}

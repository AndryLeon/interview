#include <iostream>
#include <limits.h>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        int res = 0;
        if(0 == divisor)
            return INT_MAX;
        if(dividend == INT_MIN && divisor == -1){
            return INT_MAX;
        }
        if(dividend == INT_MIN){
            res = 1;
            dividend += abs(divisor);
        }
        if(divisor == INT_MIN)
            return res;
        int sign = 1;
        if(dividend<0) sign = -sign;
        if(divisor<0) sign = -sign;
        dividend = abs(dividend);
        divisor = abs(divisor);
        int digit = 0;
        while(divisor <= (dividend>>1)){
            digit++;
            divisor <<= 1;
        }
        while(digit >= 0){
            if(dividend >= divisor){
                res += 1<<digit;
                dividend -= divisor;
            }
            divisor >>= 1;
            --digit;
        }
        return sign > 0? res:-res;
    }
};

int main(){
    Solution s;
    cout << s.divide(10,4);
}

#include <iostream>
#include <limits.h> // not limits

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int sz = str.size();
        int k = 0;
        bool neg = false;
        while(k < sz && isspace(str[k]))
            k++;
        if('+' == str[k]){
            k++;
        }else if('-' == str[k]){
            neg = true;
            k++;
        }
        int r = 0;
        while( k < sz && isdigit(str[k]) ){
            int d = str[k] - '0';
            if(neg){
                if(r < (INT_MIN + d)/10){
                    return INT_MIN;
                }
                r = 10*r - d;
            }else{
                if(r > (INT_MAX - d)/10){
                    return INT_MAX;
                }
                r = 10*r + d;
            }
            k++;
        }
        return r;
    }
};

int main(){
    Solution s;
    cout << s.myAtoi("1");
}


#include <iostream>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string c[4][10]={{"0","I","II","III","IV","V","VI","VII","VIII","IX"},{"0","X","XX","XXX","XL","L","LX"
            ,"LXX","LXXX","XC"},{"0","C","CC","CCC","CD","D",
            "DC","DCC","DCCC","CM"},{"0","M","MM","MMM"}};
        int t=1;
        int tmp=num;
        string st;
        if(tmp/1000 != 0) st += c[3][tmp/1000];
        if((tmp%1000)/100 != 0) st += c[2][(tmp%1000)/100];
        if((tmp%100)/10 != 0) st += c[1][(tmp%100)/10];
        if(tmp%10 != 0) st += c[0][tmp%10];
        return st;
    }
};

int main(){
    Solution s;
    cout << s.intToRoman(123);

}

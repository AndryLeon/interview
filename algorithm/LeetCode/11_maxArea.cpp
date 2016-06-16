#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size()-1;
        int mx = INT_MIN;
        while(i < j){
            mx = max(min(height[i], height[j])*(j-i), mx);
            if(height[i] > height[j]){
                --j;
            }else{
                ++i;
            }
        }
        return mx;
    }
};

int main(){
    Solution s;
    vector<int> v{2,3,4,5,6,1};
    cout << s.maxArea(v);
}

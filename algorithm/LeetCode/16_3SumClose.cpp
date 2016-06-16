#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int close = INT_MAX;
        int res = 0;
        int i = 0;
        sort(nums.begin(), nums.end());
        while(i < nums.size()){
            int j = i+1, k = nums.size()-1;
            while(j < k){
                if(abs(target - nums[i]-nums[j]-nums[k]) < close){
                    close = abs(target - nums[i]-nums[j]-nums[k]);
                    res = nums[i]+nums[j]+nums[k];
                }
                if(nums[i]+nums[j]+nums[k] > target){
                    --k;
                }else if(nums[i]+nums[j]+nums[k] < target){
                    ++j;
                }else{
                    return target;
                }
                int tmp = nums[j];
                while(++j < nums.size() && nums[j] == tmp);
            }
            int tmp = nums[i];
            while(++i < nums.size() && nums[i] == tmp);
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> v{-1, 2, 1, -4};
    cout << s.threeSumClosest(v, 1);
}

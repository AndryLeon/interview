#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int i = 0;
        while(i < nums.size()){
            int j = i+1, k = nums.size()-1;
            while(j < k){
                if(nums[i] + nums[j] + nums[k] < 0){
                    ++j;
                }else if(nums[i] + nums[j] + nums[k] > 0){
                    --k;
                }else{
                    res.push_back(vector<int>{nums[i], nums[j], nums[k]});
                    int tmp = nums[j++];
                    while(j < nums.size() && tmp == nums[j])
                        ++j;
                }
            }
            int tmp = nums[i++];
            while(i < nums.size() && tmp == nums[i])
                ++i;
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums{-1, 0, 1, 2, -1, -4};
    vector<vector<int>> res = s.threeSum(nums);
    for(int i = 0; i < res.size(); ++i){
        for(int j = 0; j < res[i].size(); ++j){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int sz = nums.size();
        int i = 0;
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        while(i < sz-3){
            int j = i+1;
            while(j < sz-2){
                int k = j+1, l = sz-1;
                while(k < l){
                    int sum = nums[i]+nums[j]+nums[k]+nums[l];
                    if(sum > target)
                        --l;
                    else if(sum < target)
                        ++k;
                    else{
                        res.push_back(vector<int>{nums[i], nums[j], nums[k], nums[l]});
                        int tmp = nums[k];
                        while(++k < sz-1 && tmp == nums[k]);
                    }
                }
                int tmp = nums[j];
                while(++j < sz-2 && tmp == nums[j]);
            }
            int tmp = nums[i];
            while(++i < sz-3 && tmp == nums[i]);
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> n{1, 0, -1, 0, -2, 2};
    vector<vector<int>> v = s.fourSum(n, 0);
    for(auto c : v){
        for(auto a : c){
            cout << a << " ";
        }
        cout << endl;
    }
}

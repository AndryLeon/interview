#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto liter = lower_bound(nums.begin(), nums.end(), target);
        auto riter = upper_bound(nums.begin(), nums.end(), target);
        vector<int> res;
        if(*liter == target)
            res.push_back(liter - nums.begin());
        else
            res.push_back(-1);

        if(*(riter-1) == target)
            res.push_back(riter -nums.begin()-1);
        else
            res.push_back(-1);
        return res;
    }
};

int main(){
    vector<int> v{1,1,2,2,2,3,3,3,3,4,5};
    Solution s;
    auto res = s.searchRange(v, 3);
    cout << res[0] << " " << res[1] << endl;
}

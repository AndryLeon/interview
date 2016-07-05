#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    }
};

int main(){
    Solution s;
    vector<int> v{1,2,4,6,7};
    cout << s.searchInsert(v, 5) << endl;
}

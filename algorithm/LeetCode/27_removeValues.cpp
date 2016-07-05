#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int cnt = 0;
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] != val)
                nums[cnt++] = nums[i];
        }
        return cnt;
    }
};

int main(){
    Solution s;
    vector<int> v{3,2,2,3};
    cout << s.removeElement(v, 3);
}

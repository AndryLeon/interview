#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int sz = nums.size();
        if(sz == 0)
            return 0;
        int cnt = 1, last = nums[0];
        for(int i = 1; i < sz; ++i){
            if(last != nums[i]){
                last = nums[i];
                nums[cnt++] = nums[i];
            }
        }
        return cnt;
    }
};

int main(){
    Solution s;
    vector<int> v{1,1,2};
    cout << s.removeDuplicates(v);
}

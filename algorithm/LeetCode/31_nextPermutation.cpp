#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        for(int i = nums.size()-1; i > 0; --i){
            if(nums[i-1] < nums[i]){
                for(int j = nums.size()-1; j > 0; --j){
                    if(nums[j] > nums[i-1]){
                        swap(nums[i-1], nums[j]);
                        reverse(nums.begin()+i,nums.end());
                        return;
                    }
                }
            }
        }
        reverse(nums.begin(), nums.end());
        return;
    }
};

int main(){
    Solution s;
    vector<int> v{1,2,3,4,5};
    for(int i = 0; i < 5; ++i){
        s.nextPermutation(v);
        for(auto a : v){
            cout << a << " ";
        }
        cout << endl;
    }
}

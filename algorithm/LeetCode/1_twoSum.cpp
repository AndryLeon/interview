#include <unordered_map>
#include <vector>
#include <iostream>

using namespace std;

//O(n)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target){
        unordered_map<int, int> hash;
        vector<int> result;

        for(int i = 0;i < nums.size(); i++){
            if(hash.find(target - nums[i]) != hash.end()){
                result.push_back(hash[target - nums[i]]);
                result.push_back(i);
                return result;
            }
            hash[nums[i]] = i;
        }

        result.push_back(-1);
        result.push_back(-1);
        return result;
    }

};

int main(){
    Solution s;
    vector<int> nums{2,7,11,17};
    vector<int> v = s.twoSum(nums, 9);
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
}

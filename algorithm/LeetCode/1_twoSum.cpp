#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hash;
        vector<int> res;
        for(int i = 0; i < nums.size(); ++i){
            if(hash.find(target-nums[i]) != hash.end()){
                res.push_back(hash[target-nums[i]]);
                res.push_back(i);
                return res;
            }
            hash[nums[i]] = i;
        }
        return res;
    }
};

int main(){
    vector<int> v{2,3,2,3};
    Solution s;
    auto res = s.twoSum(v, 4);
    for(auto x : res){
        cout << x << " ";
    }
    return 0;
}

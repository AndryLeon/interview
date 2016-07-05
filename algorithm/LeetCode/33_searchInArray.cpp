#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target){
        int beg = 0, end = nums.size()-1, pivot, sz = nums.size();
        while(beg <= end){
            int mid = (beg+end)/2;
            if(mid-1 >= 0 && nums[mid] < nums[mid-1]){
                pivot = mid;
                break;
            }else if(mid+1 < sz && nums[mid] > nums[mid+1]){
                pivot = mid+1;
                break;
            }else if(nums[mid] >= nums[beg])
                beg = mid+1;
            else
                end = mid-1;
        }
        if(beg > end)
            pivot = sz;
        beg = 0, end = sz-1;
        while(beg <= end){
            int mid = (beg+end)/2;
            if(nums[(mid+pivot)%sz] == target){
                return (mid+pivot)%sz;
            }else if(nums[(mid+pivot)%sz] > target){
                end = mid-1;
            }else{
                beg = mid+1;
            }
        }
        return -1;
    }
};

int main(){
    vector<int> v{2,3,4,0,1};
    Solution s;
    cout << s.search(v, 3) << endl;
}

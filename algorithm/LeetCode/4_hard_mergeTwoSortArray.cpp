#include <vector>
#include <iostream>

using namespace std;

//O(log(m+n)
class Solution {
public:
    double findKth(vector<int>& nums1, int start1, int end1, vector<int>& nums2, int start2, int end2, int k){
        int size1 = end1-start1, size2 = end2-start2;
        if(size1 > size2){
            return findKth(nums2, start2, end2, nums1, start1, end1, k);
        }
        if(size1 == 0){
            return nums2[start2+k-1];
        }
        if(k == 1){
            return min(nums1[start1], nums2[start2]);
        }

        int a = min(k/2, size1);
        int b = k - a;
        if(nums1[start1+a-1] < nums2[start2+b-1]){
            return findKth(nums1, start1+a, end1, nums2, start2, end2, k-a);
        }else if(nums1[start1+a-1] > nums2[start2+b-1]){
            return findKth(nums1, start1, end1, nums2, start2+b, end2, k-b);
        }else{
            return nums1[start1+a-1];
        }
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size = nums1.size()+nums2.size();
        if(size & 1){
            return findKth(nums1, 0, nums1.size(), nums2, 0, nums2.size(), size/2 + 1);
        }else{
            return findKth(nums1, 0, nums1.size(), nums2, 0, nums2.size(), size/2)/2
                    + findKth(nums1, 0, nums1.size(), nums2, 0, nums2.size(), size/2 + 1)/2;
        }
    }
};

int main(){
    Solution s;
    vector<int> a{2,2,3,5,7,9};
    vector<int> b{2,3,5,7,8};
    cout << s.findMedianSortedArrays(a, b);
}

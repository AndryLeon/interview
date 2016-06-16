#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1)
            return l2;
        if(!l2)
            return l1;
        ListNode *res, *tmp3;
        if(l1->val < l2->val){
            res = tmp3 = l1;
            l1 = l1->next;
        }else{
            res = tmp3 = l2;
            l2 = l2->next;
        }
        while(l1 && l2){
            if(l1->val < l2->val){
                tmp3->next = l1;
                l1 = l1->next;
                tmp3 = tmp3->next;
            }else{
                tmp3->next = l2;
                l2 = l2->next;
                tmp3 = tmp3->next;
            }
        }
        if(l1){
            tmp3->next = l1;
        }
        if(l2)
            tmp3->next = l2;
        return res;
    }
};

int main(){
    ListNode l1(1), l2(3), l3(5), l4(2), l5(6), l6(8);
    l1.next = &l2;
    l2.next = &l3;
    l4.next = &l5;
    l5.next = &l6;
    Solution s;
    ListNode *res = s.mergeTwoLists(&l1, &l4);
    while(res){
        cout << res->val << " ";
        res = res->next;
    }
}

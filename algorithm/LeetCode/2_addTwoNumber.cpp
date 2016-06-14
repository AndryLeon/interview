#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

//O(n)
class Solution{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *t1 = l1, *t2 = l2, *res = NULL, *last = NULL;
        int carry = 0;
        while(t1 || t2){
            if(t1){
                carry += t1->val;
                t1 = t1->next;
            }
            if(t2){
                carry += t2->val;
                t2 = t2->next;
            }
            ListNode *tmp = new ListNode(carry%10);
            carry /= 10;
            if(res){
                last->next = tmp;
                last = tmp;
            }else{
                res = last = tmp;
            }
        }
        if(carry){
            last->next = new ListNode(carry);
        }
        return res;
    }
};

int main(){
    ListNode *a1 = new ListNode(4);
    a1->next = new ListNode(3);
    ListNode *a0 = new ListNode(2);
    a0->next = a1;

    ListNode *b1 = new ListNode(6);
    b1->next = new ListNode(3);
    ListNode *b0 = new ListNode(5);
    b0->next = b1;

    Solution s;
    ListNode* r = s.addTwoNumbers(a0, b0);
    while(r){
        cout << r->val << " ";
        r = r->next;
    }
    return 0;
}

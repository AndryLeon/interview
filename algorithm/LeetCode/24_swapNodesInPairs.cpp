#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *res, *last, *nx, *tmp1, *tmp2;
        if(!head || !head->next){
            return head;
        }
        tmp1 = head;
        tmp2 = head->next;
        nx = tmp2->next;
        res = tmp2;
        res->next = tmp1;
        last = tmp1;
        last->next = nx;
        while(nx && nx->next){
            tmp1 = nx;
            tmp2 = nx->next;
            nx = tmp2->next;
            last->next = tmp2;
            tmp2->next = tmp1;
            last = tmp1;
            tmp1->next = nx;
        }
        return res;
    }
};

int main(){
    ListNode a(2), b(3);
    a.next = &b;
    Solution s;
    ListNode *res = s.swapPairs(&a);
    while(res){
        cout << res->val << " ";
        res = res->next;
    }
}

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode res(0), *t1 = &res;
        res.next = head;
        ListNode *t2 = t1;
        for(int i = 0; i < n; ++i){
            t2 = t2->next;
        }
        while(t2->next){
            t2 = t2->next;
            t1 = t1->next;
        }
        t1->next = t1->next->next;
        return res.next;
    }
};

int main(){
    Solution s;
    ListNode t1(2), t2(3);
    t1.next = &t2;
    ListNode* res = s.removeNthFromEnd(&t1, 1);
    while(res){
        cout << res->val << " ";
        res = res->next;
    }
    return 0;
}

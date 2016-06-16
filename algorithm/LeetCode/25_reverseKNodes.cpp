#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head){
        ListNode *last = NULL, *tmp = head, *next;
        while(tmp->next){
            next = tmp->next;
            tmp->next = last;
            last = tmp;
            tmp = next;
        }
        tmp->next = last;
        return tmp;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k <= 1)
            return head;
        ListNode *res = NULL, *last = NULL, *top, *tmp, *next = head;
        int cnt = k;
        while(cnt == k){
            cnt = 0;
            top = tmp = next;
            while(tmp){
                ++cnt;
                if(cnt == k){
                    next = tmp->next;
                    tmp->next = NULL;
                    ListNode *newTop = reverseList(top);
                    top->next = next;
                    if(res){
                        last->next = newTop;
                        last = top;
                    }else{
                        res = newTop;
                        last = top;
                    }
                    break;
                }
                tmp = tmp->next;
            }
        }
        if(res)
            return res;
        else
            return head;
    }
};

int main(){
    ListNode a(2), b(3), c(4);
    a.next = &b;
    b.next = &c;
    Solution s;
    ListNode* res = s.reverseKGroup(&a, 2);
    while(res){
        cout << res->val << " ";
        res = res->next;
    }
}

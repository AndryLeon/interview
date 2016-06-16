#include <iostream>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        struct cmp{
            bool operator()(const ListNode* a, const ListNode* b){
                return a->val > b->val;
            }
        };

        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        for(auto x : lists){
            if(x)
                pq.push(x);
        }
        ListNode *res = NULL, *tmp = NULL, *get;
        while(!pq.empty()){
            get = pq.top();
            pq.pop();
            if(res){
                tmp->next = get;
                tmp = tmp->next;
            }else{
                res = tmp = get;
            }
            get = get->next;
            if(get){
                pq.push(get);
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    ListNode a(3), b(2);
    vector<ListNode*> v{&a, &b};
    ListNode* res = s.mergeKLists(v);
    while(res){
        cout << res->val << " ";
        res = res->next;
    }
}

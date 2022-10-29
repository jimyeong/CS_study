
#include <iostream>
#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode * next;
    ListNode() : val(0), next(nullptr){};
    ListNode(int x):val(x), next(nullptr){};
    ListNode(int x, ListNode *next):val(x), next(next){};
};

// 1 1 2 1
// 1 2 1 1

class Solution{
public:
    bool isPalindrome(ListNode* head) {
        stack<int> s;
        ListNode * cur_node = head;
        while(cur_node){
            s.push(cur_node->val);
            cur_node = cur_node->next;
        };
        int flag = 0;
        cur_node = head;
        while(!s.empty()){
            int reverse_val = s.top();
            s.pop();
            if(reverse_val != cur_node->val){
                flag = 1;
                break;
            }
            cur_node = cur_node->next;
        };
        return flag == 0 ? false : true;
    };
};
int main(){
    Solution sol;

    ListNode a(1);
    ListNode b(1);
    ListNode c(2);
    ListNode d(1);

    a.next =&b;
    b.next=&c;
    c.next=&d;
    d.next= nullptr;

    ListNode * head = &a;
    sol.isPalindrome(head);

    return 0;
}



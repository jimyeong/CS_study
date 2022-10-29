
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode * next;
    ListNode() : val(0), next(nullptr){};
    ListNode(int x):val(x), next(nullptr){};
    ListNode(int x, ListNode *next):val(x), next(next){};
};

class Solution{
public:
    bool isPalindrome(ListNode* head) {
        ListNode * cur_node = head;
        ListNode * prev_node = nullptr;
        ListNode * reverse_head = nullptr;
        ListNode * reverse_first = nullptr;
        // I keept making wrong code here, 
        // i should set up nullptr at the end of the reverse_head;

        while(cur_node){
            prev_node = cur_node;
            cur_node = cur_node->next;

            if(!reverse_head){
                reverse_head = prev_node;
                
                reverse_head->next= nullptr;
                reverse_first = prev_node;
            };
            prev_node->next = reverse_head;
            reverse_head = prev_node;
        };
        reverse_first->next = nullptr;
        int flag = 0;
        cur_node = head;
        ListNode * cur_reverse_node = reverse_head;
        while(cur_node){
            if(cur_node->val != cur_reverse_node->val){
                flag = 1;
                break;
            }
            cur_node = cur_node->next;
            cur_reverse_node = cur_reverse_node->next;
        }
        return flag == 0 ? true : false;
    }
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



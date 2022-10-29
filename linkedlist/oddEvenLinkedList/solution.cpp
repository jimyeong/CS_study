/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
struct ListNode {
    int val;
    ListNode * next;
    ListNode() : val(0), next(nullptr){};
    ListNode(int x):val(x), next(nullptr){};
    ListNode(int x, ListNode *next):val(x), next(next){};
};
#include <iostream>
using namespace std;

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode * node = head;
        ListNode * prev = nullptr;
        ListNode * newHead = nullptr;
        ListNode * eventh = nullptr;
        if(!head){
            return head;
        };
        int index = 1;
        
        while(node){
            if(!prev){
                 newHead = node;
                 eventh= node->next;
            };
            if(prev) {
                
                if(node->next) prev->next = node->next;
                if(!(node->next)) {
                    if(index %2 == 1){
                        prev->next=nullptr;
                        node->next = eventh;
                        break;
                    };
                    if(index %2 == 0){
                        node->next=nullptr;
                        prev->next = eventh;
                    };
                };
                //if(!node->next) prev->next = eventh; 
            };
            prev = node;
            node = node->next;
            index++;
        };
        
        return newHead;
    };
};

int main(){
    Solution solution;
    ListNode a(1);
    ListNode b(2);
    ListNode c(3);
    ListNode d(4);
    ListNode e(5);
    // ListNode f(6);
    // ListNode g(7);
    // ListNode h(8);
    a.next =&b;
    b.next=&c;
    c.next=&d;
    d.next=&e;
    // e.next=&f;
    // f.next=&g;
    // g.next=&h;
    ListNode * head = &a;
    solution.oddEvenList(&a);


    return 0;
}
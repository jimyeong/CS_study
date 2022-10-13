#include<iostream>

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode * node = head;
        ListNode * newHead = head;
        ListNode * prev = nullptr;
        ListNode * nextTemp;
        while(node){
            if(node->val == val){
                if(prev){
                    prev->next = node->next;
                    node = node->next;
                    
                };
                if(!prev){
                    newHead = node->next;
                    nextTemp = node->next;
                    head = nextTemp;
                    node = nextTemp;
                    prev = nullptr;
                }
            }else{
                prev = node;
                node = node->next;
            };
        }
        return newHead;
        
    }
};
#include<iostream>
using namespace std;
struct ListNode {
     int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr) return nullptr;
        if(head->next == nullptr) return head;
        if(k == 0) return head;
        int length = getLength(head);
        int iter_num = k % length;
        ListNode* start = head;
        ListNode* cur_node = head;
        ListNode* prev_node = nullptr;
        for(int i = 0; i < iter_num; i++){
            while(cur_node->next){
                prev_node = cur_node;
                cur_node = cur_node->next;
            };
            cur_node->next = start;
            start = cur_node;
            prev_node->next = nullptr;
        }
        return start;
    }
    int getLength(ListNode * head){
        int length = 0;
        while(head){
            head = head->next;
            length++;
        };
        return length;
    }
};
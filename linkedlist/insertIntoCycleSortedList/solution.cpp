#include <iostream>
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};

using namespace std;
#include <map>
class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        Node * prev_node = nullptr;
        Node * cur_node = head;
        Node * new_node = new Node(insertVal);
        bool isInserted = false;
        if(!head){
            new_node ->next = new_node;
            head = new_node;
            return head;
            
        }
        while(cur_node){
            
            prev_node = cur_node;
            cur_node = cur_node -> next;
            
            if(new_node->val <= cur_node->val && new_node->val >= prev_node->val){
                prev_node->next = new_node;
                new_node->next = cur_node;
                isInserted = true;
                break;
            };
            if(cur_node == head) break;
            
        }
        if(isInserted) return head;
        if(!isInserted){
            while(cur_node){
                if(prev_node->val >= cur_node->val){
                    prev_node->next = new_node;
                    new_node->next = cur_node;
                    break;
                }
                prev_node = cur_node;
                cur_node = cur_node->next;
                
            }
            return head;
        }
        return head;
    }
    
};
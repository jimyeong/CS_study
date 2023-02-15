#include <iostream>

// https://leetcode.com/explore/learn/card/linked-list/213/conclusion/1225/
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

#include <stack>
class Solution {
public:
    Node* flatten(Node* head) {
        Node * itr1 = head;
        Node * next = nullptr;
        while(itr1){
            next = itr1->next;
            Node * child = itr1->child;
            
            if(child){
                Node *  itr2 = flatten(child);
                // patch(itr1, itr2);
                // linking
                itr1->next = itr2;
                itr2->prev = itr1;
                
                // 
                while(itr2){
                    if(itr2->next) itr2= itr2->next;
                    if(!itr2->next) break;
                };
                // linking
                if(next){
                    itr2->next = next;
                    next->prev = itr2;   
                    itr1->child = NULL;
                    itr1 = next;
                }
                if(!next){
                    itr1->child= NULL;
                }
            }else{
                itr1 = itr1->next;
            };
        };
        return head;
    }
};


int main(){

    return 0;

}
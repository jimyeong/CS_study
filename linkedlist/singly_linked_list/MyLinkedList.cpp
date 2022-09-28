#include <iostream>
using namespace std;

class ListNode{
    public:
        int val;
        ListNode *next;
    ListNode(int x){
        val = x;
        next = nullptr;
    }

};
class MyLinkedList{
    public:
    ListNode * head;
    int size;
    MyLinkedList(){
        size = 0;
        head = new ListNode(0);
    };
    int get(int index){
        if(index > size-1 || index <0) return -1;
        ListNode *cur;
        for(int i=0; i < index+1; i++){
            cur = head->next;
        };
        return cur->val;
    };
    void addAtHead(int val){
        addAtIndex(val, 0);
    }
    void addAtTail(int val) {
        addAtIndex(val, size);
    }
    void addAtIndex(int index, int val){
        // not available for linking
        if(size < index)return;
        if(index < 0) return;

        ListNode * new_node = new ListNode(val);
        if(index == 0 ){    
            new_node->next = head;
            head = new_node;
        };
        if(index != 0){
            ListNode * cur;
            for(int i=0; i < index; i++){
                cur = head->next;
            }
            cur->next = new_node;
        };
    };
    void deleteAtIndex(int index) {
        // valid range set up
        if(index < 0 || index > size-1)return;
        if(index == 0){
            
            head = head->next;
            size--;
        }else if(index == size-1){
            ListNode * cur;
            for(int i=0; i < index-1; i++){
                cur = head->next;
            }
            cur->next = nullptr;
            size--;

        }else{

            ListNode * prev;
            ListNode * cur;
            
            for(int i = 0; i < index; i++){
                cur = head->next;
            }
            ListNode * targetNode = cur->next;
            cur->next = targetNode->next;
            size--;
        }

    }


};
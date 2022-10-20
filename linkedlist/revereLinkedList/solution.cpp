
#include<iostream>
#include<queue>
#include<stack>
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
    ListNode* reverseList(ListNode* head) {
        ListNode * cur = head;
        ListNode * prev = nullptr;
        while(cur){
            cur->next = prev;
            ListNode * nextNode = cur->next; // wrong answer, try drawing this image again
            prev = cur;
            cur = nextNode;  
        };
        return prev;
    }
};
int main(){
    
    ListNode node1(1);
    ListNode node2(2);
    ListNode node3(3);
    
    

    
    ListNode node4(4);
    ListNode node5(5);
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    

    ListNode * head = &node1;

    Solution s;
    s.reverseList(head);
    



    return 0;
}
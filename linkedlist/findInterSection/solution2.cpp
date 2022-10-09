#include <iostream>
using namespace std;
  
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode * tortoise = head;
        ListNode * rabbit = head;
        
        while(rabbit){
            rabbit = rabbit->next;
            if(rabbit)rabbit=rabbit->next;
            tortoise = tortoise->next;
            
            if(tortoise == rabbit){
                break;
            };
        };
        
        
        if(!rabbit)return NULL;
        rabbit = head;
        while(rabbit!=tortoise){
            rabbit= rabbit->next;
            tortoise = tortoise->next;
            if(tortoise == rabbit){
                break;
            };
        };
        return rabbit;
    };
    
};
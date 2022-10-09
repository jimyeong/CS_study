#include <iostream>
using namespace std;


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 // Definition for singly-linked list.
 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode * normalStep;
        ListNode * fastStep;
        
        normalStep = head;
        fastStep = head;
        
        while(normalStep){
            normalStep = normalStep->next;
            if(fastStep)fastStep = fastStep->next;
            if(fastStep){
                fastStep = fastStep->next;
                if(fastStep){                    
                    if(normalStep == fastStep->next){
                        return true;
                        break;
                    }

                }
            };
            
        };
        if(normalStep == fastStep){
            return false;
        }else{
            return true;
        };
        
    };
};
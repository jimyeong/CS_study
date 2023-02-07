#include <iostream>

 
 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * head1 = l1;
        ListNode * head2 = l2;
        ListNode * node_cur1 = head1;
        ListNode * node_cur2 = head2;
        bool flag = false;
        ListNode * merged = nullptr;
        ListNode * currentMerged = nullptr;
        while(node_cur1&&node_cur2){
            
            int cur1_val = node_cur1->val;
            int cur1_va2 = node_cur2->val;
            
            int addedValue = cur1_val + cur1_va2;
            if(flag){
                addedValue++;
                flag = !flag;
            }
            if(addedValue >= 10){
                addedValue -= 10;
                flag = true;
            };
            if(!merged){
                merged = new ListNode(addedValue);
                currentMerged = merged;
                
            }else{
                ListNode * newNode = new ListNode(addedValue);
                currentMerged->next = newNode;
                currentMerged = currentMerged->next;
            };
            node_cur1 = node_cur1->next;
            node_cur2 = node_cur2->next;
            
        }
        if(!node_cur1 && node_cur2){
            while(node_cur2){
                int addedValue = node_cur2->val;
                if(flag){
                    addedValue++;
                    flag = !flag;
                }
                if(addedValue >= 10){
                    addedValue -= 10;
                    flag = true;
                };
                
                ListNode * newNode = new ListNode(addedValue);
                currentMerged->next = newNode;
                
                currentMerged = currentMerged->next;
                node_cur2 = node_cur2->next;

            }
        }
        
        
        if(!node_cur2 && node_cur1){
            while(node_cur1){
                int addedValue = node_cur1->val;
                if(flag){
                    addedValue++;
                    flag = !flag;
                }
                if(addedValue >= 10){
                    addedValue -= 10;
                    flag = true;
                };
                
                ListNode * newNode = new ListNode(addedValue);
                currentMerged->next = newNode;
                
                currentMerged = currentMerged->next;
                node_cur1 = node_cur1->next;

            }
        }
        
        if(!node_cur1 && !node_cur2) {

            if(flag){
                currentMerged->next = new ListNode(1);
            }
            
            return merged;
        };
        
        
        if(flag){
            // merged->next = new ListNode(1);
        }
        return merged;
    }
};
int main(){

}
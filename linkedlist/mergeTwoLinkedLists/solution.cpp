

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode * mer_head = nullptr;
        ListNode * mer_node = nullptr;
        ListNode * a_current = list1;
        ListNode * b_current = list2;
        if(a_current && b_current){
            if(a_current->val >= b_current->val){
                mer_head = b_current;
                b_current = b_current->next;
                mer_head -> next = nullptr;

            }else{
                mer_head = a_current;
                a_current = a_current->next;
                mer_head -> next = nullptr;
            }
        }else{
            if(!a_current && !b_current){
                return mer_head;
            }
            if(!a_current){
                mer_head = b_current;
                b_current = b_current->next;
                mer_head -> next = nullptr;
            }else{
                mer_head = a_current;
                a_current = a_current->next;
                mer_head -> next = nullptr;
            }
            
        }
        
        mer_node = mer_head;
        while(a_current || b_current){
            if(a_current && b_current){
                if(a_current->val >= b_current->val){
                    mer_node->next = b_current;
                    b_current = b_current->next;
                }else{
                    mer_node->next = a_current;
                    a_current = a_current->next;
                }
            }else{
                if(!a_current){
                    mer_node->next = b_current;
                    b_current = b_current->next;
                }else{
                    mer_node->next = a_current;
                    a_current = a_current->next;
                }
                
            }
            mer_node = mer_node->next;
            mer_node->next = nullptr;
        }
        return mer_head;
        
        
        
    }
};
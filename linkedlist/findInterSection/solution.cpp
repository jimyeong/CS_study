
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <iostream>
#include <map>
#include <sstream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){};
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        map<string, int> nodeMap;
        ListNode * nodeA = headA;
        ListNode * targetNode = NULL;
        while (nodeA)
        {
            
            const void * address = static_cast<const void *>(nodeA);
            stringstream ss;
            ss << address;
            nodeMap[ss.str()] = 1;
            nodeA = nodeA->next;
        };

        ListNode * nodeB = headB;
        while (nodeB)
        {
            const void * address = static_cast<const void *>(nodeB);
            
            stringstream ss;
            ss << address;
            if(nodeMap[ss.str()] == 1){
                targetNode = nodeB;
                break;
            };
            nodeMap[ss.str()] = 1;
            nodeB = nodeB->next;
        };

        if(targetNode == NULL) return NULL;
        return targetNode;
    
    }
};




int main(){
    return 0;
}
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(nullptr) {};
      ListNode(int x, ListNode * k): val(x), next(k){};

 };


#include <map>
#include <iostream>
#include <sstream>

using namespace std;



class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode * node = head; 
        map<string, int> nodeMap;
        int start = -1;
        ListNode * targetNode; 
        while(node){
            const void * address = static_cast<const void*>(node);
            stringstream addr;
            addr<<address;
            if(nodeMap[addr.str()] == 1){
                start = 1;
                targetNode=node;
                break;
            };
            nodeMap[addr.str()
            ] = 1;
            node=node->next;
        }
        if(start != -1){
            return targetNode;
            
        }
        return NULL;
    }
};


int main(){
    ListNode * a = new ListNode(2);
    ListNode * b = new ListNode(1,a);
    a->next = b;

    Solution k;
    cout << k.detectCycle(b)->val << endl;
    
    // Node * a = new Node(4);
    // const void * address = static_cast<const void*>(a);
    // stringstream addr;
    // addr<<address;
    // cout << addr.str() << endl;

    // map<string, int> nodeMap;
    // nodeMap[addr.str()]=0;

    // cout << "visited? " << nodeMap[addr.str()] << endl;
    // return null;
    


    
    // Node * key = a;



    return 0;
}
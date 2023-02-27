
//https://leetcode.com/explore/learn/card/linked-list/213/conclusion/1229/
using namespace std;
#include <unordered_map>

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};



class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;
        if(isVisited[head])return isVisited[head];
        Node * new_node = new Node(head->val);
        isVisited[head] = new_node;
        new_node->next = copyRandomList(head->next);
        new_node->random = copyRandomList(head->random);
        return new_node;
    }
private:
    unordered_map<Node*, Node*> isVisited;
};
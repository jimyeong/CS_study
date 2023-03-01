#include <iostream>


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

using namespace std;
#include <unordered_map>

class Solution {
public:
    Node* visitNode(Node * visitedNode){
        if(isVisited.find(visitedNode) == isVisited.end()){
            if(visitedNode !=  nullptr){
                Node * new_node = new Node(visitedNode->val);
                isVisited[visitedNode] = new_node;
                return new_node;
            }
            return isVisited[visitedNode];
        }else{
            return isVisited[visitedNode];
        }
    }

    Node* copyRandomList(Node* head) {
        Node * cur_node = head;
        Node * new_entry = nullptr;
        Node * random_node = nullptr;
        Node * next_node = nullptr;
        Node * new_prev = nullptr;
        
        while(cur_node){
            if(cur_node == head){
                new_entry = visitNode(head);
                new_prev = new_entry;
                next_node = visitNode(cur_node->next);
                random_node = visitNode(cur_node->random);
                new_entry -> next = next_node;
                new_entry -> random = random_node;
                
            }else{
                next_node = visitNode(cur_node->next);
                random_node = visitNode(cur_node->random);
                new_prev -> next = next_node;
                new_prev -> random = random_node;
            };
            cur_node = cur_node->next;
            new_prev = new_prev->next;
        };
        return new_entry;
    }
private:
    unordered_map<Node*, Node*> isVisited;
};
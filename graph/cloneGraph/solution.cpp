/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
#include "unordered_map"
using namespace std;
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr) return nullptr;
        if(isVisited[node]) return isVisited[node];
        Node * new_node = new Node(node->val);
        isVisited[node] = new_node;

        for(int i=0; i< node->neighbors.size(); i++){
            new_node->neighbors.push_back(cloneGraph(node->neighbors[i]));
        }
        return new_node;
    }
private: 
    unordered_map<Node*, Node*> isVisited;
};
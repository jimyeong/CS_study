/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

#include "unordered_map"
using namespace std;
class Solution {
public:
    Node* cloneTree(Node* root) {
        if(root == nullptr)return nullptr;
        if(isVisited[root]) return isVisited[root];

        Node * new_node = new Node(root->val);
        isVisited[root] = new_node;

        for(int i=0; i < root->children.size(); i++){
            new_node->children.push_back(cloneTree(root->children[i]));
        }


        return new_node;


        
    }
private:
    unordered_map<Node*, Node*> isVisited;

};
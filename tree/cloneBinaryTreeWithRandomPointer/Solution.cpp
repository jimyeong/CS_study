

 struct Node {
       int val;
        Node *left;
 Node *right;
      Node *random;
      Node() : val(0), left(nullptr), right(nullptr), random(nullptr) {}
      Node(int x) : val(x), left(nullptr), right(nullptr), random(nullptr) {}
      Node(int x, Node *left, Node *right, Node *random) : val(x), left(left), right(right), random(random) {}
  };
 

#include "unordered_map"
using namespace std;

class Solution {
public:
    NodeCopy* copyRandomBinaryTree(Node* root) {
        // NodeCopy* new_node = new NodeCopy(root->val);

        
        if(!root) return nullptr;
        if(isVisited[root]) return isVisited[root];
        NodeCopy* new_node = new NodeCopy(root->val);
        isVisited[root] = new_node;

        isVisited[root]->right = copyRandomBinaryTree(root->right);
        isVisited[root]->left = copyRandomBinaryTree(root->left);
        isVisited[root]->random = copyRandomBinaryTree(root->random);
        return new_node;
    }
private: 
    unordered_map<Node *, NodeCopy* > isVisited;

};
#include <iostream>
#include <stack>
using namespace std;

struct Node{
    int val;
    Node * next;
    Node(const int _val):val(_val), next(nullptr){};
};

void helloWorld(int val){
    Node cur_node(val);
    cout << intptr_t(&cur_node) << endl;
    cout << cur_node.val << endl;


}

int main(){
    stack<Node> s;
    helloWorld(4);
    helloWorld(5);
    return 0;
}


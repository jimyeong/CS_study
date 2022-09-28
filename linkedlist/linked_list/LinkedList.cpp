#include <iostream>
using namespace std;

class MyLinkedList {
    public:
    MyLinkedList():head_(nullptr), tail_(nullptr), size_(0){};
    ~MyLinkedList(){
        //delete all Node in Linked list
        Node * node = head_;
        while(node){
            Node * cur = node;
            node = node->next;
            delete cur;
        };
        
        head_ = nullptr;
        tail_ = nullptr;
    };
    int get(int index){
        if(index < 0 || index >= size_)return -1;
        int n = index;
        Node * cur = head_;
        while (n > 0)
        {
            cur = cur->next;
            n--;
        };
        // cout << intptr_t(cur) << endl;
        return cur->val;
    }
    void addAtHead(int val){
        head_ = new Node(val, head_);
        if(size_ == 0)tail_ = head_;
        size_++;
    };
    void addAtTail(int val){
        if(size_ == 0){
            tail_ = new Node(val, tail_);   
            head_ = tail_;
        };
        if(size_ != 0 ){
            Node * newNode = new Node(val, nullptr);
            tail_->next = newNode;
            tail_ = newNode;


            // tail_->next = newNode;
            // tail_ = newNode;
        }
        size_++;
    };
    void addAtIndex(int index, int val){
        if(index < 0 || index > size_) return;
        Node * cur;
        int n = index;
        if(index == 0){
            return addAtHead(val);
        }else if(index == size_){
            return addAtTail(val);
        }else{
            Node * cur = new Node(val, nullptr);
            Node * prev = getNode(index-1);
            cur->next =  prev->next;
            prev->next = cur;
            size_++;
        }
        
    };

    void deleteAtIndex(int index){
        if(index >= size_ || index < 0)return ;
        int n = index;
        cout << "size: " << size_ << endl;
        
        if(index == 0){ 
            Node * target = head_;
            head_ = head_->next;
            target = nullptr;
        } else if(index == size_-1){
            Node * prevNode = getNode(size_-2);
            Node * targetNode = prevNode->next;
            tail_ = prevNode;
            targetNode = nullptr;
        }else{
            Node * prevNode = getNode(index - 1);
            Node * targetNode = prevNode->next;
            prevNode->next = targetNode->next;
            targetNode = nullptr;
        }
        size_--;
    };
    
    private: 
    struct Node{
        int val;
        Node* next;
        Node(int _val): Node(_val, nullptr) {};
        Node(int _val, Node * _next): val(_val), next(_next) {}
    };
    Node *head_;
    Node *tail_;
    Node *dummy_;
    int size_;

    Node * getNode(int index){
        int count = index;
        dummy_ = head_;
        while (count > 0)
        {
            dummy_=dummy_->next;
            count--;
        };
        return dummy_;
    };
    
};


int main(){
    MyLinkedList linkedlist;
    linkedlist.addAtHead(0);
    linkedlist.addAtIndex(1,4);
    linkedlist.addAtTail(8);
    linkedlist.addAtHead(5);
    linkedlist.addAtIndex(4,3);
    linkedlist.addAtTail(0);
    linkedlist.addAtTail(5);
    linkedlist.addAtIndex(6,3);
    linkedlist.deleteAtIndex(7);
    linkedlist.deleteAtIndex(5);
    linkedlist.addAtTail(4);
    return 0;
}


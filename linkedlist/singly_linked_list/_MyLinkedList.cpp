struct Node {
    int val;
    Node * next;
};

class MyLinkedList{
    public:
    Node *head = nullptr;
    Node *tail = nullptr;
    int index = 0;
    MyLinkedList() {
        
    }
    
    int get(int index) {
        int move = index;
        Node * cur;
        while (move < 0)
        {
            cur = head->next;
            move--;
        };
        return cur->val;
    };
    
    void addAtHead(int val) {
        Node * newNode;
        newNode->val = val;
        if(!head){
            newNode->next = nullptr;
            head = newNode;
            tail = newNode;
            index++;
        }
        if(head){
            newNode->next = head;
            head = newNode;
            index ++;

        }
    }
    
    void addAtTail(int val) {
        Node * newNode;
        newNode->val = val;
        //Node * temp = tail;
        // tail = newNode;
        tail->next = newNode;
        tail = newNode;
        index++;
    }
    
    void addAtIndex(int index, int val) {
        int move = index;
        Node * newNode;
        newNode->val = val;

        Node * cur = head;
        while (move < 0)
        {
            cur = cur->next;
            move--;
        }
        newNode.next = cur->next;
        cur->next = newNode;
        index++;
    }
    
    void deleteAtIndex(int index) {
        
        int move = index;
        Node * cur = head;

        while(move < 1){
            cur = cur->next;
            move--;
        };
        
        Node * target = cur->next->next;

        target->next = cur->next;
        target = nullptr;
    }

};

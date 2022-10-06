```
intptr_t(&cur_node)  memory address in decimal
```

```
// string casting in c++
        const void * address = static_cast<const void*>(node);
        stringstream addr;
        addr<<address;

        // add visited node address in map
        nodeMap[addr.str()] == 1
```

```
Hashmap usecase
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        set<ListNode *> nodes_in_B;

        while (headB != nullptr) {
            nodes_in_B.insert(headB);
            headB = headB->next;
        }

        while (headA != nullptr) {
            // if we find the node pointed to by headA,
            // in our set containing nodes of B, then return the node
            if (nodes_in_B.find(headA) != nodes_in_B.end()) {
                return headA;
            }
            headA = headA->next;
        }

        return nullptr;
    }
};
```

```
6th of October
ListNode * node = head;
        // index=1로 썼는데 1부터 5칸을 가면 6이 된다.
        int index = 0;
        while(node){
            node=node->next;
            index++;
        };


        // 여기 next 하나만 써서 틀림 ㅠㅠ
        cur->next = targetNode->next->next;
```

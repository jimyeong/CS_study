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

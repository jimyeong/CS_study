#include<iostream>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * node = head;
        // index=1로 썼는데 1부터 5칸을 가면 6이 된다.
        
        int index = 0;
        while(node){
            node=node->next;
            index++;
        };
        if(n > index){
            return head;
        };
        if(n == index){
            // head
            head = head->next;
            return head;
        }
        if(n == 1){
            // tail
            int step = 1;
            ListNode * cur = head;
            while(step < index-1){
                cur = cur->next;
                step++;
            };
            cur->next = NULL;
            return head;
        };
        int move = index - n;
        ListNode * cur = head;
        while(move > 1 ){
            cur=cur->next;
            move--;
        };
        ListNode* targetNode = cur;
        // 여기 next 하나만 써서 틀림 ㅠㅠ
        cur->next = targetNode->next->next;
        targetNode=NULL;
        return head;
    }
};

int main(){
    int val = 2;
    ListNode a(5);
    ListNode b(4, &a);
    ListNode c(3, &b);
    ListNode d(2,&c);
    ListNode e(1, &d);
    Solution sol;
    sol.removeNthFromEnd(&e,2);


    


}
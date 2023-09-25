// You are given the head of a singly linked-list. The list can be represented as:

// L0 → L1 → … → Ln - 1 → Ln
// Reorder the list to be on the following form:

// L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
// You may not modify the values in the list's nodes. Only nodes themselves may be changed.

 

// Example 1:


// Input: head = [1,2,3,4]
// Output: [1,4,2,3]
// Example 2:


// Input: head = [1,2,3,4,5]
// Output: [1,5,2,4,3]
 

// Constraints:

// The number of nodes in the list is in the range [1, 5 * 104].
// 1 <= Node.val <= 1000


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
ListNode *s,*t;
int ex=0;
    void reorderList(ListNode* p) {
        if(p->next==NULL)return;
        s=p;
        t=p;
        my(p);
    }
    void my(ListNode *p){
        if(p!=NULL){
            my(p->next);
            if(ex==1)return;
            t=s->next;
            s->next=p;
            p->next=t;
            s=t;
            if(t->next==p && t==p->next){
                t->next=NULL;
                ex=1;
            }
        }
    }
};
// Given the head of a linked list, rotate the list to the right by k places.

 

// Example 1:

// Input: head = [1,2,3,4,5], k = 2
// Output: [4,5,1,2,3]

// Example 2:

// Input: head = [0,1,2], k = 4
// Output: [2,0,1]

 

// Constraints:

//     The number of nodes in the list is in the range [0, 500].
//     -100 <= Node.val <= 100
//     0 <= k <= 2 * 109

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
    ListNode* rotateRight(ListNode* head, int k) {
        int n=sizeOfLL(head);
        if(n==0)return head;
        k=k%n;
        if(k==0)return head;
        n=n-k;
        ListNode *p=head,*t=NULL,*re=head;
        while(n!=1){ p=p->next; n--; }
        t=p->next;
        p->next=NULL;
        re=t;
        while(t->next!=NULL)t=t->next;
        t->next=head;
        return re;
    }
    int sizeOfLL(ListNode *p){
        int s=0;
        while(p!=NULL){ p=p->next; s++; }
        return s;
    }
};
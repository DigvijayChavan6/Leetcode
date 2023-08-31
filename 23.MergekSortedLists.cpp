// You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

// Merge all the linked-lists into one sorted linked-list and return it.

 

// Example 1:

// Input: lists = [[1,4,5],[1,3,4],[2,6]]
// Output: [1,1,2,3,4,4,5,6]
// Explanation: The linked-lists are:
// [
//   1->4->5,
//   1->3->4,
//   2->6
// ]
// merging them into one sorted list:
// 1->1->2->3->4->4->5->6

// Example 2:

// Input: lists = []
// Output: []

// Example 3:

// Input: lists = [[]]
// Output: []

 

// Constraints:

//     k == lists.length
//     0 <= k <= 104
//     0 <= lists[i].length <= 500
//     -104 <= lists[i][j] <= 104
//     lists[i] is sorted in ascending order.
//     The sum of lists[i].length will not exceed 104.


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
    ListNode* mergeKLists(vector<ListNode*>& lis) {
        ListNode *cn=new ListNode(0);
        if(lis.size()==1)return lis[0];
        if(lis.size()==0)return NULL;
        cn->next=mrg(lis[0],lis[1]);
        for(int i=2;i<lis.size();i++)cn->next=mrg(cn->next,lis[i]);
        return cn->next;
    }
    ListNode* mrg(ListNode *p,ListNode *q){
        ListNode *cn=new ListNode(0);
        ListNode *re=cn;
        while(p!=NULL && q!=NULL){
            if(p->val < q->val){
                cn->next=p;
                p=p->next;
            }
            else{
                cn->next=q;
                q=q->next;
            }
            if(cn->next != NULL)cn=cn->next;
        }
        while(p!=NULL){
            cn->next=p;
            p=p->next;
            cn=cn->next;
        }
        while(q!=NULL){
            cn->next=q;
            q=q->next;
            cn=cn->next;
        }
        return re->next;
    }
};
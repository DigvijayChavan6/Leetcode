// You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 

// Example 1:

// Input: l1 = [2,4,3], l2 = [5,6,4]
// Output: [7,0,8]
// Explanation: 342 + 465 = 807.

// Example 2:

// Input: l1 = [0], l2 = [0]
// Output: [0]

// Example 3:

// Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
// Output: [8,9,9,9,0,0,0,1]

 

// Constraints:

//     The number of nodes in each linked list is in the range [1, 100].
//     0 <= Node.val <= 9
//     It is guaranteed that the list represents a number that does not have leading zeros.

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
    vector<int> vec,v;
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int on=getDig(l1,1);
        int tw=getDig(l2,2);
        int s1=vec.size(),s2=v.size(),i=0,j=0,h=0;
        ListNode *p;
        p=l1;
        if(tw>on)p=l2;
        ListNode *tp,*re=p;
        if(p==NULL)return p;
        while(i<s1 && j<s2){
            int ad=vec[i++]+v[j++]+h;
            tp=p;
            p->val=ad%10;
            p=p->next;
            if(ad>=10)h=1;
            else h=0;
        }
        while(i<s1){
            int ad=vec[i++]+h;
            tp=p;
            p->val=ad%10;
            p=p->next;
            if(ad>=10)h=1;
            else h=0;
        }
        while(j<s2){
            int ad=v[j++]+h;
            tp=p;
            p->val=ad%10;
            p=p->next;
            if(ad>=10)h=1;
            else h=0;
        }
        if(h==1)p->val=1;
        else tp->next=NULL;
        return re;
    }
    int getDig(ListNode *p,int flag){
        int cn=0;
        ListNode *t;
        while(p!=NULL){
            if(flag==1)vec.push_back(p->val);
            else v.push_back(p->val);
            t=p;
            p=p->next;
            cn++;
        }
        ListNode *z=new ListNode;
        z->val=0;
        z->next=NULL;
        t->next=z;
        return cn+1;
    }
};
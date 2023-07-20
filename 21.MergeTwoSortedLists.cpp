// You are given the heads of two sorted linked lists list1 and list2.

// Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.

// Return the head of the merged linked list.

// Example 1:

// Input: list1 = [1,2,4], list2 = [1,3,4]
// Output: [1,1,2,3,4,4]

// Example 2:

// Input: list1 = [], list2 = []
// Output: []

// Example 3:

// Input: list1 = [], list2 = [0]
// Output: [0]

// Constraints:

//     The number of nodes in both lists is in the range [0, 50].
//     -100 <= Node.val <= 100
//     Both list1 and list2 are sorted in non-decreasing order.

// ANSWER->
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
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l, ListNode *r)
    {
        ListNode *p, *pp;
        if (l == NULL)
        {
            return r;
        }
        if (r == NULL)
        {
            return l;
        }
        if (l->val > r->val)
        {
            p = r;
            r = r->next;
        }
        else
        {
            p = l;
            l = l->next;
        }
        pp = p;
        while (l != NULL && r != NULL)
        {
            if (l->val > r->val)
            {
                p->next = r;
                p = r;
                r = r->next;
            }
            else
            {
                p->next = l;
                p = l;
                l = l->next;
            }
        }
        if (l == NULL)
        {
            p->next = r;
        }
        else
        {
            p->next = l;
        }
        return pp;
    }
};
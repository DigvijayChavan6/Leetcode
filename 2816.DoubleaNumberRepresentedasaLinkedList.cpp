

// You are given the head of a non-empty linked list representing a non-negative integer without leading zeroes.

// Return the head of the linked list after doubling it.

 

// Example 1:

// Input: head = [1,8,9]
// Output: [3,7,8]
// Explanation: The figure above corresponds to the given linked list which represents the number 189. Hence, the returned linked list represents the number 189 * 2 = 378.

// Example 2:

// Input: head = [9,9,9]
// Output: [1,9,9,8]
// Explanation: The figure above corresponds to the given linked list which represents the number 999. Hence, the returned linked list reprersents the number 999 * 2 = 1998. 

 

// Constraints:

//     The number of nodes in the list is in the range [1, 104]
//     0 <= Node.val <= 9
//     The input is generated such that the list represents a number that does not have leading zeros, except the number 0 itself.

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
    vector<int> vec;
    int m = 0;
    ListNode *doubleIt(ListNode *head)
    {
        fun(head);
        if (m != 0)
            vec.insert(vec.begin(), m);
        ListNode *p = head, *t = p;
        for (int i = 0; i < vec.size(); i++)
        {
            if (p != NULL)
                p->val = vec[i];
            else
            {
                p = cre(vec[i]);
                t->next = p;
                p->val = vec[i];
            }
            t = p;
            p = p->next;
        }
        return head;
    }
    ListNode *cre(int n)
    {
        ListNode *x = new ListNode(n);
        x->next = NULL;
        return x;
    }
    void fun(ListNode *p)
    {
        if (p != NULL)
        {
            fun(p->next);
            int t = 2 * p->val;
            vec.insert(vec.begin(), t % 10 + m);
            m = t / 10;
        }
    }
};
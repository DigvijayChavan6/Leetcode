// Given the head of a linked list, return the list after sorting it in ascending order.

 

// Example 1:

// Input: head = [4,2,1,3]
// Output: [1,2,3,4]

// Example 2:

// Input: head = [-1,5,3,4,0]
// Output: [-1,0,3,4,5]

// Example 3:

// Input: head = []
// Output: []

 

// Constraints:

//     The number of nodes in the list is in the range [0, 5 * 104].
//     -105 <= Node.val <= 105

 

// Follow up: Can you sort the linked list in O(n logn) time and O(1) memory (i.e. constant space)?

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
    ListNode *sortList(ListNode *head)
    {
        ListNode *p = head, *t = head;
        vector<int> vec;
        while (p != NULL)
        {
            vec.push_back(p->val);
            p = p->next;
        }
        ms(vec, 0, vec.size() - 1);
        for (int i = 0; i < vec.size(); i++)
        {
            t->val = vec[i];
            t = t->next;
        }
        return head;
    }
    void ms(vector<int> &vec, int l, int h)
    {
        if (l < h)
        {
            int mid = (l + h) / 2;
            ms(vec, l, mid);
            ms(vec, mid + 1, h);
            mrg(vec, l, mid, h);
        }
    }
    void mrg(vector<int> &vec, int l, int mid, int h)
    {
        int s1 = l, s2 = mid + 1;
        vector<int> tp;
        while (s1 <= mid && s2 <= h)
        {
            if (vec[s1] <= vec[s2])
                tp.push_back(vec[s1++]);
            else
                tp.push_back(vec[s2++]);
        }
        while (s1 <= mid)
            tp.push_back(vec[s1++]);
        while (s2 <= h)
            tp.push_back(vec[s2++]);
        for (int i = l; i <= h; i++)
            vec[i] = tp[i - l];
    }
};
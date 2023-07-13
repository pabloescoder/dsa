// https://leetcode.com/problems/reverse-nodes-in-k-group/description/
// https://leetcode.com/problems/reverse-nodes-in-k-group/solutions/11491/succinct-iterative-python-o-n-time-o-1-space/comments/337296
// https://leetcode.com/problems/reverse-nodes-in-k-group/solutions/11491/succinct-iterative-python-o-n-time-o-1-space/comments/217945

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
    // Time Complexity: O(N)
    // Space Complexity: O(1)
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (k == 1 || !head)
            return head;

        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *nextHead = dummy;
        ListNode *prev = head;
        ListNode *curr = head;
        while (true)
        {
            int nodeCount = 0;
            while (curr && nodeCount < k)
            {
                curr = curr->next;
                nodeCount++;
            }

            if (nodeCount == k)
            {
                ListNode *t = prev;
                ListNode *h = curr;
                for (int i = 1; i <= k; i++) // this is NOT a standard reversing by swapping arrows between adjacent nodes
                {                            // instead it poplefts a node successively (ref. comment below)
                    ListNode *temp = t->next;
                    t->next = h;
                    h = t;
                    t = temp;
                }
                nextHead->next = h;
                nextHead = prev;
                prev = curr;
            }
            else
            {
                return dummy->next;
            }
        }
    }
};

// Swapping method used in the above code
/*
k = 3 for example:

step 0: a -> b -> c -> (next k-group)

step 1:      b -> c -> (next k-group)
                  a ---^

step 2:           c -> (next k-group)
             b -> a ---^

step 3:                (next k-group)
        c -> b -> a ---^

finish: c -> b -> a -> (next k-group)
*/
// https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/

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
    // Time Complexity: O(N) (One Pass)
    // Space Complexity: O(1)
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *slow = head;
        ListNode *fast = head;

        // Moving fast n steps ahead
        for (int i = 1; i <= n; i++)
            fast = fast->next;

        if (!fast) // if fast is already nullptr, it means that we need to delete head itself
            return head->next;

        // Moving both fast and slow by 1 step each till fast reaches the end
        while (fast->next)
        {
            slow = slow->next;
            fast = fast->next;
        }

        slow->next = slow->next->next; // remove nth node from end
        return head;
    }

    // // Time Complexity: O(N) (Two Pass)
    // // Space Complexity: O(1)
    // ListNode* removeNthFromEnd(ListNode* head, int n)
    // {
    //     int total = 0;
    //     ListNode *curr = head;
    //     while (curr)
    //     {
    //         total++;
    //         curr = curr->next;
    //     }

    //     if(total == n)
    //         return head->next;

    //     curr = head;
    //     for(int i = 1; i < total - n; i++) // Stop 1 node behind
    //         curr = curr->next;

    //     curr->next = curr->next->next;
    //     return head;
    // }
};
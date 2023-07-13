// https://leetcode.com/problems/rotate-list/description/

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
    ListNode *rotateRight(ListNode *head, int k)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        int count = 0;
        while (slow)
        {
            slow = slow->next;
            count++;
        }
        slow = head;
        if (k == 0 || count == 0 || k % count == 0)
            return head;
        for (int i = 1; i <= k % count; i++)
            fast = fast->next;
        while (fast->next)
        {
            slow = slow->next;
            fast = fast->next;
        }
        fast->next = head;
        head = slow->next;
        slow->next = nullptr;
        return head;
    }
};
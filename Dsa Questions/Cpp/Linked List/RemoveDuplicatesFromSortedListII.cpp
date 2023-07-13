// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description/

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
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (!head)
            return head;
        ListNode *dummy = new ListNode(0);
        ListNode *p = dummy;
        ListNode *slow = head;
        ListNode *fast = head;
        while (slow)
        {
            while (fast && fast->val == slow->val)
                fast = fast->next;
            if (slow->next == fast)
            {
                p->next = slow;
                p = p->next;
            }
            slow = fast;
        }
        p->next = nullptr;
        return dummy->next;
    }
};
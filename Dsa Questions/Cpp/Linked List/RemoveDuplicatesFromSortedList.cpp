// https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/
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
            return nullptr;

        ListNode *uniqueP = head;
        ListNode *curr = head->next;
        while (curr)
        {
            if (curr->val != uniqueP->val)
            {
                uniqueP->next = curr;
                uniqueP = uniqueP->next;
            }
            curr = curr->next;
        }
        uniqueP->next = nullptr;
        return head;
    }
};
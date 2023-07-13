// https://leetcode.com/problems/reverse-linked-list-ii/description/

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
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        ListNode *leftPrev = dummy;
        ListNode *curr = head;
        int pos = 1;
        while (pos != left)
        {
            leftPrev = curr;
            curr = curr->next;
            pos++;
        }

        ListNode *prev = nullptr;
        while (pos != right + 1)
        {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            pos++;
        }

        leftPrev->next->next = curr;
        leftPrev->next = prev;
        return dummy->next;
    }
};
// https://leetcode.com/problems/partition-list/description/

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
    // More concise/intuitive. Both solutions are equally optimal.
    ListNode *partition(ListNode *head, int x)
    {
        ListNode *pLess = new ListNode(0);
        ListNode *pMore = new ListNode(0);
        ListNode *pL = pLess;
        ListNode *pM = pMore;
        while (head)
        {
            if (head->val < x)
            {
                pL->next = head;
                pL = pL->next;
            }
            else
            {
                pM->next = head;
                pM = pM->next;
            }
            head = head->next;
        }
        pM->next = nullptr;
        pL->next = pMore->next;
        return pLess->next;
    }
    // // Time Complexity: O(N) (One Pass)
    // // Space Complexity: O(1)
    // ListNode* partition(ListNode* head, int x) {
    //     ListNode *dummy = new ListNode(0);
    //     dummy->next = head;
    //     ListNode *leftPrev = dummy;
    //     while(leftPrev->next && leftPrev->next->val < x)
    //         leftPrev = leftPrev->next;

    //     ListNode *slow = leftPrev;
    //     ListNode *fast = leftPrev->next;
    //     ListNode *left = leftPrev->next;
    //     while(fast) {
    //         if(fast->val < x)
    //         {
    //             slow->next = fast->next;
    //             leftPrev->next = fast;
    //             leftPrev = fast;
    //             fast = slow->next;
    //         }
    //         else {
    //             fast = fast->next;
    //             slow = slow->next;
    //         }
    //     }
    //     leftPrev->next = left;
    //     return dummy->next;
    // }
};
// https://leetcode.com/problems/add-two-numbers/description/

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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *newHead = new ListNode(0);
        ListNode *t = newHead;
        int carry = 0;
        while (l1 || l2 || carry)
        {
            int total = carry + (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
            t->next = new ListNode(total % 10);
            t = t->next;
            carry = total / 10;
            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;
        }
        return newHead->next;
    }
    // ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    //    ListNode* totalHead = nullptr;
    //    ListNode* totalP = nullptr;
    //    int carry = 0;
    //    while (l1 && l2)
    //    {
    //        int total = l1->val + l2->val + carry;
    //        carry = total / 10;
    //        ListNode* newNode = new ListNode(total % 10);
    //        if(!totalP)
    //            totalHead = newNode;
    //        else
    //            totalP->next = newNode;
    //        totalP = newNode;
    //        l1 = l1->next;
    //        l2 = l2->next;
    //    }

    //    while(l1)
    //    {
    //        int total = l1->val + carry;
    //        carry = total/10;
    //        ListNode* newNode = new ListNode(total % 10);
    //        totalP->next = newNode;
    //        totalP = newNode;
    //        l1=l1->next;
    //    }
    //    while (l2)
    //    {
    //        int total = l2->val + carry;
    //        carry = total/10;
    //        ListNode *newNode = new ListNode(total % 10);
    //        totalP->next = newNode;
    //        totalP = newNode;
    //        l2=l2->next;
    //    }
    //    if (carry != 0)
    //    {
    //        ListNode *newNode = new ListNode(carry);
    //        totalP->next = newNode;
    //    }
    //    return totalHead;
    // }
};
// https://leetcode.com/problems/palindrome-linked-list/description/
#include <iostream>
using namespace std;

// Definition for singly-linked list.
class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode()
    {
        val = 0;
        next = nullptr;
    }
    ListNode(int x)
    {
        val = x;
        next = nullptr;
    }
};

bool isPalindrome(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode *prev = nullptr;
    while (slow)
    {
        ListNode *next = slow->next;
        slow->next = prev;
        prev = slow;
        slow = next;
    }

    slow = prev;
    fast = head;
    while (slow)
    {
        if (fast->val != slow->val)
            return false;
        fast = fast->next;
        slow = slow->next;
    }
    return true;
}
// bool isPalindrome(ListNode* head) {
//     vector<int> elems;
//     while(head != nullptr)
//     {
//         elems.push_back(head->val);
//         head = head->next;
//     }
//     for(int i = 0, j = elems.size() - 1; i < j; i++, j--)
//     {
//         if (elems[i] != elems[j])
//             return false;
//     }
//     return true;
// }

int main()
{

    // Addition of linked list
    ListNode *one = new ListNode(1);
    ListNode *two = new ListNode(2);
    ListNode *three = new ListNode(3);
    ListNode *four = new ListNode(2);
    ListNode *five = new ListNode(1);

    // Initialize the next pointer
    // of every current pointer
    five->next = NULL;
    one->next = two;
    two->next = three;
    three->next = four;
    four->next = five;
    ListNode *temp = one;

    cout << boolalpha << isPalindrome(one);
}
// https://leetcode.com/problems/copy-list-with-random-pointer/solutions/43491/a-solution-with-constant-space-complexity-o-1-and-linear-time-complexity-o-n/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution
{
public:
    // Time Complexity: O(N)
    // Space Complexity: O(1) <--- Not counting space for the deep copy ll
    Node *copyRandomList(Node *head)
    {
        Node *temp = head;

        // Duplicate all the nodes in the same LL
        while (temp)
        {
            Node *next = temp->next;
            temp->next = new Node(temp->val);
            temp->next->next = next;
            temp = next;
        }

        // Duplicate all the random links
        temp = head;
        while (temp)
        {
            if (temp->random)
                temp->next->random = temp->random->next;
            temp = temp->next->next;
        }

        // Extract duplicated nodes & Restore original list
        temp = head;
        Node *newHead = new Node(0);
        Node *newTemp = newHead;
        while (temp)
        {
            newTemp->next = temp->next;
            newTemp = newTemp->next;

            Node *next = temp->next->next;
            temp->next = next;
            temp = next;
        }
        return newHead->next;
    }
    // // Time Complexity: O(N)
    // // Space Complexity: O(N) <--- For Unordered Map
    // Node* copyRandomList(Node* head)
    // {
    //     unordered_map<Node*, Node*> hm;
    //     Node *temp = head;

    //     while(temp)
    //     {
    //         hm[temp] = new Node(temp->val);
    //         temp = temp->next;
    //     }

    //     temp = head;
    //     while(temp)
    //     {
    //         hm[temp]->next = hm[temp->next];
    //         hm[temp]->random = hm[temp->random];
    //         temp = temp->next;
    //     }
    //     return hm[head];
    // }
};
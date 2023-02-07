#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int data)
    {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(N) ---> Recursion call stack
int depthRecursiveDFS(TreeNode *root)
{
    if (root == nullptr)
        return -1;

    return max(depthRecursiveDFS(root->left), depthRecursiveDFS(root->right)) + 1;
}

// Time Complexity: O(N)
// Space Complexity: O(N) ---> Storing Node pointers in Queue
int depthIterativeLevelOrder(TreeNode *root)
{
    queue<TreeNode *> q;
    q.push(root);

    int depth = 0;
    int qSize = 0;

    while (!q.empty())
    {
        qSize = q.size();
        for (int i = 0; i < qSize; i++)
        {
            TreeNode *curr = q.front();
            q.pop();
            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
        depth += 1;
    }
    return depth - 1;
}

int main()
{
    TreeNode *root = new TreeNode(0);
    TreeNode a(10);
    TreeNode b(20);
    TreeNode c(30);
    TreeNode d(40);
    TreeNode e(50);
    TreeNode f(60);
    root->left = &a;
    root->right = &b;
    root->right->right = &f;
    root->left->left = &c;
    root->left->left->right = &d;
    root->left->left->left = &e;
    cout << depthRecursiveDFS(root) << " ";
    cout << depthIterativeLevelOrder(root);
}
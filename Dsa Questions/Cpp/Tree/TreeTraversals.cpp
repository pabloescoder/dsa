#include <iostream>
#include <stack>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode()
    {
        data = 0;
        left = nullptr;
        right = nullptr;
    }
    TreeNode(int data)
    {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};

// DFS for a tree is the same as Preorder Traversal
// Time: O(n)
// Space: O(n)
void dfsIterative(TreeNode *root)
{
    if (root == nullptr)
    {
        cout << "Tree is empty.\n";
        return;
    }

    stack<TreeNode *> s;
    s.push(root);

    while (!s.empty())
    {
        TreeNode *curr = s.top();
        s.pop();
        cout << curr->data << " ";
        if (curr->right)
            s.push(curr->right);
        if (curr->left)
            s.push(curr->left);
    }
}

void dfsRecursive(TreeNode *root)
{
    if (root == nullptr)
        return;

    cout << root->data << " ";
    dfsRecursive(root->left);
    dfsRecursive(root->right);
}

// BFS for a tree is the same as Level Order Traversal
// Can be done iteratively only
// Time: O(n)
// Space: O(n)
void bfsIterative(TreeNode *root)
{
    if (root == nullptr)
    {
        cout << "Tree is empty.\n";
        return;
    }

    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *curr = q.front();
        q.pop();
        cout << curr->data << " ";
        if (curr->left)
            q.push(curr->left);
        if (curr->right)
            q.push(curr->right);
    }
}

int sum(TreeNode *root)
{
    if (root == nullptr)
        return 0;

    return root->data + sum(root->left) + sum(root->right);
}

int minVal(TreeNode *root)
{
    if (root == nullptr)
        return INT_MAX;

    return min({root->data, minVal(root->left), minVal(root->right)});
}

int maxDepth(TreeNode *root)
{
    if (root == nullptr)
        return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

int maxPathSum(TreeNode *root)
{
    if (root == nullptr)
        return INT_MIN;
    if (root->left == nullptr && root->right == nullptr)
        return root->data;
    return root->data + max(maxPathSum(root->left), maxPathSum(root->right));
}

int main()
{
    TreeNode *a = new TreeNode(1);
    TreeNode *b = new TreeNode(2);
    TreeNode *c = new TreeNode(3);
    TreeNode *d = new TreeNode(4);
    TreeNode *e = new TreeNode(5);
    TreeNode *f = new TreeNode(6);
    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->right = f;

    cout << "DFS: ";
    dfsIterative(a);
    cout << "\nDFS: ";
    dfsRecursive(a);
    cout << "\nBFS: ";
    bfsIterative(a);
    cout << "\nSum: " << sum(a);
    cout << "\nMin: " << minVal(a);
    cout << "\nMax Depth: " << maxDepth(a);
    cout << "\nMax Path Sum: " << maxPathSum(a);
}
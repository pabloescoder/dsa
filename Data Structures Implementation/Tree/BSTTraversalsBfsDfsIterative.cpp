#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class BstNode
{
public:
    int data;
    BstNode *left;
    BstNode *right;

    BstNode()
    {
        data = 0;
        left = nullptr;
        right = nullptr;
    }
    BstNode(int data)
    {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class BST
{
    BstNode *root;

public:
    BST()
    {
        root = nullptr;
    }

    BstNode *getRoot()
    {
        return root;
    }

    void insert(int data)
    {
        BstNode *newNode = new BstNode(data);
        if (root == nullptr)
        {
            root = newNode;
            return;
        }

        BstNode *currNode = root;
        BstNode *prevNode = nullptr;
        while (currNode)
        {
            prevNode = currNode;
            if (data <= currNode->data)
                currNode = currNode->left;
            else if (data > currNode->data)
                currNode = currNode->right;
        }
        if (data <= prevNode->data)
            prevNode->left = newNode;
        else
            prevNode->right = newNode;
    }

    void remove(int data)
    {
        BstNode *prevNode = nullptr;
        BstNode *currNode = root;
        while (currNode != nullptr && currNode->data != data)
        {
            prevNode = currNode;
            if (data < currNode->data)
                currNode = currNode->left;
            else if (data > currNode->data)
                currNode = currNode->right;
        }

        if (currNode == nullptr)
        {
            cout << "Given element is not present in the BST\n";
            return;
        }

        if (currNode->left == nullptr || currNode->right == nullptr) // Node to be deleted has atmost 1 child
        {
            if (prevNode == nullptr) // If there is only 1 node (root) in the BST
            {
                root = nullptr;
                return;
            }
            BstNode *newCurr;
            if (currNode->left == nullptr)
                newCurr = currNode->right;
            else
                newCurr = currNode->left;

            if (prevNode->left == currNode)
                prevNode->left = newCurr;
            else
                prevNode->right = newCurr;
            delete currNode;
        }
        else // Node to be deleted has 2 children
        {
            BstNode *prevMinInRightSubtree = nullptr;
            BstNode *minInRightSubtree = currNode->right;
            while (minInRightSubtree->left != nullptr)
            {
                prevMinInRightSubtree = minInRightSubtree;
                minInRightSubtree = minInRightSubtree->left;
            }
            currNode->data = minInRightSubtree->data;
            if (prevMinInRightSubtree == nullptr)
                currNode->right = minInRightSubtree->right;
            else
                prevMinInRightSubtree->left = minInRightSubtree->right;
            delete minInRightSubtree;
        }
    }

    bool search(int data)
    {
        BstNode *currNode = root;
        while (currNode)
        {
            if (data < currNode->data)
                currNode = currNode->left;
            else if (data > currNode->data)
                currNode = currNode->right;
            else
                return true;
        }
        return false;
    }

    void levelOrder() // BFS
    {
        if (root == nullptr)
        {
            cout << "BST is empty.\n";
            return;
        }
        queue<BstNode *> discovered;
        discovered.push(root);

        while (!discovered.empty())
        {
            BstNode *current = discovered.front();
            cout << current->data << " ";
            discovered.pop();
            if (current->left != nullptr)
                discovered.push(current->left);
            if (current->right != nullptr)
                discovered.push(current->right);
        }
        cout << endl;
    }

    void preOrder()
    {
        if (root == nullptr)
        {
            cout << "BST is empty.\n";
            return;
        }

        stack<BstNode *> s;
        s.push(root);
        while (!s.empty())
        {
            BstNode *current = s.top();
            s.pop();
            cout << current->data << " ";
            if (current->right)
                s.push(current->right);
            if (current->left)
                s.push(current->left);
        }
        cout << endl;
    }

    void inOrder()
    {
        if (root == nullptr)
        {
            cout << "BST is empty.\n";
            return;
        }
        stack<BstNode *> s;
        BstNode *current = root;
        while (!s.empty() || current != nullptr)
        {
            if (current != nullptr)
            {
                s.push(current);
                current = current->left;
            }
            else
            {
                current = s.top();
                s.pop();
                cout << current->data << " ";
                current = current->right;
            }
        }
        cout << endl;
    }

    void postOrder()
    {
        if (root == nullptr)
        {
            cout << "BST is empty.\n";
            return;
        }

        stack<BstNode *> s;
        s.push(root);
        stack<int> output;

        while (!s.empty())
        {
            BstNode *current = s.top();
            s.pop();
            output.push(current->data);

            if (current->left)
                s.push(current->left);
            if (current->right)
                s.push(current->right);
        }

        while (!output.empty())
        {
            cout << output.top() << " ";
            output.pop();
        }
        cout << '\n';
    }
};

int main()
{
    BST bst;
    bst.insert(20);
    bst.insert(15);
    bst.insert(30);
    bst.insert(10);
    bst.insert(12);
    bst.insert(25);
    bst.insert(37);
    bst.insert(40);
    bst.insert(43);
    bst.levelOrder();
    bst.preOrder();
    bst.inOrder();
    bst.postOrder();
    bst.remove(20);
    bst.remove(25);
    bst.levelOrder();
    bst.preOrder();
    bst.inOrder();
    bst.postOrder();
    cout << boolalpha;
    cout << bst.search(37) << '\n';
    cout << bst.search(25) << '\n';
}
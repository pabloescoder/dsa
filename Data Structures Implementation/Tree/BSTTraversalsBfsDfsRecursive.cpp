#include <iostream>
#include <algorithm>
#include <queue>
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

    BstNode *findMin(BstNode *root)
    {
        if (root->left == nullptr)
        {
            return root;
        }
        return findMin(root->left);
    }

public:
    BST()
    {
        root = nullptr;
    }

    BstNode *insert(BstNode *root, int data)
    {
        if (root == nullptr)
        {
            return new BstNode(data);
        }

        if (data <= root->data)
            root->left = insert(root->left, data);
        else
            root->right = insert(root->right, data);
        return root;
    }
    void insert(int data)
    {
        root = insert(root, data);
    }

    BstNode *remove(BstNode *root, int data)
    {
        if (root == nullptr)
            return nullptr;

        if (data < root->data)
        {
            root->left = remove(root->left, data);
        }
        else if (data > root->data)
        {
            root->right = remove(root->right, data);
        }
        else // Node found
        {
            if (root->left == nullptr || root->right == nullptr) // Atmost 1 child present
            {
                BstNode *prevRoot = root;
                if (root->left == nullptr)
                    root = root->right;
                else
                    root = root->left;
                delete prevRoot;
            }
            else // Both children are present
            {
                BstNode *minInRightSub = findMin(root->right);
                root->data = minInRightSub->data;
                root->right = remove(root->right, minInRightSub->data);
            }
        }
        return root;
    }
    void remove(int data)
    {
        root = remove(root, data);
    }

    bool search(BstNode *root, int data)
    {
        if (root == nullptr)
            return false;

        if (data < root->data)
            return search(root->left, data);
        else if (data > root->data)
            return search(root->right, data);
        else
            return true;
    }
    bool search(int data)
    {
        return search(root, data);
    }

    void levelOrder() // Can be done iteratively only.
    {
        if (root == nullptr)
        {
            cout << "BST is empty.\n";
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

    void preOrder(BstNode *root)
    {
        if (root == nullptr)
            return;

        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
    void preOrder()
    {
        preOrder(root);
        cout << endl;
    }

    void inOrder(BstNode *root)
    {
        if (root == nullptr)
            return;

        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
    void inOrder()
    {
        inOrder(root);
        cout << endl;
    }

    void postOrder(BstNode *root)
    {
        if (root == nullptr)
            return;

        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
    void postOrder()
    {
        postOrder(root);
        cout << endl;
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
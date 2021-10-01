#include <iostream>
#include <algorithm>
#include <array>

class AVLTree
{
    class AVLNode
    {
    public:
        int value;
        int height;
        AVLNode *leftChild;
        AVLNode *rightChild;
        AVLNode(int value)
            : value(value), height(0), leftChild(nullptr), rightChild(nullptr)
        {
        }
    };

    AVLNode *root = nullptr;

    AVLNode *insert(AVLNode *root, int value)
    {
        if (root == nullptr)
            return new AVLNode(value);
        if (value < root->value)
            root->leftChild = insert(root->leftChild, value);
        else
            root->rightChild = insert(root->rightChild, value);

        setHeight(root);
        root = balance(root);
        return root;
    }

    AVLNode *balance(AVLNode *root)
    {
        if (isLeftHeavy(root))
        {
            if (balanceFactor(root->leftChild) < 0)
                root->leftChild = leftRotate(root->leftChild);
            return rightRotate(root);
        }

        else if (isRightHeavy(root))
        {
            if (balanceFactor(root->rightChild) > 0)
                root->rightChild = rightRotate(root->rightChild);
            return leftRotate(root);
        }
        return root;
    }

    AVLNode *leftRotate(AVLNode *root)
    {
        AVLNode *newRoot = root->rightChild;
        root->rightChild = newRoot->leftChild;
        newRoot->leftChild = root;
        setHeight(root);
        setHeight(newRoot);
        return newRoot;
    }

    AVLNode *rightRotate(AVLNode *root)
    {
        AVLNode *newRoot = root->leftChild;
        root->leftChild = newRoot->rightChild;
        newRoot->rightChild = root;
        setHeight(root);
        setHeight(newRoot);
        return newRoot;
    }

    void setHeight(AVLNode *node)
    {
        node->height = std::max(height(node->leftChild), height(node->rightChild)) + 1;
    }

    int balanceFactor(AVLNode *node)
    {
        return node == nullptr ? 0 : height(node->leftChild) - height(node->rightChild);
    }

    bool isLeftHeavy(AVLNode *node)
    {
        return balanceFactor(node) > 1;
    }

    bool isRightHeavy(AVLNode *node)
    {
        return balanceFactor(node) < -1;
    }

    int height(AVLNode *node)
    {
        return node == nullptr ? -1 : node->height;
    }

    void inOrderTraversal(AVLNode *root)
    {
        if (root == nullptr)
            return;
        inOrderTraversal(root->leftChild);
        std::cout << (root->value) << " ";
        inOrderTraversal(root->rightChild);
    }

    void preOrderTraversal(AVLNode *root)
    {
        if (root == nullptr)
            return;
        std::cout << (root->value) << " ";
        preOrderTraversal(root->leftChild);
        preOrderTraversal(root->rightChild);
    }

    void postOrderTraversal(AVLNode *root)
    {
        if (root == nullptr)
            return;
        postOrderTraversal(root->leftChild);
        postOrderTraversal(root->rightChild);
        std::cout << (root->value) << " ";
    }

    void levelOrderTraversal(AVLNode *root)
    {
        for (int i = 1; i <= height(root); i++)
            print(root, i);
    }

    void print(AVLNode *root, int level)
    {
        if (root == nullptr)
            return;
        if (level == 1)
            std::cout << (root->value) << " ";
        else if (level > 1)
        {
            print(root->leftChild, level - 1);
            print(root->rightChild, level - 1);
        }
    }

public:
    void insert(int value)
    {
        root = insert(root, value);
    }

    void inOrderTraversal()
    {
        inOrderTraversal(root);
    }

    void preOrderTraversal()
    {
        preOrderTraversal(root);
    }

    void levelOrderTraversal()
    {
        levelOrderTraversal(root);
    }

    void postOrderTraversal()
    {
        postOrderTraversal(root);
    }
};

int main()
{
    AVLTree avltree;
    std::array<int, 5> numbers{1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++)
        avltree.insert(numbers[i]);
    avltree.insert(15);
    avltree.insert(23);
    avltree.insert(3);
    avltree.insert(1);
    avltree.insert(12);
    avltree.insert(30);
    avltree.insert(17);
    avltree.insert(7);
    avltree.insert(6);
    avltree.insert(16);
    avltree.insert(20);
    avltree.insert(38);
    avltree.inOrderTraversal();
    std::cout << "\n";
    avltree.preOrderTraversal();
    std::cout << "\n";
    avltree.postOrderTraversal();
    std::cout << "\n";
    avltree.levelOrderTraversal();
}

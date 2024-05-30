/*
Author: Kasmik Regmi (@Kasmik004 on GitHub, rkasmik@gmail.com)
License: Unlicense

Attribution:

Kasmik Regmi (52)
CE-22 (Undergraduate, II-I)

Department of Computer Science and Engineering
Kathmandu University
*/

#include <iostream>

struct Node
{
    int data;
    int key;
    Node *parent;
    Node *left;
    Node *right;

    Node(int k, int val) : key(k), data(val), parent(nullptr), left(nullptr), right(nullptr) {}
};

class LinkedList_BST
{
private:
    Node *HEAD = nullptr;

public:
    bool isEmpty()
    {
        return HEAD == nullptr;
    }

    bool searchBST(int targetKey)
    {
        if (HEAD == nullptr)
        {
            return false;
        }
        Node *p = HEAD;
        while (p != nullptr)
        {
            if (p->key == targetKey)
            {
                return true;
            }
            else if (p->key < targetKey)
            {
                p = p->right;
            }
            else
            {
                p = p->left;
            }
        }
        return false;
    }

    bool addBST(int key, int value)
    {
        if (searchBST(key))
        {
            return false;
        }

        Node *newNode = new Node(key, value);
        if (HEAD == nullptr)
        {
            HEAD = newNode;
            return true;
        }

        Node *p = HEAD;
        Node *q = nullptr;
        while (p != nullptr)
        {
            q = p;
            if (p->key < key)
            {
                p = p->right;
            }
            else
            {
                p = p->left;
            }
        }

        if (q->key < key)
        {
            q->right = newNode;
        }
        else
        {
            q->left = newNode;
        }
        newNode->parent = q;
        return true;
    }

    void inOrderTraversal(Node *node)
    {
        if (node != nullptr)
        {
            inOrderTraversal(node->left);
            std::cout << "Key: " << node->key << ", Data: " << node->data << std::endl;
            inOrderTraversal(node->right);
        }
    }

    void printInOrder()
    {
        inOrderTraversal(HEAD);
    }
};
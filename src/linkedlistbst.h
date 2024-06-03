/*
Author: Kasmik Regmi (@Kasmik004 on GitHub, rkasmik@gmail.com)
License: Unlicense

Attribution:

Kasmik Regmi (52)
CE-22 (Undergraduate, II-I)

Department of Computer Science and Engineering
Kathmandu University
*/
#ifndef LINKEDLIST_BST_H
#define LINKEDLIST_BST_H

#include <iostream>
#include "BST.h"

struct Node
{
public:
    int data;
    int key;
    Node *left;
    Node *right;

    Node(int k, int val) : key(k), data(val), left(nullptr), right(nullptr) {}
};

class LinkedList_BST : public BinarySearchTree
{
private:
    Node *HEAD = nullptr;

public:
    bool isEmpty()
    {
        return HEAD == nullptr;
    }

    bool searchBST(int targetKey) const
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
        return true;
    }

    bool removeBST(int key)
    {
        if (!searchBST(key))
        {
            return false;
        }

        Node *p = HEAD;
        Node *q = nullptr;
        while (p->key != key)
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

        if (p->left == nullptr && p->right == nullptr)
        {
            if (q == nullptr)
            {
                HEAD = nullptr;
            }
            else if (q->left == p)
            {
                q->left = nullptr;
            }
            else
            {
                q->right = nullptr;
            }
            delete p;
        }
        else if (p->left == nullptr)
        {
            if (q == nullptr)
            {
                HEAD = p->right;
            }
            else if (q->left == p)
            {
                q->left = p->right;
            }
            else
            {
                q->right = p->right;
            }
            delete p;
        }
        else if (p->right == nullptr)
        {
            if (q == nullptr)
            {
                HEAD = p->left;
            }
            else if (q->left == p)
            {
                q->left = p->left;
            }
            else
            {
                q->right = p->left;
            }
            delete p;
        }
        else
        {
            Node *r = p->right;
            Node *s = p;
            while (r->left != nullptr)
            {
                s = r;
                r = r->left;
            }
            p->key = r->key;
            p->data = r->data;
            if (s == p)
            {
                s->right = r->right;
            }
            else
            {
                s->left = r->right;
            }
            delete r;
        }
        return true;
    }
};

#endif

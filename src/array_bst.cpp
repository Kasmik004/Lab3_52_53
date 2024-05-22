#include <iostream>
#include "BST.h"

class Node
{
public:
    int key;
    int value;

    Node(int key, int value = 0) : key(key), value(value) {}
};

const int ARRAY_SIZE = 255;

class ArrayBinarySearchTree : public BinarySearchTree
{

    Node **array = nullptr;

    /*
    Attempts to find the largest child of the node at the index
    using in-order traversal.

    @returns
    `int`: The index of the largest child.
    */
    int getLargestNode(int index)
    {
        if (array[2 * index + 2] != nullptr)
        {
            return getLargestNode(2 * index + 2);
        }

        return index;
    }

    /*
    Attempts to find the smallest child of the node at the index
    using in-order traversal.

    @returns
    `int`: The index of the smallest child.
    */
    int getSmallestNode(int index)
    {
        if (array[2 * index + 1] != nullptr)
        {
            return getSmallestNode(2 * index + 1);
        }

        return index;
    }

    /*
    Abstracts the addition of a node to the binary search tree.

    The recursion may stop at the first empty node or when the
    internal array overflows.

    @returns
    `bool`: `true` if the node was added successfully, `false` otherwise.
    */
    bool addBSTAsNode(int index, Node *node)
    {
        if (index > ARRAY_SIZE)
        {
            return false;
        }

        if (array[index] == nullptr)
        {
            array[index] = node;
            return true;
        }

        if (array[index]->key < node->key)
        {
            return addBSTAsNode(2 * index + 2, node);
        }
        return addBSTAsNode(2 * index + 1, node);
    }

    /*
    Searches for the index of the node with the given key in O(log n) time.

    @returns
    `int`: The index of the node with the given key, `-1` otherwise.
    */
    int searchIndex(int key) const
    {
        int current = 0;

        while (array[current] != nullptr && array[current]->key != key)
        {

            if (array[current]->key < key)
            {
                current = 2 * current + 2;
            }
            else
            {
                current = 2 * current + 1;
            }
        }

        if (array[current] == nullptr)
        {
            return -1;
        }

        return current;
    }

    /*
    Recursively removes the node at the given index.

    When the node has no children, it is deleted.

    Else, if the node has a left child, the largest child of the left child
    is moved to the node's position.

    Else, if the node has a right child, the smallest child of the right child
    is moved to the node's position.
    */
    bool removeIndex(int index)
    {
        if (index > ARRAY_SIZE || array[index] == nullptr)
        {
            return false;
        }

        int l_index = 2 * index + 1;
        int r_index = 2 * index + 2;

        int targetIndex = -1;

        if (array[l_index] != nullptr)
        {
            targetIndex = getLargestNode(l_index);
        }
        else if (array[r_index] != nullptr)
        {
            targetIndex = getSmallestNode(r_index);
        }

        if (targetIndex == -1)
        {
            delete array[index];
            array[index] = nullptr;
        }
        else
        {
            std::swap(array[index], array[targetIndex]);
            return removeIndex(targetIndex);
        }

        return true;
    }

public:
    /*
    Initializes the internal array with `nullptr` values.
    */
    ArrayBinarySearchTree()
    {

        array = new Node *[ARRAY_SIZE];

        for (int i = 0; i < ARRAY_SIZE; i++)
            array[i] = nullptr;
    }

    /*
    Deallocates the memory allocated for the internal array.
    */
    ~ArrayBinarySearchTree()
    {
        for (int i = 0; i < ARRAY_SIZE; i++)
        {
            if (array[i] != nullptr)
            {
                delete array[i];
            }
        }

        delete[] array;
    }

    /*
    Indicates whether the binary search tree is empty.

    @returns
    `bool`: `true` if the binary search tree is empty, `false` otherwise.
    */
    bool isEmpty()
    {
        return array[0] == nullptr;
    }

    /*
    Adds a key-value pair to the binary search tree.

    Also coerces a search operation ahead of time.

    @returns
    `bool`: `true` if the node was added successfully, `false` otherwise.
    */
    bool addBST(int key, int value)
    {
        if (searchBST(key))
        {
            return false;
        }
        return addBSTAsNode(0, new Node(key, value));
    }

    /*
    Removes a node with the given key from the binary search tree.

    @returns
    `bool`: `true` if the node was removed successfully, `false` otherwise.
    */
    bool removeBST(int key)
    {
        int keyIndex = searchIndex(key);

        if (keyIndex == -1)
        {
            return false;
        }

        return removeIndex(keyIndex);
    }

    /*
    Searches for a node with the given key in the binary search tree.

    @returns
    `bool`: `true` if the node with the given key was found, `false` otherwise.
    */
    bool searchBST(int key) const
    {
        return searchIndex(key) != -1;
    };
};

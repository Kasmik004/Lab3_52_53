#ifndef BST_H
#define BST_H

class BinarySearchTree
{
public:
    virtual bool isEmpty() = 0;
    virtual bool addBST(int, int) = 0;
    virtual bool removeBST(int) = 0;
    virtual bool searchBST(int) const = 0;
};

#endif

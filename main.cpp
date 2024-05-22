#include <iostream>

#include "src/BST.h"
#include "src/array_bst.cpp"
// #include "src/linkedlist_bst.cpp"

int main()
{

    bool useArray = true;

    BinarySearchTree *bst = nullptr;

    if (useArray)
    {
        bst = new ArrayBinarySearchTree();
    }
    else
    {
        // bst = new LinkedListBinarySearchTree();
    }

    if (bst->isEmpty())
    {
        std::cout << "BST is empty." << std::endl;
    }

    bst->addBST(1, 1);
    bst->addBST(2, 2);
    bst->addBST(3, 3);
    bst->addBST(4, 4);
    bst->addBST(5, 5);

    if (bst->searchBST(5))
    {
        std::cout << "Found 5." << std::endl;
    }

    if (!bst->searchBST(6))
    {
        std::cout << "Did not find 6." << std::endl;
    }

    if (bst->removeBST(1))
    {
        std::cout << "Removed 1." << std::endl;
    }

    if (!bst->searchBST(1))
    {
        std::cout << "Did not find 1." << std::endl;
    }

    if (!bst->isEmpty())
    {
        std::cout << "BST is not empty." << std::endl;
    }

    return 0;
}
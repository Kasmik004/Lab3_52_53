class BST{
    private:

    public:
        virtual bool isEmpty() = 0;
        virtual bool addBST(int key, int value) = 0;
        virtual void removeBST(int keyToDelete) = 0;
        virtual bool searchBST(int targetKey) = 0;
};
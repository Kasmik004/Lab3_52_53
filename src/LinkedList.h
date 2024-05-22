#include<BST.h>


struct Node{
    int data;
    int key;
    Node* parent;
    Node* l;
    Node* r;
};

class LinkedList_BST: public BST{
    private:
        Node* HEAD = nullptr;
        Node* TAIL = nullptr;

    public:
        bool isEmpty(){
            if(HEAD == nullptr){
                return true;
            }
            return false;
        }

        bool searchBST(int targetKey){
            if(HEAD->key == targetKey){
                return true;
            }
            Node *p = this->HEAD;
            while(p != nullptr){
                if(p->key == targetKey){
                    return true;
                }
                else if(p->key <targetKey){
                    p = p->r;
                }
                else{
                    p=p->l;
                }
            }
            return false;
        }

        bool addBST(int key, int value){
            if(!searchBST(key)){
                return true;
            }
            else{
                return false;
            }
        }
};
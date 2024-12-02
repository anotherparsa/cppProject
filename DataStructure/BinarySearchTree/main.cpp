#include <iostream>

using namespace std;

class Node{
    public:
        int value;
        Node* left;
        Node* right;

        Node(int value){
            this->value = value;
            this->left = nullptr;
            this->right = nullptr;
        }
 
};

class BinarySearchTree{
    private:
        Node* root;
    
    public:
        BinarySearchTree(){
            this->root = nullptr;
        }


}
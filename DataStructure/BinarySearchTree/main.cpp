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

        void insert_node(int value){
            Node* new_node = new Node(value);
            if (this->root == nullptr){
                this->root = new_node;
                return;
            }else{
                Node* temp = this->root;
                while(true){
                    if (new_node->value == temp->value){
                        return;
                    }else{
                        if(new_node->value < temp->value){
                            if (temp->left == nullptr){
                                temp->left == new_node;
                                return;
                            }else{
                                temp = temp->left;
                            }
                        }else{
                            if (temp->right == nullptr){
                                temp->right = new_node;
                                return;
                            }else{
                                temp = temp->right;
                            }
                        }
                    }
                }
            }
        }


};

int main(){

}
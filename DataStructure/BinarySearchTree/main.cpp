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

        bool contain(int value){
            if (this->root == nullptr){
                return false;
            }else{
                Node* temp = this->root;
                while (temp != nullptr){
                    if (value < temp->value){
                        temp = temp->left;
                    }else if (value > temp->value){
                        temp = temp -> right;
                    }else{
                        return true;
                    }
                }
            }
            return false;
        }


};

int main(){
    BinarySearchTree* MyBST = new BinarySearchTree;
    MyBST->insert_node(8);
    MyBST->insert_node(10);
    MyBST->insert_node(100);
    MyBST->insert_node(2);
    MyBST->insert_node(1);
    MyBST->insert_node(5);
    cout << MyBST->contain(100) << endl;
    cout << MyBST->contain(101) << endl;
}
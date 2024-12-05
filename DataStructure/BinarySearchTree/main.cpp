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

class QueueNode{
    public:
        Node* treeNode;
        QueueNode* next;
        QueueNode(Node* treeNode){
            this->treeNode = treeNode;
            this->next = nullptr;
        }
};

class Queue{
    public:
        int length;
        QueueNode* first;
        QueueNode* last;
        Queue(){
            this->first = nullptr;
            this->last = nullptr;
            this->length = 0;
        }
        bool is_queue_empty(){
            return (this->length == 0);
        }
        void Enqueue(QueueNode* new_node){
            if (this->is_queue_empty()){
                this->first = new_node;
                this->last = new_node;
            }else{
                last->next = new_node;
                this->last = new_node;
            }
            this->length++;
        }
        QueueNode* Dequeue() {
            if (this->length == 0) {
                return nullptr; 
            }else {
                QueueNode* temp = this->first;
                if (length == 1) {
                    this->first = nullptr;
                    this->last = nullptr;
                } else {
                    this->first = first->next;
                }
                this->length--;
                return temp;
            }
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
                        delete new_node;
                        return;
                    }else{
                        if(new_node->value < temp->value){
                            if (temp->left == nullptr){
                                temp->left = new_node;
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
        void Breadth_First_Search(){
            Queue* BFSQueue = new Queue();
            BFSQueue->Enqueue(new QueueNode(this->root));
            while (BFSQueue->length > 0){
                QueueNode* current_node = BFSQueue->Dequeue();
                if (current_node != nullptr){
                    cout << current_node->treeNode->value << " " ;
                    if (current_node->treeNode->left != nullptr){
                        BFSQueue->Enqueue(new QueueNode(current_node->treeNode->left));
                    }
                    if (current_node->treeNode->right != nullptr){
                        BFSQueue->Enqueue(new QueueNode(current_node->treeNode->right));
                    }
                }
            }
            cout << endl;
        }

        void Depth_First_Search_PreOrder(Node* CurrentNode){
            cout << CurrentNode->value << " ";
            if (CurrentNode->left != nullptr){
                this->Depth_First_Search_PreOrder(CurrentNode->left);
            }
            if (CurrentNode->right != nullptr){
                this->Depth_First_Search_PreOrder(CurrentNode->right);
            }
        }

        void Depth_First_Search_PreOrder(){
            this->Depth_First_Search_PreOrder(this->root);
            cout << endl;
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
    MyBST->Breadth_First_Search();      
    MyBST->Depth_First_Search_PreOrder();
}
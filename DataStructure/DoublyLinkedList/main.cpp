#include <iostream>

using namespace std;

class Node{
    public:
        int value;
        Node* next;
        Node* prev;

        Node(int value){
            this->value = value;
            this->next = nullptr;
            this->prev = nullptr;
        }
};

class DoublyLinkedList{
    private:
        Node* head;
        Node* tail;
        int length;
    
    public:
        DoublyLinkedList(){
            this->head = nullptr;
            this->tail = nullptr;
            this->length = 0;
        }

        bool is_list_empty(){
            return (this->head == nullptr || this->length == 0);
        }

        void print_head_of_list(){
            if (this->is_list_empty()){
                cout << "There are no Nodes in the list" << endl;
            }else{
                cout << "The Head address : " << this->head << " The Head value : " << this->head->value << endl;
            }
        }

        void print_tail_of_list(){
            if (this->is_list_empty()){
                cout << "There are no Nodes in the list" << endl;
            }else{
                cout << "The Tail address : " << this->tail << " The Tail value : " << this->tail->value << endl;
            }
        }

        void print_length(){
            cout << "Length of the list : " << this->length << endl;
        }

        void append_node(int value){
            Node* new_node = new Node(value);
            if (this->is_list_empty()){
                this->head = new_node;
                this->tail = new_node;
            }else{
                this->tail->next = new_node;
                new_node->prev = this->tail;
                this->tail = new_node;
            }
            this->length++;
        }





};


int main(){
    DoublyLinkedList* MyDoublyLinkedList = new DoublyLinkedList();
}
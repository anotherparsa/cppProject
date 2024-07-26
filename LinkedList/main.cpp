#include <iostream>

using namespace std;

class Node{
    public:
        int value;
        Node* next;
        Node(int value){
            this->value = value;
            this->next = nullptr;
        }
};

class LinkedList{
    private:
        Node* head;
        Node* tail;
        int length;
    public:
        LinkedList(){
            this->head = nullptr;
            this->tail = nullptr;
            this->length = 0;
        }

        bool is_list_empty(){
            return (this->head == nullptr || this->length == 0);
        }

        void print_head(){
            if (this->is_list_empty()){
                cout << "There are no Nodes in the list" << endl;
            }else{
                cout << "The Head address : " << this->head << " The Head value : " << this->head->value << endl;
            }
        }

        void print_tail(){
            if (this->is_list_empty()){
                cout << "There are no Nodes in the list" << endl;
            }else{
                cout << "The Tail address : " << this->tail << " The Tail value : " << this->tail->value << endl;
            }
        }

        void print_length(){
            cout << "Lenght of the list : " << this->length << endl;
        }

        void print_list(){
            if (this->is_list_empty()){
                cout << "There are no Nodes in the list" << endl;
            }else{
                cout << "List Items: " << endl;
                Node* temp = this->head;
                while(temp != nullptr){
                    cout << temp->value << " ";
                    temp = temp->next;
                }
                cout << endl;
            }
        }

        Node* get_node(int index){
            if (this->is_list_empty()){
                cout << "There are no Nodes in the list " << endl;
                return nullptr;
            }else if (index < 0 || index >= this->length){
                cout << "Invalid index " << endl;
                return nullptr;
            }else{
                Node* temp = this->head;
                for (int i = 0 ; i < this->length ; i++){
                    temp = temp->next;
                }
                return temp;
            }
        }

        void append_node(int value){
            Node* new_node = new Node(value);
            if (this->is_list_empty()){
                this->head = new_node;
                this->tail = new_node;
            }else{
                this->tail->next = new_node;
                this->tail = new_node;
            }
            this->length++;
            cout << "New Node with the value of " << value << " Has been added to the end of the list" << endl;
        }

        void prepend_node(int value){
            Node* new_node = new Node(value);
            if (this->is_list_empty()){
                this->head = new_node;
                this->tail = new_node;
            }else{
                new_node->next = this->head;
                this->head = new_node;
            }
            this->length++;
            cout << "New Node with the value of " << value << " Has been added to the beginning of the list" << endl;
        }

};

int main(){
    LinkedList* my_linked_list = new LinkedList;
    my_linked_list->append_node(1);
    my_linked_list->append_node(2);
    my_linked_list->append_node(3);
    my_linked_list->print_head();
    my_linked_list->print_tail();
    my_linked_list->print_length();
    my_linked_list->print_list();
    my_linked_list->append_node(4);
    my_linked_list->print_head();
    my_linked_list->print_tail();
    my_linked_list->print_length();
    my_linked_list->print_list();
    my_linked_list->prepend_node(5);
    my_linked_list->print_head();
    my_linked_list->print_tail();
    my_linked_list->print_length();
    my_linked_list->print_list();
}
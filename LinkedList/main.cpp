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
                cout << "Invalid Index " << endl;
                return nullptr;
            }else{
                Node* temp = this->head;
                for (int i = 0 ; i < index ; i++){
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

        void delete_last_node(){
            if (this->is_list_empty()){
                cout << "There are no Nodes in the list" << endl;
            }else if (this->length == 1){
                Node* temp = this->head;
                cout << "Node with the value of " << temp->value << " Has been deleted from the end of the list" << endl;
                delete temp;
                this->length--;
                this->head = nullptr;
                this->tail = nullptr;
            }else{
                Node* temp = this->tail;
                Node* previous_node = this->get_node(this->length - 2);
                previous_node->next = nullptr;
                this->tail = previous_node;
                cout << "Node with the value of " << temp->value << " Has been deleted from the end of the list" << endl;
                delete temp;
                this->length--;
            }
        }

        void delete_first_node(){
            if (this->is_list_empty()){
                cout << "There are no Nodes in the list" << endl;
            }else if (this->length == 1){
                Node* temp = this->head;
                cout << "Node with the value of " << temp->value << " Has been deleted from the beginning of the list" << endl;
                delete temp;
                this->length--;
                this->head = nullptr;
                this->tail = nullptr;
            }else{
                Node* temp = this->head;
                this->head = this->head->next;
                cout << "Node with the value of " << temp->value << " Has been deleted from the beginning of the list" << endl;
                delete temp;
                this->length--;
            }
        }

        void set_node_value(int index, int value){
            if (this->is_list_empty()){
                cout << "There are no Nodes in the list" << endl;
            }else if (index < 0 || index >= this->length){
                cout << "Invalid Index" << endl;
            }else{
                Node* temp = this->get_node(index);
                cout << "Node at the index of " << index << " Has the value of " << temp->value ;
                temp->value = value;
                cout << " Now the value is set to " << value << endl;
            }
        }
};

int main(){
    LinkedList* my_linked_list = new LinkedList;
    my_linked_list->append_node(1);
    my_linked_list->append_node(2);
    my_linked_list->print_head();
    my_linked_list->print_tail();
    my_linked_list->print_length();
    my_linked_list->print_list();
    my_linked_list->delete_first_node();
    my_linked_list->delete_first_node();
    my_linked_list->print_head();
    my_linked_list->print_tail();
    my_linked_list->print_length();
    my_linked_list->print_list();
    my_linked_list->delete_first_node();
    my_linked_list->append_node(5);
    my_linked_list->append_node(6);
    my_linked_list->set_node_value(0, 10);
    my_linked_list->set_node_value(1, 222);
    my_linked_list->set_node_value(2, 233);
    my_linked_list->append_node(32);
    my_linked_list->set_node_value(2, 320);
    my_linked_list->print_head();
    my_linked_list->print_tail();
    my_linked_list->print_length();
    my_linked_list->print_list();

}
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
        //makes a Linked List with head node pointing to nullptr, tail node pointing to nullptr and length of 0.
        LinkedList(){
            this->head = nullptr;
            this->tail = nullptr;
            this->length = 0;
        }

        //it will delete all nodes and free up the memory after the list got deleted.
        ~LinkedList(){
            this->purge_list();
        }

        //checks if the length is 0 which means the list is empty.
        bool is_list_empty(){
            return (this->length == 0);
        }

        //first check if the list is empty or not if the list is empty it will return null pointer.
        //if the list is not empty it will return head node.
        Node* return_head(){
            if (!this->is_list_empty()){
                return (this->head);
            }else{
                return nullptr;
            }
        }

        //first check if the list is empty or not if the list is empty it will return null pointer.
        //if the list is not empty it will return tail node.
        Node* return_tail(){
            if (!this->is_list_empty()){
                return (this->tail);
            }else{
                return nullptr;
            }
        }

        //returns the length of the list.
        int return_length(){
            return this->length;
        }

        //first it checks if the list is empty or not, if it is it will show a message.
        //then it will make a temp node and the value is head node,and puts it into a while loop
        //the loop will go, while the value of temp node is not equal to nullptr.
        //it will show the value of current temp node which is the head node and after that 
        //will go to the next node and it keeps doing it until it shows the last node value and the value of temp node 
        //will be nullptr and then it will gets out of the loop
        void print_list_elements(){
            if (!this->is_list_empty()){
                cout << "List Items: " << endl;
                Node* temp = this->head;
                while(temp != nullptr){
                    cout << temp->value << " ";
                    temp = temp->next;
                }
                cout << endl;
            }else{
                cout << "There are no Nodes in the list!" << endl;
            }
        }

        //it takes an int as index.
        //first it checks if the list is empty or not, if it is, it will return null pointer.
        //if it's not it will check if the index is valid or not. index must be bigger than 0 and smaller than the length of the list
        //otherwise it's an invalid index.
        //if the index is valid it will make a temp node with the value of head node.
        //and go forward index times in sequence to reach the node at the index provided.
        //then it will return that node
        Node* get_node(int index){
            if (!this->is_list_empty()){
                if (!(index < 0 || index >= this->length)){
                    Node* temp = this->head;
                    for (int i = 0 ; i < index ; i++){
                        temp = temp->next;
                    }
                    return temp;
                }else{
                    return nullptr;
                }
            }else{
                return nullptr;
            }
        }

        //it will take an int as value of the new node
        //then it will make a new node by passing it to the constructor of Node class
        //when the new node is made, if will check if the list is empty or not, if it's empty that means new node is going 
        //to be the first node in the list, so both head and tail nodes will point to this node.
        //if the list is not empty that menas there are already nodes exist in the list and the new node must be placed after them
        //so the next node of the current tail node must be new node
        //after that the new node will be the last node and the tail node will point to it.
        //then we increment the list's length by one since a new node has been added.
        void append_node(int value){
            Node* new_node = new Node(value);
            if (!this->is_list_empty()){
                this->tail->next = new_node;
                this->tail = new_node;
            }else{
                this->head = new_node;
                this->tail = new_node;
            }
            this->length++;
        }

        //it will take an int as value of the new node
        //then it will make a new node by passing it to the constructor of Node class
        //when the new node is made, if will check if the list is empty or not, if it's empty that means new node is going 
        //to be the first node in the list, so both head and tail nodes will point to this node.
        //if the list is not empty that menas there are already nodes exist in the list and the new node must be placed before them
        //so the next node of the new node must be the current head node
        //after that the new node will be the first node and the head node will point to it.
        //then we increment the list's length by one since a new node has been added.
        void prepend_node(int value){
            Node* new_node = new Node(value);
            if (!this->is_list_empty()){
                new_node->next = this->head;
                this->head = new_node;
            }else{
                this->head = new_node;
                this->tail = new_node;
            }
            this->length++;
        }

        //first it will check if the list is empty or not, if it's empty it will show a message
        //if it's not it will check the list's length, if it's equal to 1 that means there is only one node in the list
        //it will make a temp node and equals it to the head node which is the only node in the list
        //then it will delete the temp node and since now the list is empty both head and tail node will point to the nullptr
        //if the list is not empty and the length is not equal to the 1 that means there are more than one nodes in the list.
        //it makes a temp node and equals it to the tail node which is the last node.
        //now we need to find the node before the last node which is going to be the new last node after the last node is deleted.
        //we call it previous node, the next node of the previous node should be nullptr since it's the new last node.
        //and then tail node will point to that previous node as last node.
        //after that we delete the temp value which was the old last node.
        //and decrement the list's length value by one since a node is deleted.
        void delete_last_node(){
            if (!this->is_list_empty()){
                if (this->length == 1){
                    Node* temp = this->head;
                    this->head = nullptr;
                    this->tail = nullptr;
                    delete temp;
                }else{
                    Node* temp = this->tail;
                    Node* previous_node = this->get_node(this->length - 2);
                    previous_node->next = nullptr;
                    this->tail = previous_node;
                    delete temp;
                }
                this->length--;
            }
        }

        //first it will check if the list is empty or not, if it's empty it will show a message
        //if it's not it will check the list's length, if it's equal to 1 that means there is only one node in the list
        //it will make a temp node and equals it to the head node which is the only node in the list
        //then it will delete the temp node and since now the list is empty both head and tail node will point to the nullptr
        //if the list is not empty and the length is not equal to the 1 that means there are more than one nodes in the list.
        //it makes a temp node and equals it to the head node which is the first node.
        //then we make the node after the current first node as the new first node since the current first node is going to be deleted
        //and decrement the list's length value by one since a node is deleted.
        void delete_first_node(){
            if (!this->is_list_empty()){
                if (this->length == 1){
                    Node* temp = this->head;
                    this->head = nullptr;
                    this->tail = nullptr;
                    delete temp;
                }else{
                    Node* temp = this->head;
                    this->head = this->head->next;
                    delete temp;
                }
                this->length--;
            }
        }

        //it will take two values index and value.
        //first it check the index, index must be bigger than zero and in this case just not be bigger than index.
        //if the index is equal to 0 it's same as prepending a node and if the index is equal to the list's length it's same as appending a node
        //otherwise it meas the new node is going to be inserted somewhere in between.
        //so we make a new node with that value provieded
        //then we get the previous node of that place that the new node is going to be inserted.
        //the new node is going to be inserted between the previous node and the node after the prevous node
        //so the new nodes next node will be set to the next node of the previous node
        //then the previous node next node will be the new node
        //this way the new node will be inserted between previous node of that node in that index and the node in that index.
        //then we increment the list's length by one since a node has been inserted
        void insert_node(int index, int value){
            if (index < 0 || index > this->length){
                if(index == 0){
                    this->prepend_node(value);
                }else if (index == this->length){
                    this->append_node(value);
                }else{
                    Node* new_node = new Node(value);
                    Node* previous = this->get_node(index - 1);
                    new_node->next = previous->next;
                    previous->next = new_node;
                    this->length++;
                }
            }
        }
        //it will take an int as the index of the node that is going to be deleted
        //then it will check if the list is empty or not, if it's it will show a message, if it's not
        //it will check to see if the index is valid or not.
        //if the index be valid then it checks the index, if it's equal to 0 it's same as deleting the first node
        //if it's equal to list's length - 1 it same as deleting the last index
        //otherwise that means the node that is going to be deleting is somewhere in the middle.
        //it will make two Nodes, a temp node which is the node that is going to be deleting and previous node which is the node 
        //before the node we want to delete, in other words we are going to take the node that is between the node before the node we want to remove 
        //and the node after the node we want to remove.
        //so the previous node next node will be the next node of the node we want to remove.
        //and then we decrement the list's length since a node got removed.
        void delete_node(int index){
            if (this->is_list_empty()){
                cout << "There are no Nodes in the list" << endl;
            }else if (index < 0 && index >= this->length){
                cout << "Invalid index" << endl;
            }else if (index == 0){
                this->delete_first_node();
            }else if (index == this->length - 1){
                this->delete_last_node();
            }else {
                Node* temp = this->get_node(index);
                Node* previous = this->get_node(index - 1);
                previous->next = temp->next;
                cout << "The Node with the value of " << temp->value << " Has been removed at the index " << index << endl;
                delete temp;
                this->length--;
            }
        }

        //it will take two value index and value.
        //first it will check if the list is empty or not, if it's then it will show a message.
        //if it's not it will check the index, it must be bigger than 0 and smalled than the list's length
        //after validating the index it will make temp node and equals it to the node at index provided.
        //then it will set its value to the value provided.
        //this way the value of a node will be changed.
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

        //it will purge the entire list
        //it will delete the first node at each iteration
        void purge_list(){
            for (int i = 0 ; i < this->length ; i++){
                this->delete_first_node();
            }
            cout << "List has been purged" << endl;
        }

        //first it will check if the list is empty or not, if it's empty it will show a message
        //if it's not it will check if the length is equal to 1 or not, if it is, that means there is only one element in the list
        //if it's not it will make two nodes, first node and second node.
        //while the second node is not equal to nullptr, it will check if the first node is bigger than the second node or not
        //if it's that means the list is not sorted.
        void is_list_sorted(){
            if (this->is_list_empty()){
                cout << "There are no Nodes in the list" << endl;
            }else if (this->length == 1){
                cout << "There is only one element" << endl;
            }else {
                Node* first_node = this->head;
                Node* second_node = this->head->next;
                int flag = 1;
                while (second_node != nullptr){
                    if (first_node->value > second_node->value){
                        flag = 0;
                        break;
                    }else{
                        first_node = second_node;
                        second_node = second_node->next;
                    }
                }
                if (flag) {
                    cout << "The list is sorted" << endl;
                }else{
                    cout << "The list is not sorted" << endl;
                }
            }
        }

        //this is the implementation of bubble sort algorithm on the nodes
        void bubble_sort_the_list(){
            for (int i = 1 ; i <= this->length - 1; i++){
                for (int j = 0 ; j < this->length - i; j++){
                    if (this->get_node(j)->value > this->get_node(j+1)->value){
                        this->swap_nodes_value(j, j+1);
                    }
                }
            }
            cout << "Bubble sort finished" << endl;
        }

        //separate method for swapping node's value
        void swap_nodes_value(int a, int b){
            int temp = this->get_node(a)->value;
            this->get_node(a)->value = this->get_node(b)->value;
            this->get_node(b)->value = temp;
        }

        //merges two linked list, by appending nodes from the second list to the end of the first list.
        void merge(LinkedList* secondList){
            Node* temp = secondList->head;
            while (temp != nullptr){
                this->append_node(temp->value);
                temp = temp->next;
            }
            cout << "Done " << endl;
        }

        //merges two linked list, by pointers.
        void merge_by_address(LinkedList* secondList){
            this->tail->next = secondList->head;
            this->tail = secondList->tail;
        }

        void reverse_copy_to_mewList(LinkedList* secondList){
            Node* temp = this->head;
            while(temp != nullptr){
                Node* new_node = new Node(temp->value);
                new_node->next = secondList->head;
                secondList->head = new_node;
                secondList->length++;
                temp = temp->next;
            }
        }

        void reverse_the_list(){
            Node* temp = this->head;
            this->head = this->tail;
            this->tail = temp;
            Node* after = temp->next;
            Node* before = nullptr;
            for (int i = 0 ; i < length ; i++){
                after = temp->next;
                temp->next = before;
                before = temp;
                temp = after;
            }
        }

        void print_list_elements_recursive(Node* temp){
            if (temp != nullptr){
                cout << temp->value << " ";
                this->print_list_elements_recursive(temp->next);
            }
        }

        void print_list_element_recurisve_reverse(Node* temp){
            if (temp != nullptr){
                this->print_list_element_recurisve_reverse(temp->next);
                cout << temp->value << " ";
            }
        }

        bool check_contains(int value){
            if (this->is_list_empty()){
                return false;
            }else{
                Node* temp = this->head;
                while(temp != nullptr){
                    if (temp->value == value){
                        return true;
                    }else{
                        temp = temp->next;
                    }
                }
            }
            return false;
        }
    
};

int main(){
    LinkedList* list1 = new LinkedList();
    LinkedList* list2 = new LinkedList();
    list1->append_node(1);
    list1->append_node(2);
    list1->append_node(3);
    list1->append_node(4);
    list2->append_node(5);
    list2->append_node(6);
    list2->append_node(7);
    list2->append_node(8);
    list1->print_list_elements();
    list2->print_list_elements();
    list1->merge_by_address(list2);
    list1->print_list_elements();
}

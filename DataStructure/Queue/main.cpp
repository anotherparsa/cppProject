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

class Queue{
    private:
        Node* first;
        Node* last;
        int length;

    public:

        Queue(){
            this->first = nullptr;
            this->last = nullptr;
            this->length = 0;
        }

        bool is_queue_empty(){
            return (this->length == 0);
        }

        void print_queue(){
            Node* temp = this->first;
            while(temp != nullptr){
                cout << temp->value << " " ;
                temp = temp->next;
            }
            cout << endl;
        }

        void Enqueue(int value){
            Node* new_node = new Node(value);
            if (this->is_queue_empty()){
                this->first = new_node;
                this->last = new_node;
            }else{
                last->next = new_node;
                this->last = new_node;
            }
            this->length++;
        }

};

int main(){
    Queue* MyQueue = new Queue();
    MyQueue->Enqueue(1);
    MyQueue->Enqueue(10);
    MyQueue->Enqueue(22);
    MyQueue->Enqueue(123);
    MyQueue->print_queue();

}
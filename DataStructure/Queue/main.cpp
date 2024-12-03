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

        int Dequeue(){
            if (this->length == 0){
                return 11111;
            }else{
                Node* temp = this->first;
                int DeQueuedValue = first->value;
                if (length == 1){
                    this->first = nullptr;
                    this->last = nullptr;
                }else{
                    this->first = first->next;
                }
                delete temp;
                this->length--;
                return DeQueuedValue;
            }
        }

};

int main(){
    Queue* MyQueue = new Queue();
    MyQueue->Enqueue(1);
    MyQueue->Enqueue(10);
    MyQueue->Enqueue(22);
    MyQueue->Enqueue(123);
    MyQueue->print_queue();
    cout << MyQueue->Dequeue() << endl;
    cout << MyQueue->Dequeue() << endl;

}
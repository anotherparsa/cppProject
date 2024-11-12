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

class Stack{
    private:
        Node* top;
        int height;
    
    public:
        Stack(int maxSize){
            this->top = nullptr;
            this->height = 0;
        }

        bool isEmpty(){
            return (this->height == 0); 
        }

        void printStack(){
            if (this->isEmpty()){
                cout << "Stack is empty" << endl;
            }else{
                Node* temp = this->top;
                while (temp){
                    cout << temp->value << endl;
                    temp = temp->next;
                }
            }
        }

        void push_node(int value){
            Node* newNode = new Node(value);
            newNode->next = top;
            top = newNode;
            height++;
        }

        int pop_node(){
            if (height == 0){
                return INT8_MIN;
            }else{
            Node* temp = this->top;
            top = top->next;
            int popped_value = temp->value;
            delete temp;
            this->height--;
            return popped_value;


            }
        }

};

int main(){
    Stack* myStack = new Stack(10);
    myStack->printStack();
    myStack->push_node(1);
    myStack->push_node(2);
    myStack->push_node(3);
    myStack->push_node(4);
    myStack->printStack();
    cout << myStack->pop_node() << endl; 
    cout << myStack->pop_node() << endl; 
    myStack->printStack();

}
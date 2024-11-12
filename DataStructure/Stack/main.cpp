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
};

int main(){
    Stack* myStack = new Stack(10);
    myStack->printStack();
}
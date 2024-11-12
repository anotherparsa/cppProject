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
        int top;
        int maxSize;
    
    public:
        Stack(int maxSize){
            this->top = -1;
            this->maxSize = maxSize;
        }

};
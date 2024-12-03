#include <iostream>

using namespace std;

class Node{
    public:
        int value;
        Node* next;
        Node(int vlaue){
            this->value;
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
};
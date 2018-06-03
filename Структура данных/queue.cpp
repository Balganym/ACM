#include <iostream>
using namespace std;

class Node{
public:
    int value;
    Node *next;
    Node (int value){
        this->value=value;
    }
};

class Queue{
    public:
        Node *top;
        Node *end;
        
        Queue(){
            top = NULL;
            end = NULL;   
        }
        
        void push(int value){
            Node *node = new Node(value);
            if(top == NULL){
                top = node;
                end = node;
            }else {
                end -> next = node;
                end = node;
            }
        }
    
        void pop(){
            if(top != NULL)
                top = top -> next;
            if(top == NULL)
                end = NULL;
        }
};

int main(){
    
    Queue *q = new Queue();
    q->push(5);
    q->push(6);
    q->pop();
    cout<<q->top->value;
    cout<<q->end->value;
    
    return 0;
    
}



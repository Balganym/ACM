#include <iostream>
using namespace std;

int sz = 0;
class Node{
public:
    int value;
    Node *next;
    Node(int value){
        this->value = value;
    }
};

class Stack{
public:
    Node *top;
    Stack(){
        top= NULL;
    }
    
    int back(){
        //if(top!=NULL) ///?????
        return top -> value;
    }
    
    void push(int value){
        Node *node = new Node(value);
        node->next = top;
        top = node;
        sz++;
    }
    
    void pop(){
        cout<<(top->value)<<endl;
        top = top->next;
        sz--;
    }
    
    
    bool is_empty(){
        return top==NULL;
    }
    
    int size(){
        return sz;
    }
    
    string clear(){
        top = NULL;
        sz = 0;
        return "ok";
    }
};

int main(){
    
    Stack *st = new Stack();
    st->push(4);
    st->push(3);
    st->push(4);
    cout<<st->back();
    
    cout<< st->top->value;
    
    return 0;
}

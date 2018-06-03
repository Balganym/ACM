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
            }
            else {
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


/*
#include<iostream>
#include<queue>
#include<stack>
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
        }
        else {
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
    
    bool empty(){
        
        return (top = NULL);
        
    }
    
};


int main(){
    
    Queue *f = new Queue();
    Queue *s = new Queue();
    
    
    int n, cnt, x, y;
    cnt = 0;
    for(int i=0; i<5; i++){
        cin>>n;
        f->push(n);
    }
    
    
    for(int i=0; i<5; i++){
        cin>>n;
        s->push(n);
    }
    
    
    while(!f->empty()&&!s->empty()){
        x=f->top -> value;
        f->pop();
        y=s->top->value;
        s->pop();
        cnt++;
        
        if (x == 0 && y == 9) {
            f->push(x);
            f->push(y);
            continue;
        }
        if (x == 9 && y == 0) {
            s->push(x);
            s->push(y);
            continue;
        }
        if (x > y) {
            f->push(x);
            f->push(y);
        } else {
            s->push(x);
            s->push(y);
        }
    }
    if (f->empty())
        cout << "second" << " ";
    else
        cout << "first" << " ";
    cout << cnt;
    
    return 0;
}*/
#include <iostream>

using namespace std;

class Node{
public:
    int value;
    Node *next, *prev;
    Node(char value){
        this->value = value;
    }
};

class List{

public:
    
    Node *front, *back;
    
    List(){
        front= NULL;
        back = NULL;
    }
    void push_back(int value){
        
        Node *node = new Node(value);
        if(back == NULL){
            front = node;
            back = node;
        }else{
            node->prev = back;
            back->next = node;
            back = node;
        }
    }
    
    void push_front(int value){
        Node *node = new Node(value);
        if(front == NULL){
            front = node;
            back = node;
        }else{
            front->prev = node;
            node->next = front;
            front = node;
        }
    }
    
    void pop_back(){
        if(back == NULL)
            return;
        else{
            back = back->prev;
            if(back == NULL)
                front = NULL;
        }
    }
    void pop_front(){
        if(front == NULL)
            return;
        else{
            front = front->next;
            if(front == NULL)
                back = NULL;
        }
    }
    
    bool empty(){
        return (back == NULL);
    }
    
    void del(Node *node){
        if(node == back)
            pop_back();
        else if(node == front)
            pop_front();
        else{
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }
    }
    
    void add(Node *node, int value){
        if(node == back)
            push_back(node->value);
        
        else{
            Node *node1 = new Node(value);
            node->next->prev = node1;
            node1->next = node->next;
            node->next = node1;
            node1->prev = node;
        }
    }
    
    Node *find(int value){
        Node *node = front;
        while(node!=NULL && node->value != value){
            node = node->next;
        }
        return node;
    }
    
    void print(){
        Node *node = front;
        while(node!=NULL){
            cout<<node->value<<" ";
            node = node->next;
        }
        cout<<endl;
    }
};

int main() {

    List *l = new List();
    
    l->push_back(5);
    l->push_back(6);
    l->push_front(0);
    l->push_back(19);
    l->push_back(45);
    l->push_front(23);
    l->print();
    cout<<l->front->value<<endl;
    cout<<l->back->value<<endl;
    l->find(0);
    l->add(l->find(6), 34);
    l->print();
    
    return 0;
}


#ifndef _deque_ptr_hpp
#define _deque_ptr_hpp

#include <iostream>
class deque{
    
    //int* arr;
    //int capacity;
private:
    struct Node
    {
        Node* next, *prev;
        int data;
    };
    Node* back;
    Node* top;
    int size;
    int max_size;
    int * nop;

public:
    deque();
    ~deque();
    void set_nop(int* nop);
    int* get_nop();
    int pop_top();
    int pop_down();
    int peek();
    void push_top(int x);
    void push_down(int x);
    bool isEmpty();
    int get_size();
    int get_data(int index);
    void print_all();
};

deque::deque(): size{0} {
    top = nullptr;
    back = nullptr;
    nop = new int;
}

deque::~deque(){
    if (!isEmpty())
    {
        Node* current = back;
        Node* temp;
        while (current != nullptr){
            temp = current;
            current = current->next;
            delete temp;
        }
    }
}
void deque::set_nop(int* nop){
    this->nop = nop;
}
int* deque::get_nop(){
    return nop;
}

int deque::get_size(){
    return size;
}

bool deque::isEmpty(){
    return top == nullptr;
}

void deque::push_top(int x){
    Node *newNode = new Node();
    *nop +=1;
    if (size == 0) {
        *nop +=1;
        newNode -> data = x;
        newNode -> prev = nullptr;
        back = newNode;
        *nop += 3;
    }
    else{
        newNode -> data = x;
        newNode->prev = top;
        top -> next = newNode;
        *nop +=4;
    }
    newNode -> next = nullptr;
    top = newNode;
    size++;
    *nop += 3;
}
void deque::push_down(int x){
    Node *newNode = new Node();
    *nop +=1;
    if (size == 0) {
        newNode -> data = x;
        newNode -> next = nullptr;
        top = newNode;
        *nop +=4;
    }
    else{
        newNode -> data = x;
        newNode -> next =  back;
        newNode -> next -> prev = newNode;
        *nop +=4;
    }
    newNode -> prev = nullptr;
    back = newNode;
    size++;
    *nop +=3;
}

int deque::pop_top(){
    int data;
    if (isEmpty())
        {
            std::cout << "Underflow\nProgram Terminated\n";
            exit(EXIT_FAILURE);
        }
    else{
        Node *temp = top;
        *nop+=1;
        if (top->prev != nullptr){
            top -> prev -> next = nullptr;
            top = temp->prev;
            data =temp -> data;
            delete temp;
            size--;
            *nop +=5;
        }
        else{
            data = top ->data;
            top->data = NULL;
            top = nullptr;
            back = nullptr;
            size--;
            *nop +=5;
        }
        *nop+=1;
    }
    *nop+=1;
    return data;
}

void deque::print_all(){
    if (isEmpty())
        {
            std::cout << "Underflow\nProgram Terminated\n";
            exit(EXIT_FAILURE);
        }
    else{
        Node* current = back;
        *nop+=1;
        while (current != nullptr) {
            std:: cout << current-> data;
            current = current->next;
            *nop+=2;
        }
        *nop+=1;
        std::cout << std::endl;
    }
    *nop+=1;
}

int deque::pop_down(){
    int data;
    if (isEmpty())
        {
            std::cout << "Underflow\nProgram Terminated\n";
            //exit(EXIT_FAILURE);
        }
    else{
        Node *temp = back;
        if (back -> next != nullptr){
            back -> next -> prev = nullptr;
            back = temp->next;
            data = temp -> data;
            delete temp;
            size--;
            *nop+=5;
        }
        else {
            data = back -> data;
            back->data = NULL;
            back = nullptr;
            top = nullptr;
            size--;
            *nop+=5;
        }
        *nop+=1;
    }
    nop+=1;
    return data;
}

#endif /* deque_hpp */


#ifndef adapteur_f_deque_hpp
#define adapteur_f_deque_hpp

#include "_deque_ptr.h"

class adapteur_deque_ptr{
private:
    deque* deque;
    int * nop;

public:
    adapteur_deque_ptr();
    ~adapteur_deque_ptr();
    void set_nop(int* nop);
    int* get_nop();
    int size();
    void push_top(int x);
    void push_down(int x);
    void pop_top();
    void pop_down();
    bool is_empty();
    int getElement(int index);
    bool setElement(int index, int element);
    void display();
};

adapteur_deque_ptr::adapteur_deque_ptr():
deque { new class deque() } {;}

void adapteur_deque_ptr:: set_nop(int *nop)
{
    this->nop = nop;
    deque->set_nop(nop);
}

int* adapteur_deque_ptr:: get_nop()
{
    return nop;
}

int adapteur_deque_ptr:: size()
{
    return deque->get_size();
}

bool adapteur_deque_ptr::is_empty(){
    return deque -> isEmpty();
}

int adapteur_deque_ptr::getElement(int index){
    int size = deque->get_size();
    *nop+=1;
    *nop+=3;
    if ((index >= 0) and (index < size)){
        *nop+=2;
        if (index > size / 2){
            class deque* tmp = new class deque();
            *nop+=1;
            int element;
            for (int i = 0; i <= size - index -1 ; i++) {
                element = deque->pop_top();
                tmp->push_top(element);
                *nop+=3;
            }
            *nop+=4;
            for (int i = 0; i <= size - index - 1; i++) {
                deque->push_top(tmp->pop_top());
                *nop+=1;
            }
            *nop+=4;
            delete tmp;
            return element;
        }
        else {
            class deque* tmp = new class deque();
            *nop+=1;
            int element;
            for (int i = 0; i <= index; i++) {
                *nop+=2;
                element = deque->pop_down();
                tmp->push_top(element);
                *nop+=3;
            }
            *nop+=2;
            for (int i = 0; i <= index; i++) {
                *nop+=2;
                deque->push_down(tmp->pop_top());
                *nop+=2;
            }
            *nop+=2;
            delete tmp;
            return element;
        }
    }
    else {
        std::cout << "Error int getElement(int ind)";
    }
    return -1;
}

bool adapteur_deque_ptr::setElement(int index, int element){
    int size = deque->get_size();
    *nop+=1;
    *nop+=3;
    if ((index >= 0) and (index < size)) {
        class deque* tmpSt1 = new class deque();
        *nop+=1;
        *nop+=2;
        if (index > size / 2 ){
            for (int i = 0; i < size - index - 1; i++){
                *nop+=4;
                tmpSt1->push_top(deque->pop_top());
                *nop+=2;
            }
            *nop+=4;
            tmpSt1->push_top(element);
            *nop+=1;
            int del_element= deque->pop_top();
            *nop+=1;
            *nop+=3;
            for (int i = size - index; i < size; i++){
                *nop+=3;
                tmpSt1->push_top(deque->pop_top());
                *nop+=2;
            }
            delete(deque);
            class deque* tmpSt2 = new class deque();
            *nop+=1;
            *nop+=2;
            for (int i = 0; i < size; i++){
                *nop+=2;
                tmpSt2->push_top(tmpSt1->pop_top());
                *nop+=2;
            }
            delete(tmpSt1);
            deque = tmpSt2;
            *nop+=1;
            return true;
        }
        else{
            for (int i = 0; i < index; i++) {
                *nop+=2;
                tmpSt1->push_down(deque->pop_down());
                *nop+=2;
            }
            *nop+=2;
            tmpSt1->push_down(element);
            int del_element= deque->pop_down();
            *nop+=3;
            for (int i = index+1; i < size; i++) {
                *nop+=3;
                tmpSt1->push_down(deque->pop_down());
                *nop+=2;
            }
            *nop+=3;
            delete(deque);
            class deque* tmpSt2 = new class deque();
            *nop+=1;
            for (int i = 0; i < size; i++){
                *nop+=2;
                tmpSt2->push_down(tmpSt1->pop_down());
                *nop+=2;
            }
            *nop+=2;
            delete(tmpSt1);
            deque = tmpSt2;
            *nop+=1;
            return true;
        }
    }
    else {
        std::cout << " Error setElement(int ind, int element)" << std::endl;
    }
    return false;
}

void adapteur_deque_ptr::push_top(int x){
    deque->push_top(x);
    *nop+=1;
}

void adapteur_deque_ptr::push_down(int x){
    deque->push_down(x);
    *nop+=1;
}

void adapteur_deque_ptr::pop_top(){
    deque->pop_top();
    *nop+=1;
}
void adapteur_deque_ptr::pop_down(){
    deque->pop_down();
    *nop+=1;
}
void adapteur_deque_ptr::display(){
    class deque* tmpSt1 = new class deque();
    *nop+=1;
    int size = deque->get_size();
    *nop+=1;
    for (int i = 0; i < size; i++){
        *nop+=2;
        int element = deque->pop_down();
        std::cout << " " << element;
        tmpSt1->push_down(element);
        *nop+=3;
    }
    *nop+=2;
    std::cout << std::endl;
    delete(deque);
    class deque* tmpSt2 = new class deque();
    *nop+=1;
    for (int i = 0; i < size; i++){
        *nop+=2;
        tmpSt2->push_down(tmpSt1->pop_down());
        *nop+=2;
    }
    *nop+=2;
    delete(tmpSt1);
    deque = tmpSt2;
    *nop+=1;
}

adapteur_deque_ptr::~adapteur_deque_ptr(){
    delete deque;
}

#endif /* adapteur_hpp */

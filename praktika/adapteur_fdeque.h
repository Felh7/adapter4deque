
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
            class deque* tmp = new class deque(); *nop+=1;
            tmp->set_nop(nop);
            int element;
            for (int i = 0; i <= size - index -1 ; i++) {
                element = deque->pop_top();
                tmp->push_top(element);
                *nop+=2;
            }
            for (int i = 0; i <= size - index - 1; i++) {
                deque->push_top(tmp->pop_top());
                *nop+=2;
            }
            delete tmp;
            return element;
        }
        else {
            class deque* tmp = new class deque(); *nop+=1;
            tmp->set_nop(nop);
            int element;
            for (int i = 0; i <= index; i++) {
                element = deque->pop_down();
                tmp->push_top(element);
                *nop+=2;
            }
            for (int i = 0; i <= index; i++) {
                deque->push_down(tmp->pop_top());
                *nop+=2;
            }
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
    int size = deque->get_size(); *nop+=1;
    *nop+=3;
    if ((index >= 0) and (index < size)) {
        class deque* tmpSt1 = new class deque(); *nop+=1;
        tmpSt1->set_nop(nop);
        *nop+=2;
        if (index > size / 2 ){
            for (int i = 0; i < size - index - 1; i++){
                tmpSt1->push_top(deque->pop_top());
                *nop+=2;
            }
            tmpSt1->push_top(element); *nop+=1;
            //int del_element= deque->pop_top(); *nop+=1;
            for (int i = size - index; i < size; i++){
                tmpSt1->push_top(deque->pop_top());
                *nop+=2;
            }
            delete(deque);
            class deque* tmpSt2 = new class deque(); *nop+=1;
            tmpSt2->set_nop(nop);
            for (int i = 0; i < size; i++){
                tmpSt2->push_top(tmpSt1->pop_top());
                *nop+=2;
            }
            delete(tmpSt1);
            deque = tmpSt2; *nop+=1;
            return true;
        }
        else{
            for (int i = 0; i < index; i++) {
                tmpSt1->push_down(deque->pop_down());
                *nop+=2;
            }
            tmpSt1->push_down(element); *nop+=1;
            //int del_element= deque->pop_down(); *nop+=1;
            for (int i = index+1; i < size; i++) {
                tmpSt1->push_down(deque->pop_down());
                *nop+=2;
            }
            delete(deque);
            class deque* tmpSt2 = new class deque();  *nop+=1;
            tmpSt2->set_nop(nop);
            for (int i = 0; i < size; i++){
                tmpSt2->push_down(tmpSt1->pop_down());
                *nop+=2;
            }
            delete(tmpSt1);
            deque = tmpSt2; *nop+=1;
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
}

void adapteur_deque_ptr::push_down(int x){
    deque->push_down(x);
}

void adapteur_deque_ptr::pop_top(){
    deque->pop_top();
}
void adapteur_deque_ptr::pop_down(){
    deque->pop_down();
}
void adapteur_deque_ptr::display(){
    class deque* tmpSt1 = new class deque(); *nop+=1;
    tmpSt1->set_nop(nop);
    int size = deque->get_size(); *nop+=1;
    for (int i = 0; i < size; i++){
        int element = deque->pop_down();
        std::cout << " " << element;
        tmpSt1->push_down(element);
        *nop+=4;
    }
    std::cout << std::endl;
    delete(deque);
    class deque* tmpSt2 = new class deque(); *nop+=1;
    tmpSt2->set_nop(nop);
    for (int i = 0; i < size; i++){
        tmpSt2->push_down(tmpSt1->pop_down());
        *nop+=2;
    }
    delete(tmpSt1);
    deque = tmpSt2;
    *nop+=1;
}

adapteur_deque_ptr::~adapteur_deque_ptr(){
    delete deque;
}

#endif /* adapteur_hpp */

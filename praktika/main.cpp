#pragma once

#include <iostream>
#include "_deque_ptr.h"
#include "adapteur_fdeque.h"
#include "Merge_sort.h"
#include<ctime>

void example_metods() {
    int n = 10;  //количество элементов в деке
    adapteur_deque_ptr deque;
    //заполнение дека
    for(int i=0;i<n;i++){
        //добавление элемента в начало начало дека
        deque.push_down(rand() % 100);
    }
    std::cout << "заполненный дек"<< std::endl;
    deque.display();
    //добавление элемента в конец дека
    deque.push_top(12);
    std::cout << "добавление элемента в конец дека"<< std::endl;
    deque.display();
    //удаление элемента с конца дека
    deque.pop_top();
    std::cout << "удаление элемента с конца дека"<< std::endl;
    deque.display();
    //удаление элемента с начала дека
    deque.pop_down();
    std::cout << "удаление элемента с начала дека"<< std::endl;
    deque.display();
}
void example_sort() {
    int n = 10;  //количество элементов в деке
    adapteur_deque_ptr deque;
    long long * nop = new long long;
    *nop = 0;
    //заполнение дека
    for(int i=0;i<n;i++){
        deque.push_down(rand() % 100);
    }
    std::cout << "заполненный дек"<< std::endl;
    deque.display();
    //сортировка
    MergeSort(deque, 0, n-1, nop);
    std::cout << "отсортированный дек"<< std::endl;
    deque.display();
}

void sorting(int n){
    long long * nop = new long long;
    *nop = 0;
    adapteur_deque_ptr *deque = new adapteur_deque_ptr();
    deque->set_nop(nop);
    //заполнение дека
    for(int i=0;i<n;i++){
        deque->push_down(rand() % 100);
    }
    const clock_t begin_time = clock();
    MergeSort(*deque, 0, n-1, nop);
    std::cout << float(clock() - begin_time) / CLOCKS_PER_SEC << std::endl;
    std::cout << "NOP: " << *deque->get_nop() << std::endl;
}
int main() {
    //example_metods();
   // example_sort();
    std::vector vect = {100, 300, 500, 800, 1000, 1500, 2000, 2500, 3000, 3500 };
    //int n = 2;
    for (int i=0;i<vect.size();i++){
        std:: cout << "num of operations: " << vect[i]<<std::endl;
        sorting(vect[i]);
    }
   // sorting(n);
}

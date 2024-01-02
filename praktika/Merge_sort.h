#pragma once

#include "adapteur_fdeque.h"

void merge(adapteur_deque_ptr& array, int const left, int const mid, int const right, long long * nop){ // 3+ 1+1+ n( 7 + 2+2*(13n)) + n(7+ 2+2*(13n) + 1)
    int i = left;
    int j = mid+1;
    *nop+=3; // 3
    
    adapteur_deque_ptr *temp = new adapteur_deque_ptr(); *nop+=1; // 1
    temp->set_nop(nop); *nop+=1; //1

    while (i <= mid &&  j <= right) { //n( 7 + 2+2*(13n - 13i))
        if (array.getElement(i) <= array.getElement(j)) {
            temp->push_down(array.getElement(i)); *nop+=2; // 7+ 2+2*(13n)
            ++i; *nop+=1; // 1
        }
        else {
            temp->push_down(array.getElement(j)); *nop+=2; // 7+ 2+2*(13n)
            ++j; *nop+=1; //1
        }
    }
    while (i <= mid) {
        temp->push_down(array.getElement(i)); *nop+=2; // 7+ 2+2*(13n)
        ++i; *nop+=1; //1
    }
    while (j <= right) {
        temp->push_down(array.getElement(j)); *nop+=2;// 7+ 2+2*(13n)
        ++j; *nop+=1;//1
    }
    for (int i = left; i <= right; ++i){ //n(7+ 2+2*(13n) + 1)
        array.setElement(i, temp->getElement(i - left)); // // 7+ 2+2*(13n) + 1
        *nop+=3;
    }
    delete temp;

}
void MergeSort(adapteur_deque_ptr& array, int left, int right, long long* nop ) {//3*log2(n)*(64n + 11 + 91 n^2)
 
    if (left < right) {
        int mid = (left + right) / 2; *nop+=3; // 3
        MergeSort(array, left, mid, nop); *nop+=1; //log2(n)
        MergeSort(array, mid + 1, right, nop); *nop+=2;
        merge(array, left, mid, right, nop); *nop+=1;//3+ 1+1+ n( 7 + 2+2*(13n)) + n(7+ 2+2*(13n) + 1)
    }
}

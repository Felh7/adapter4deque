#include <vector>
#include "adapteur_fdeque.h"

void merge(adapteur_deque_ptr& array, int const left, int const mid, int const right, long long * nop){
    int i = left;
    int j = mid+1;
    *nop+=3;
    
    adapteur_deque_ptr *temp = new adapteur_deque_ptr(); *nop+=1;
    temp->set_nop(nop); *nop+=1;

    while (i <= mid &&  j <= right) { *nop+=3;
        if (array.getElement(i) <= array.getElement(j)) {
            temp->push_down(array.getElement(i)); *nop+=2;
            ++i; *nop+=1;
        }
        else {
            temp->push_down(array.getElement(j)); *nop+=2;
            ++j; *nop+=1;
        }
    }
    while (i <= mid) {
        temp->push_down(array.getElement(i)); *nop+=2;
        ++i; *nop+=1;
    }
    while (j <= right) {
        temp->push_down(array.getElement(j)); *nop+=2;
        ++j; *nop+=1;
    }
    for (int i = left; i <= right; ++i){
        array.setElement(i, temp->getElement(i - left));
        *nop+=3;
    }
    delete temp;

}
void MergeSort(adapteur_deque_ptr& array, int left, int right, long long* nop ) {
    //int* nop = _nop;
    if (left < right) {
        int mid = (left + right) / 2; *nop+=3;
        MergeSort(array, left, mid, nop); *nop+=1;
        MergeSort(array, mid + 1, right, nop); *nop+=2;
        merge(array, left, mid, right, nop); *nop+=1;
    }
}

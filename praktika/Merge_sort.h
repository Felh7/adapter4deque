#include <vector>
#include "adapteur_fdeque.h"

void merge(adapteur_deque_ptr& array, int const left, int const mid, int const right, int * nop){
    int i = left;
    int j = mid+1;
    *nop+=3;
    
    std::vector<int>  temp;
    
    while (i <= mid &&  j <= right) {
        *nop+=3;
        if (array.getElement(i) <= array.getElement(j)) {
            temp.push_back(array.getElement(i));
            *nop+=3;
            ++i;
            *nop+=1;
        }
        else {
            temp.push_back(array.getElement(j));
            *nop+=3;
            ++j;
            *nop+=1;
        }
        *nop+=3;
    }
    *nop+=3;
    while (i <= mid) {
        *nop+=1;
        temp.push_back(array.getElement(i));
        *nop+=3;
        ++i;
        *nop+=1;
    }
    *nop+=1;
    while (j <= right) {
        *nop+=1;
        temp.push_back(array.getElement(j));
        *nop+=3;
        ++j;
        *nop+=1;
    }
    *nop+=1;
    for (int i = left; i <= right; ++i){
        *nop+=2;
        array.setElement(i, temp[i - left]);
        *nop+=3;
    }
    *nop+=2;

}
void MergeSort(adapteur_deque_ptr& array, int left, int right, int* nop ) {
    nop+=2;
    if (left < right) {
        int mid = (left + right) / 2;
        *nop+=3;
        MergeSort(array, left, mid, nop);
        *nop+=1;
        MergeSort(array, mid + 1, right, nop);
        *nop+=2;
        merge(array, left, mid, right, nop);
        *nop+=1;
    }
}

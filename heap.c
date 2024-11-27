#include <stdio.h>
#include <stdlib.h>

void showVec(int *vec, int size);
void swap(int *a, int *b);
void heapify(int *vec, int size, int root);
void heapSort(int *vec, int size);

int main(){
    int vec[] = {8, 7, 9, 5, 4, 2, 3, 1, 6};
    int size = sizeof(vec)/sizeof(vec[0]);

    showVec(vec, size);
    heapSort(vec, size);
    showVec(vec, size);

    return EXIT_SUCCESS;
}

void heapify(int *vec, int size, int root){
    int greatest = root;
    int left = 2 * root + 1;
    int right= 2 * root + 2;

    if(left < size && vec[left] > vec[greatest]) greatest = left;
    if(right < size && vec[right] > vec[greatest]) greatest = right;

    if(greatest != root){ //if the greatest not is the root, call heapify
        swap(&vec[root], &vec[greatest]);
        heapify(vec, size, greatest);
    }
}

void heapSort(int *vec, int size){
    for(int i= size / 2 - 1; i >= 0; i--){ //build heap
        heapify(vec, size, i);
    }
 
    for(int i= size-1; i >= 1; i--){ //extract elements from heap
        swap(&vec[0], &vec[i]);
        heapify(vec, i, 0);
    }
}

void swap(int *a, int *b){
    int aux = *a;
    *a = *b;
    *b = aux;  
}

void showVec(int *vec, int size){
    for(int i=0; i < size; i++){
        printf("[%d] ",vec[i]);
    }
    printf("\n");
}
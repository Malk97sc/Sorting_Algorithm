#include <stdio.h>
#include <stdlib.h>

void showVec(int *vec, int size);
void quickSort(int *vec, int left, int right);
void swap(int *vec, int *a, int *b);

int main(){
    int vec[] = {8, 7, 9, 5, 4, 2, 3, 1, 6};
    int size = sizeof(vec)/sizeof(vec[0]);

    showVec(vec, size);
    quickSort(vec, 0, size-1);
    showVec(vec, size);

    return EXIT_SUCCESS;
}

void quickSort(int *vec, int left, int right){
    int piv = vec[(left+right) / 2];
    int i = left, j = right;

    while(i <= j){
        while(vec[i] < piv) i++;
        while(vec[j] > piv) j--;
        if(i <= j){
            swap(vec, &i, &j);
            i++;
            j--;
        }
    }

    if(left < j){
        quickSort(vec, left, j);
    }
    if(i < right){
        quickSort(vec, i, right);
    }
}

void swap(int *vec, int *a, int *b){
    int aux = vec[*a];
    vec[*a] = vec[*b];
    vec[*b] = aux;  
}

void showVec(int *vec, int size){
    for(int i=0; i < size; i++){
        printf("[%d] ",vec[i]);
    }
    printf("\n");
}
#include <stdio.h>
#include <stdlib.h>

void showVec(int *vec, int size);
void insertionSort(int *vec, int size);

int main(){
    int vec[] = {8, 7, 9, 5, 4, 2, 3, 1, 6};
    int size = sizeof(vec)/sizeof(vec[0]);

    showVec(vec, size);
    insertionSort(vec, size);
    showVec(vec, size);

    return EXIT_SUCCESS;
}

void insertionSort(int *vec, int size){
    int aux, j=0;

    for(int i=0; i < size; i++){
        aux = vec[i];
        j=i;
        while(j > 0 && aux < vec[j-1]){
            vec[j] = vec[j-1];
            j--;
        }
        vec[j] = aux;
    }
}


void showVec(int *vec, int size){
    for(int i=0; i < size; i++){
        printf("[%d] ",vec[i]);
    }
    printf("\n");
}
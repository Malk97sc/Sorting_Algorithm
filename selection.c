#include <stdio.h>
#include <stdlib.h>

void showVec(int *vec, int size);
void selectionSort(int *vec, int size);

int main(){
    int vec[] = {8, 7, 9, 5, 4, 2, 3, 1, 6};
    int size = sizeof(vec)/sizeof(vec[0]);

    showVec(vec, size);
    selectionSort(vec, size);
    showVec(vec, size);

    return EXIT_SUCCESS;
}

void selectionSort(int *vec, int size){
    int aux;

    for(int i=0; i < size; i++){
        for(int j= i+1; j < size; j++){
            if(vec[i] > vec[j]){
                aux = vec[i];
                vec[i] = vec[j];
                vec[j] = aux;
            }
        }
    }
}


void showVec(int *vec, int size){
    for(int i=0; i < size; i++){
        printf("[%d] ",vec[i]);
    }
    printf("\n");
}
#include <stdio.h>
#include <stdlib.h>

void showVec(int *vec, int size);
void bubbleSort(int *vec, int size);

int main(){
    int vec[] = {8, 7, 9, 5, 4, 2, 3, 1, 6};
    int size = sizeof(vec)/sizeof(vec[0]);

    showVec(vec, size);
    bubbleSort(vec, size);
    showVec(vec, size);

    return EXIT_SUCCESS;
}

void bubbleSort(int *vec, int size){
    int aux;

    for(int i=0; i < size-1; i++){ //the size-1, 'Cause the last position is ordenate
        for(int j=0; j < size-i-1; j++){
            if(vec[j] > vec[j+1]){
                aux = vec[j];
                vec[j] = vec[j+1];
                vec[j+1] = aux;
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
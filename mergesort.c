#include <stdio.h>
#include <stdlib.h>

void showVec(int *vec, int size);
void mergeSort(int *vec, int start, int end);
void merge(int *vec, int start, int middle ,int end);

int main(){
    int vec[] = {8, 7, 9, 5, 4, 2, 3, 1, 6};
    int size = sizeof(vec)/sizeof(vec[0]);

    showVec(vec, size);
    mergeSort(vec, 0, size-1);
    showVec(vec, size);

    return EXIT_SUCCESS;
}

void merge(int *vec, int start, int middle ,int end){
    int i, j, k;
    int index1 = middle - start +1, index2 = end - middle;
    int vecLeft[index1], vecRight[index2];

    for(i = 0; i < index1; i++){
        vecLeft[i] = vec[start + i];
    }

    for(j = 0; j < index2; j++){
        vecRight[j] = vec[middle + 1 + j];
    }
    i = j = 0;
    k = start;

    while(i < index1 && j < index2){
        if(vecLeft[i] <= vecRight[j]){
            vec[k] = vecLeft[i];
            i++;
        }else{
            vec[k] = vecRight[j];
            j++;
        }
        k++;
    }

    while(i < index1){
        vec[k] = vecLeft[i];
        i++;
        k++;
    }

    while(j < index2){
        vec[k] = vecRight[j];
        j++;
        k++;
    }
}

void mergeSort(int *vec, int start, int end){
    if(start < end){
        int middle = start + (end-start)/2;
        mergeSort(vec, start, middle);
        mergeSort(vec, middle+1, end);
        merge(vec, start, middle, end);
    }
}


void showVec(int *vec, int size){
    for(int i=0; i < size; i++){
        printf("[%d] ",vec[i]);
    }
    printf("\n");
}
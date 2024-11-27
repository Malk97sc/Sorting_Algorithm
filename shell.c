#include <stdio.h>
#include <stdlib.h>

void showVec(int *vec, int size);
void shellSort(int *vec, int size);

int main(){
    int vec[] = {8, 7, 9, 5, 4, 2, 3, 1, 6};
    int size = sizeof(vec)/sizeof(vec[0]);

    showVec(vec, size);
    shellSort(vec, size); 
    showVec(vec, size);

    return EXIT_SUCCESS;
}

void shellSort(int *vec, int size){
    int gap, i, j, temp;

    for(gap = size / 2; gap > 0; gap /= 2){
        for(i = gap; i < size; i++){ //insertion sort with the grap
            temp = vec[i];
            j = i;
            while(j >= gap && vec[j - gap] > temp){ //move the elements
                vec[j] = vec[j - gap];
                j -= gap;
            }
            vec[j] = temp;
        }
    }
}

void showVec(int *vec, int size){
    for(int i = 0; i < size; i++){
        printf("[%d] ", vec[i]);
    }
    printf("\n");
}

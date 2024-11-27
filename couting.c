#include <stdio.h>
#include <stdlib.h>

void showVec(int *vec, int size);
int searchMAX(int *vec, int size);
void countigSort(int *vec, int size);

int main(){
    int vec[] = {8, 7, 9, 5, 4, 2, 3, 1, 6};
    int size = sizeof(vec)/sizeof(vec[0]);

    showVec(vec, size);
    countigSort(vec, size);
    showVec(vec, size);

    return EXIT_SUCCESS;
}

void countigSort(int *vec, int size){
    int max = searchMAX(vec, size), num, index;
    int out[size], *count;

    count = (int*)calloc(size, sizeof(int)); //init in 0 all the array
    
    for(int i=0; i < size; i++){
        num = vec[i];
        count[num]++;
    }

    for(int i=1; i <= max; i++){
        count[i] += count[i-1];
    }

    for(int i=0; i < size; i++){
        num = vec[i];
        index = count[num]- 1;
        out[index] = num;
        count[num]--;
    }

    for(int i=0; i < size; i++){
        vec[i] = out[i];
    }
}

int searchMAX(int *vec, int size){
    int max = vec[0]; 
    for(int i=1; i < size; i++){
        if(vec[i] > max){
            max = vec[i];
        }
    }
    return max;
}

void showVec(int *vec, int size){
    for(int i=0; i < size; i++){
        printf("[%d] ",vec[i]);
    }
    printf("\n");
}
#include <stdio.h>
#include <stdlib.h>

void showVec(int *vec, int size);
int searchMAX(int *vec, int size);
void countigSort(int *vec, int size, int place);
void radixsort(int *vec, int size);

int main(){
    int vec[] = {8, 7, 9, 5, 4, 2, 3, 1, 6};
    int size = sizeof(vec)/sizeof(vec[0]);

    showVec(vec, size);
    radixsort(vec, size); // Cambié countigSort a radixsort
    showVec(vec, size);

    return EXIT_SUCCESS;
}

void radixsort(int *vec, int size){
    int place, max;

    max = searchMAX(vec, size);

    for(place = 1; max / place > 0; place *= 10) countigSort(vec, size, place); 
}

void countigSort(int *vec, int size, int place){
    int max = searchMAX(vec, size), num, index;
    int out[size], *count;

    count = (int*)calloc(10, sizeof(int));  //10 is a posible digits 0-9
    
    for(int i = 0; i < size; i++){
        num = (vec[i] / place) % 10; 
        count[num]++;
    }

    for(int i = 1; i < 10; i++) count[i] += count[i - 1];

    for(int i = size - 1; i >= 0; i--){
        num = (vec[i] / place) % 10;
        index = count[num] - 1;
        out[index] = vec[i];
        count[num]--;
    }

    for(int i = 0; i < size; i++)
        vec[i] = out[i];

    free(count); 
}

int searchMAX(int *vec, int size){
    int max = vec[0]; 
    for(int i = 1; i < size; i++){
        if(vec[i] > max){
            max = vec[i];
        }
    }
    return max;
}

void showVec(int *vec, int size){
    for(int i = 0; i < size; i++){
        printf("[%d] ", vec[i]);
    }
    printf("\n");
}

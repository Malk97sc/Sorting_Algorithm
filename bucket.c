#include <stdio.h>
#include <stdlib.h>

void showVec(float *vec, int size);
void bucketSort(float *vec, int size);
void insertionSort(float *vec, int size);
int getBucketIndex(float value, int size);

int main(){
    float vec[] = {0.42, 0.32, 0.23, 0.53, 0.51, 0.12, 0.89, 0.84};
    int size = sizeof(vec)/sizeof(vec[0]);

    showVec(vec, size);
    bucketSort(vec, size);
    showVec(vec, size);

    return EXIT_SUCCESS;
}

void bucketSort(float *vec, int size){
    int i, j, index;
    
    float **buckets = (float**)malloc(size * sizeof(float*));
    if (!buckets) { perror("Fail malloc\n"); return; }

    for(i = 0; i < size; i++){
        buckets[i] = (float*)malloc(size * sizeof(float)); //reserve memory
        if (!buckets[i]) { perror("Fail malloc\n"); return; }
    }


    for(i = 0; i < size; i++){
        for(j = 0; j < size; j++){
            buckets[i][j] = -1.0; //empty
        }
    }

    for(i = 0; i < size; i++){
        index = getBucketIndex(vec[i], size);
        int k = 0;
        while(buckets[index][k] != -1.0){ //search the first empty bucket
            k++;
        }
        buckets[index][k] = vec[i];
    }

    for(i = 0; i < size; i++){ //sorting all element by bucket
        int k = 0;
        while(buckets[i][k] != -1.0){
            k++;
        }
        if(k > 0){
            insertionSort(buckets[i], k); //sort the bucket
        }
    }

    int pos = 0;
    for(i = 0; i < size; i++){
        int k = 0;
        while(buckets[i][k] != -1.0){
            vec[pos] = buckets[i][k];
            pos++;
            k++;
        }
    }

    for(i = 0; i < size; i++){
        free(buckets[i]);
    }
    free(buckets);
}

void insertionSort(float *vec, int size){
    int i, j;
    float key;
    for(i = 1; i < size; i++){
        key = vec[i];
        j = i - 1;
        while(j >= 0 && vec[j] > key){
            vec[j + 1] = vec[j];
            j--;
        }
        vec[j + 1] = key;
    }
}

void showVec(float *vec, int size){
    for(int i = 0; i < size; i++){
        printf("[%.2f] ", vec[i]);
    }
    printf("\n");
}

int getBucketIndex(float value, int size){
    return (int)(value * size); 
}

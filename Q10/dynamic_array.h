#ifndef DYNAMIC_ARRAY
#define DYNAMIC_ARRAY
#include<stdlib.h>

static int size = 0;
static int maxSize = 2;

int* pushBack(int* arr, int val){

    if(size == 0){
        arr = (int*)malloc(sizeof(int)*2);
    }
    else if(size >= maxSize){
        maxSize = maxSize * 2;
        arr = (int*)realloc(arr, maxSize * sizeof(int));
    }
    arr[size] = val;
    size++;
    return arr;
}
int popBack(int* arr){

    if(size == 0){
        return 0;
    }
    size--;
    return arr[size];
}
int arrSize(int* arr){
    return size;
}
int popFront(int* arr){
    if(size == 0){
        return 0;
    }
    int temp = arr[0];
    for(int i = 1; i < size; i++){
        arr[i-1] = arr[i];
    }
    size--;
    return temp;
}

#endif




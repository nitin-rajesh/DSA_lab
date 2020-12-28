#include<stdio.h>
#include<stdlib.h>
#include"dynamic_array.h"

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void conformArr(int* q){
    for(int j = arrSize(q) - 1; j > 0; j--){
        for(int i = j; i > 0; i = i/2){
            if(q[i] > q[i/2])
                swap(&q[i], &q[i/2]);
        }
    }
}

int* insertMax(int* q, int val){
    q = pushBack(q,val);
    conformArr(q);
    return q;
}

void delMax(int* q){
    printf("%d removed\n", popFront(q));
    conformArr(q);
}

void display(int* q){
    for(int i = 0; i < arrSize(q); i++){
        printf("%d ", q[i]);
    }
    printf("\n");
}

int main(){
    int* priorityQueue = NULL;
    int k;
    char op;
    printf("Enter i. Insert\t p. Display \td.Delete \te. Exit \n");
    do{
        scanf("%c",&op);
        switch(op){
            case 'i': 
                    scanf("%d",&k);
                    priorityQueue = insertMax(priorityQueue, k);
                    break;
                    
            case 'p': display(priorityQueue);
                    break;
                   
            case 'd': 
                    delMax(priorityQueue);
                    break;
        }
    }while(op != 'e');
}
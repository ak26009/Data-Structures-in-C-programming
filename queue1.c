#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct queue{
  int front;
  int rear;
  int size;
  int *q;
};

struct queue que;

int overflow(){
    if(que.rear == que.size -1){
        return 1;
    }else{
        return 0;
    }
}

int underflow(){
    if(que.rear = -1 && que.front -1){
        return 1;
    }else{
        return 0;
    }
}

void enque(int n){
    if(overflow()){
        printf("queue overflow , cant add");
    }else{
        if(que.front == -1){
            que.front++;
            que.rear++;
            que.q[que.rear] = n;
        }
    }
}

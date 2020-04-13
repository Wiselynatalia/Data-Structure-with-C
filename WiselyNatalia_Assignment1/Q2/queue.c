/*
Queue.c
*/
#include <stdlib.h>
#include "queue.h"
#include <stdio.h>

struct queueCDT{
  queueElementT front;
  queueElementT tail; 
};

queueADT EmptyQueue(){
  queueADT queue;

  queue = (queueADT)malloc(sizeof(*queue));
  queue->front = 0;
  queue->tail = 0;
  
  return queue;
}

void Enqueue(queueADT queue, queueElementT element){
  if (queue->front == 0){
    queue->front = element;
  }
  else {
    queue->tail->next = element;
  }
  queue->tail = element;
}

queueElementT Dequeue(queueADT queue){
  queueElementT result;
  if (queue->front==0) { 
    printf("Queue is empty.\n"); exit(EXIT_FAILURE); 
  };
  result = queue->front;
  queue->front = queue->front->next;
  return result;
}

int QueueLength(queueADT queue) {
  int i = 0;
  queueElementT tmp = queue->front;
  while (tmp != 0){
    i += 1;
    tmp = tmp->next;
  } 
  return i;
}

int QueueIsEmpty(queueADT queue) {
  return (queue->front == 0);
}


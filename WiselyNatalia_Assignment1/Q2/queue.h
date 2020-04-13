/*
  Queue.h
*/
#include "customer.h"

typedef struct queueCDT *queueADT; 
typedef customerT queueElementT;
queueADT EmptyQueue(void);
void Enqueue(queueADT queue, queueElementT element); 
queueElementT Dequeue(queueADT queue);
int QueueLength(queueADT queue);
int QueueIsEmpty(queueADT queue);

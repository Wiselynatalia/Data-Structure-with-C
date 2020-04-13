#include <stdio.h>
#include <stdlib.h>
#include "queue.c"
#include "customer.c"
#include <math.h>

struct cashier{
    int numberOfCustomersServed;
    int totalCustomerWaitingTime;
    float totalAmountReceived;
    queueADT customerQ;
};
typedef struct cashier cashierT;

int main(){
    int time[4] = {0,0,0,0};
    customerT cus;
    cashierT cashier[4];
    for (int i=0; i<4; i++){
        cashier[i].numberOfCustomersServed = 0;
        cashier[i].totalCustomerWaitingTime = 0;
        cashier[i].totalAmountReceived = 0;
        cashier[i].customerQ = EmptyQueue();

    }
    FILE *fptr = fopen("supermarket.dat", "r");
    char str[15];
    int a; float b;
    int indx;
    while(!feof(fptr)){
        fgets(str, 15, fptr);
        sscanf(str, "%d %f", &a,&b);
        cus = NewCustomer(a,b);
        
        for(int i=0; i<4; i++){
            if(QueueLength(cashier[i].customerQ) != 0){
                time[i]+=1;
            }
        }

        int min = 999;
        for(int i=0; i<4; i++){
            if(QueueLength(cashier[i].customerQ) != 0){
                if (cashier[i].customerQ->front->checkoutTime == time[i]){
                    Dequeue(cashier[i].customerQ);
                    time[i]=0;
                }
            }
            int len =  QueueLength(cashier[i].customerQ);
            if (len < min){
                min = len;
                indx = i;
            }  
            
        }

        if (str[0] != '\n'){
            Enqueue(cashier[indx].customerQ, cus); 
            cashier[indx].numberOfCustomersServed++;
            cashier[indx].totalAmountReceived += cus->payment;
            cashier[indx].totalCustomerWaitingTime += cus->checkoutTime;
        }
    
    }
    float ttime=0.0 ; int no=0; float atime; 
    for(int i=0; i<4; i++){
      ttime+= cashier[i].totalCustomerWaitingTime;
      no += cashier[i].numberOfCustomersServed;  
    }
    atime = ttime/no;
    printf("Average time %d\n", (int)round(atime));
    for(int i=0; i<4; i++){
        printf("Ttl money cashier[%d]= %.1f\n", i, cashier[i].totalAmountReceived);
        printf("Ttl no of customer in cashier[%d]= %d\n", i, cashier[i].numberOfCustomersServed);
    }
    
    
}

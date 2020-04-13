#include <stdio.h>
#include <stdlib.h>

customerT NewCustomer(int checkoutTime, float payment){
  customerT customer;

  customer = (customerT)malloc(sizeof(*customer));
  customer->checkoutTime = checkoutTime;
  customer->payment = payment;
  customer->next = 0;
  
  return customer;
}
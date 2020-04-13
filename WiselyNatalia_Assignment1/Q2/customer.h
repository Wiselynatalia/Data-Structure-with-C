#include <stdlib.h>

typedef struct customer *customerT;

struct customer {
    int checkoutTime;
    float payment;
    customerT next;
};

customerT NewCustomer(int checkoutTime, float payment);
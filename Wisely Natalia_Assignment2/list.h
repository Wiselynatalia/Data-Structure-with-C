typedef struct listCDT *listADT;
typedef int listElementT;

// down here are the operations
listADT EmptyList(void);	// creates []
listADT Cons(listElementT, listADT);	// 4)
listElementT Head(listADT);		// returns the Head element
listADT Tail(listADT);	// return the tail list
int ListIsEmpty(listADT); // return 1 (empty) or 0 (not empty)


#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include "list.h" 
#include "symtab.h"

typedef struct cellT {
    char *key; 
    symtabEntryT value;
} cellT;

struct symtabCDT {
    cellT **bucket; // An array of cellT*, which can be extended.
    int nBuckets; // Current number of buckets (size of the bucket array) 
    int nEntries; // Current number of entries.
};

int Hash(char *s, int nBuckets) { // DO NOT MODIFY.
    unsigned long hashcode = 0;
    for (int i=0; s[i]!='\0'; i++) hashcode = (hashcode<<5) + s[i]; 
    return (int) (hashcode % nBuckets);
}

symtabADT EmptySymbolTable() { // DO NOT MODIFY. 
    symtabADT T1 = (symtabADT) malloc(sizeof(*T1));
    T1->bucket = (cellT**) malloc(5*sizeof(cellT**)); // Initial size is 5. 
    T1->nBuckets = 5; T1->nEntries = 0;
    for (int i = 0; i < T1->nBuckets; i++) T1->bucket[i]=(cellT*)NULL;
    return T1; 
}

void Enter(symtabADT T1, char* K1, symtabEntryT V1) { // You need to implement this.

    if (T1->nBuckets == T1->nEntries) {
        symtabADT F1 = EmptySymbolTable();
        F1->bucket = (cellT**) malloc((T1->nBuckets)*sizeof(cellT**));
        for (int i=0; i<T1->nBuckets; i++){
            F1->bucket[i] = T1->bucket[i];
        }
        T1->bucket = (cellT**)realloc(T1->bucket,((7+T1->nEntries)*sizeof(cellT**)));
        T1->nBuckets = T1->nBuckets +7;
        for (int i=0; i< T1->nBuckets; i++){
            T1->bucket[i] = (cellT*)NULL;
        }
        for (int i = 0; i < T1->nEntries; i++){
            int Hashcode = Hash(F1->bucket[i]->key, T1->nBuckets);
            while (T1->bucket[Hashcode] != NULL) {
                if (strcmp(T1->bucket[Hashcode]->key,K1)==0) {
                    break;
                }
                if (Hashcode == T1->nBuckets -1) {
                    Hashcode=0;
                }
                else {
                    Hashcode +=1;
                }
            }
            if (T1->bucket[Hashcode] == NULL) {
                T1->bucket[Hashcode] = (cellT*) malloc(sizeof(cellT*));
                T1->bucket[Hashcode]->key = (char*)malloc(sizeof(char)*(strlen(F1->bucket[i]->key)+1));
            }
            strcpy(T1->bucket[Hashcode]->key, F1->bucket[i]->key);
            T1->bucket[Hashcode]->value = F1->bucket[i]->value;
        }
        
    }
    int hashCode = Hash(K1, T1->nBuckets);
    while (T1->bucket[hashCode] != NULL) {
        if (strcmp(T1->bucket[hashCode]->key,K1)==0) {
            break;
        }
        if (hashCode == T1->nBuckets-1) {
            hashCode=0;
        }
        else {
            hashCode +=1;
        }
    }
    if (T1->bucket[hashCode] == NULL) {
        T1->nEntries = T1->nEntries +1;
        T1->bucket[hashCode] = (cellT*) malloc(sizeof(cellT*));
        T1->bucket[hashCode]->key = (char*)malloc(sizeof(char)*(strlen(K1)+1));
    }
    strcpy(T1->bucket[hashCode]->key, K1);
    T1->bucket[hashCode]->value = Cons(Head(V1), T1->bucket[hashCode]->value) ;

}

symtabEntryT Lookup(symtabADT T1, char* K1) { // You need to implement this.
    int hashcode = Hash(K1, T1->nBuckets);
    int x=0;
    if (T1->bucket[hashcode] == NULL) {
        return(EmptyList());
    }
    if (strcmp(T1->bucket[hashcode]->key, K1)==0) {
        return(T1->bucket[hashcode]->value);
    }
    
    while(T1->bucket[hashcode]!= NULL) {
        if (strcmp(T1->bucket[hashcode]->key, K1)==0) {
            return(T1->bucket[hashcode]->value);
        } 
        else if (hashcode == T1->nEntries-1) {
            hashcode = 0;
        }
        else {
            hashcode+=1;
        }
    }
    return(EmptyList());
}


void forEachEntryDo(symtabFnT f, symtabADT T1) { // DO NOT MODIFY. 
    for (int i = 0; i < T1->nBuckets; i++)
        if (T1->bucket[i] != NULL)
            f(T1->bucket[i]->key, T1->bucket[i]->value);
}

void printList(listADT L) { // DO NOT MODIFY. 
    if (ListIsEmpty(L))
        printf("nil"); 
    else {
        printf("%d:", Head(L)); 
        printList(Tail(L));
    }
}

void ShowAll(symtabADT T1){ // DO NOT MODIFY. 
    for (int i = 0; i < T1->nBuckets; i++)
        if (T1->bucket[i] != NULL) {
            printf("Bucket %d\t Key:%s\t Value ", i, T1->bucket[i]->key); 
            printList(T1->bucket[i]->value);
            printf("\n");
        } 
}
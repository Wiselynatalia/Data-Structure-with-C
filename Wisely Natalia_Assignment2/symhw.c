#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include "list.h" 
#include "symtab.h"
int Sum (symtabEntryT V1) {
    if (ListIsEmpty(V1)) {
        return (0);
    }
    return(Head(V1)+Sum(Tail(V1)));
}
void Final (char* K1, symtabEntryT V1) {
    printf("%20s\t", K1);
    printf(" %d\n", Sum(V1));

} 

int main (){
    symtabADT T1 = EmptySymbolTable();
    char str[100];
    FILE *fptr;
    fptr= fopen("data.txt", "r");
    int i =0;
    int x;
    while(!feof(fptr)){
        i+=1;
        if (i%2 !=0){
            fgets(str,100,fptr);
            strtok(str,"\n");
        }
        else if (i%2 ==0){
            fscanf(fptr,"%d\n", &x);
            Enter(T1, str, Cons(x,EmptyList()));
        }   
    }
    ShowAll(T1);
    printf("\n--------------FINAL OUTPUT--------------\n");
    forEachEntryDo(Final, T1);  


} 


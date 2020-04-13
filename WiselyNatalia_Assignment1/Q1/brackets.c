#include <stdio.h>
#include <stdlib.h>
#include "stack.c"
#include <string.h>
int main(){
    char input[50]; int flag;
    stackADT stack;
    stack = EmptyStack();
    printf("Please input the string of parenthesis:");
    scanf("%s", input);
    for (int i=0; i <strlen(input); i++){
        if (input[i] == '('){
            Push(stack,')');
            flag=0;
        } 
        else if (input[i] == '{'){
            Push(stack,'}');
            flag=0;
        } 
        else if (input[i] == '['){
            Push(stack,']');
            flag=0;
        } 
        else {
            if (input[i] == Pop(stack)){
                flag =1;
                continue;
            }
            else{
                flag = 0;
                break;
            }
        }   
    }
    if (flag == 1){
       printf("Yes, the input is a well-formed string of parentheses.");
    }
    if (flag ==0){
       printf("No, the input is NOT a well-formed string of parentheses.");
    }
}

    

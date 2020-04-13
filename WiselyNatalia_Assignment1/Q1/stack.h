typedef struct stackNode *stackADT;
typedef char stackElementT;
stackADT EmptyStack(void);
void Push (stackADT stack, stackElementT element);
stackElementT Pop(stackADT stack);
int StackDepth(stackADT stack);
int StackIsEmpty(stackADT stack);

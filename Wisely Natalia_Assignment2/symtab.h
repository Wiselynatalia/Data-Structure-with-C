#include "list.h" // Please refer the lecture notes.

typedef struct symtabCDT *symtabADT;
typedef listADT symtabEntryT;
typedef void (*symtabFnT)(char*, symtabEntryT);
symtabADT EmptySymbolTable(void);

void Enter(symtabADT, char*, symtabEntryT); symtabEntryT Lookup(symtabADT, char*); // It returns an empty list if the entry does not exist. void forEachEntryDo(symtabFnT, symtabADT);
void ShowAll(symtabADT); // Detailed description will be provided later.
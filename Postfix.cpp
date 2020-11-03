// C++ program to evaluate value of a postfix expression  
#include <iostream>  
#include <string.h>  

  

using namespace std; 

  
// Stack type  

struct Stack  
{  

    int top;  

    unsigned capacity;  

    int* array;  
};  

  
// Stack Operations  

struct Stack* createStack( unsigned capacity )  
{  

    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));  

  

    if (!stack) return NULL;  

  

    stack->top = -1;  

    stack->capacity = capacity;  

    stack->array = (int*) malloc(stack->capacity * sizeof(int));  

  

    if (!stack->array) return NULL;  

  

    return stack;  
}  

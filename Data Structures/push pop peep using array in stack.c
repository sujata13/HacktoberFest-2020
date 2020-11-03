#include<stdio.h>
#include<stdlib.h>
#define max 10
int stack[max],top=-1;
void push();
void pop();
void peek();
void display();
void main()
{
    int n;
    while(1)
    {
        printf("\n1. PUSH AN ELEMENT.");
        printf("\n2. POP AN ELEMENT.");
        printf("\n3. PEEk AN ELEMENT.");
        printf("\n4. DISPLAY AN ELEMENT.");
        printf("\n5. EXIT.");
        printf("\nChoose an option.");
        scanf("%d",&n);
        switch(n)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("enter again");
        }
    }
}
void push()
{
    int item;
    if(top==max-1)
        printf("STACK IS FULL.");
    else
    {
        printf("Enter a element to push.");
        scanf("%d",&item);
        top++;
        stack[top]=item;
    }
}
void pop()
{
    int item;
    if(top==-1)
        printf("STACK IS EMPTY.");
    else
    {
        item=stack[top];
        top=top-1;
        printf("THE POPPED VALUE IS %d",item);
    }
}
void peek()
{
    int item;
    if(top==-1)
        printf("STACK IS EMPTY.");
    else
    {
        item=stack[top];
        printf("THE PEEPED VALUE IS %d",item);
    }
}
void display()
{
    if(top==-1)
        printf("STACK IS EMPTY.");
    else
    {
        int i;
        printf("STACK IS \n");
        for(i=top;i>=0;i--)
        {
            printf("%d ",stack[i]);
        }
    }
}

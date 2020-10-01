#include<stdio.h>
# define max 20
int stack[max];
int top=-1;
int isempty()
{
    if(top==-1)
        return 1;
    else
        return 0;
}
int isfull()
{
    if(top==max-1)
        return 1;
    else
        return 0;
}
void push(int stack[],int n)
{
    if(!isfull())
    {
        top++;
        stack[top]=n;
    }
}
int pop(int stack[])
{
    int item;
    if(!isempty())
    {
        item=stack[top];
        top--;
    }
    return item;
}
int peek()
{
    int item;
    if(!isempty())
    {
        item=stack[top];
    }
    return(item);
}
void main()
{
    char arr[100];
    printf("Enter expression in postfix: ");
    gets(arr);
    int i=0,ct1,ct;
    int pp1,pp2,item,h;
    while(arr[i]!='\0')
    {
        ct1=(arr[i]);
        ct=ct1-48;
        if((ct>=0)&&(ct<10))
        {
            push(stack,ct);
        }
        else if((ct==-11)||(ct==-6)||(ct==-5)||(ct==-3)||(ct==-1))
        {
            if(ct==-11)
            {
                pp1=pop(stack);
                pp2=pop(stack);
                item=pp2%pp1;
                push(stack,item);
            }
            else if(ct==-6)
            {
                pp1=pop(stack);
                pp2=pop(stack);
                item=pp2*pp1;
                push(stack,item);
            }
            else if(ct==-5)
            {
                pp1=pop(stack);
                pp2=pop(stack);
                item=pp2+pp1;
                push(stack,item);
            }
            else if(ct==-3)
            {
                pp1=pop(stack);
                pp2=pop(stack);
                item=pp2-pp1;
                push(stack,item);
            }
            else if(ct==-1)
            {
                pp1=pop(stack);
                pp2=pop(stack);
                item=pp2/pp1;
                push(stack,item);
            }
        }
        i++;
    }
    h=pop(stack);
    printf("%d",h);
}

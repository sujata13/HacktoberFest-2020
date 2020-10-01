#include<stdio.h>
#include<stdlib.h>
# define max 10
char stack[max];
int top=-1;
void push(char n)
{
        top++;
        stack[top]=n;
}
char pop()
{
    char item;
    item=stack[top];
    top--;
    return(item);
}
void peep()
{
    int item;
    if(top==-1)
        printf("STACK IS EMPTY.");
    else
    {
        item=stack[top];
        printf("THE PEEPED VAUE IS %d",item);
    }
}
void main()
{
    char arr[100];
    int co=0,flag=1;
    char cm;
    printf("Enter . to exit: ");
    gets(arr);
    while(arr[co]!='.')
    {
        co++;
    }
    int i;
    char ch;
    for(i=0;i<=co;i++)
    {
        cm=arr[i];
        if((cm=='[')||(cm=='{')||(cm=='('))
        {
            push(cm);
        }
        else if((cm==')')||(cm=='}')||(cm==']'))
        {
            if(top==-1)
            {
                flag=0;
                break;
            }
            else
            {
                ch=pop();
                if(cm==')' && ch!='(')
                {
                    flag=0;
                    break;
                }
                else if(cm=='}' && ch!='{')
                {
                    flag=0;
                    break;
                }
                else if(cm==']' && ch!='[')
                {
                    flag=0;
                    break;
                }
            }
        }
    }
    if(top!=-1)
        flag=0;
    if(flag==1)
        printf("VALID EXPRESSION");
    else
        printf("INVALID EXPRESSION");
}

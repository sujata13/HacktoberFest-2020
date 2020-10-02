#include<stdio.h>
int main()
{
    int n1,n2;
    int *ptr1,*ptr2;
    ptr1=&n1;
    ptr2=&n2;
    int sum=0;
    printf("\n Enter value of n1 & n2\n");
    scanf("%d%d",&n1,&n2);
    sum=*ptr1+*ptr2;
    printf("\nsum : %d + %d = %d\n",n1,n2,sum);
    return 0;
}

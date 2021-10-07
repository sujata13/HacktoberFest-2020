#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,n;
    printf("Enter the value of n");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        printf("%d ",2*i);
    
    printf("\n");
    
    //Check n even or odd
    if(n%2==0){
        printf("n is even");
    }
    else{
        printf("n is odd");
    }
    return 0;
}

/*This code is useful for converting decimal number to binary form*/
#include<stdio.h>
long long int tobinary(int n);
int main()
{	int n,i;
	printf("Input any decimal number :  ");
	scanf("%d",&n);
	long long int bno = tobinary(n);
	printf("The binary value is :%lld",bno);
	return 0;
}
long long int tobinary(int n)
{	long long int binary=0;
	int f=1,rem;
	for(;n!=0;n/=2,f*=10)
	{
	rem = n%2;
	binary = binary + rem * f;
	}

return 	binary;
}

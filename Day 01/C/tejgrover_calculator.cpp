//calculator by tejgrover in c
#include<stdio.h>
#include<conio.h>

int a=0, b, c, d, i, j, n;
char ch;
void table()
{
	printf("");
	for(i=1; i<=10; i++)
	{
		printf("-----------------------------------------------------------------------\n");
		for(j=2; j<=11; j++)
		{
			printf("|  %d", i*j);
			if(i*j < 10)
			{
				printf("  ");
			}
			if(i*j >= 10 && i*j < 100)
			{
				printf(" ");
			}
			if(i*j <= 110)
			{
				printf(" ");
			}
		}
		printf("|\n");
	}
	printf("-----------------------------------------------------------------------\n");

}
void table2()
{
	printf("");
	for(i=1; i<=10; i++)
	{
		printf("-----------------------------------------------------------------------\n");
		for(j=11; j<=20; j++)
		{
			printf("|  %d", i*j);
			if(i*j < 10)
			{
				printf("  ");
			}
			if(i*j >= 10 && i*j < 100)
			{
				printf(" ");
			}
			if(i*j <1000)
			{
				printf(" ");
			}
		}
		printf("|\n");
	}
	printf("-----------------------------------------------------------------------\n");

}
void table3()
{
	int l=0;
	printf("enter the no. from which table will start:>> ");
	scanf("%d",&l);
	for(i=1;i<=10;i++)
	{
		printf("-----------------------------------------------------------------------\n");
		for(j=l; j<=l+9; j++)
		{
			printf("|  %d", i*j);
			if(i*j < 10)
			{
				printf("  ");
			}
			if(i*j >= 10 && i*j < 100)
			{
				printf(" ");
			}
			if(i*j <1000)
			{
				printf(" ");
			}
		}
		printf("|\n");
	}
	printf("-----------------------------------------------------------------------\n");



}

void values()
{
	 printf("enter first number:>> ");
	 scanf("%d",&a);
	 printf("enter second number:>> ");
	 scanf("%d",&b);
};
void cal()
{     printf("\t\t\t&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n");
      printf("\t\t\t&& enter 1 for sum 	           &&\n");
      printf("\t\t\t&& enter 2 for subs	           &&\n");
      printf("\t\t\t&& enter 3 for mul	           &&\n");
      printf("\t\t\t&& enter 4 for div                 &&\n");
      printf("\t\t\t&& enter 5 for table from 2 to 11  &&\n");
      printf("\t\t\t&& enter 6 for table from 11 to 20 &&\n");
      printf("\t\t\t&& enter 7 for customized table    &&\n");
      printf("\t\t\t&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n\n");

      printf("enter your choice:>> ");
      scanf("%d",&d);
      switch(d)
      {
		 case 1:
		{
		       values();
		       c=a+b;
		       printf("Result is : %d", c);
		       do
		       {
				printf("\nDo You Want To Add More Number ? : ");
				fflush(stdin);
				scanf("%c", &ch);
				if(ch == 'y')
				{
					printf("\nEnter New Number : ");
					scanf("%d", &n);
					c = c + n;
					printf("New Result is : %d", c);
				}
				else if(ch == 'n')
				{
					printf("Bye Bye");
				}


		       }
		       while(ch == 'y');
		       break;
		}
	      case 2: {

		       values();
		       c=a-b;
			printf("Result is : %d", c);
		       do
		       {
				printf("\nDo You Want To Add More Number ? : ");
				fflush(stdin);
				scanf("%c", &ch);
				if(ch == 'y')
				{
					printf("\nEnter New Number : ");
					scanf("%d", &n);
					c = c - n;
					printf("New Result is : %d", c);
				}
				else if(ch == 'n')
				{
					printf("Bye Bye");
				}


		       }
		       while(ch == 'y');
		       break;
		     }
	      case 3: {

		       values();
		       c=a*b;
			printf("Result is : %d", c);
		       do
		       {
				printf("\nDo You Want To Add More Number ? : ");
				fflush(stdin);
				scanf("%c", &ch);
				if(ch == 'y')
				{
					printf("\nEnter New Number : ");
					scanf("%d", &n);
					c = c * n;
					printf("New Result is : %d", c);
				}
				else if(ch == 'n')
				{
					printf("Bye Bye");
				}


		       }
		       while(ch == 'y');
		       break;
		      }
	      case 4: {
		       values();
		       c=a/b;
			printf("Result is : %d", c);
		       do
		       {
				printf("\nDo You Want To Add More Number ? : ");
				fflush(stdin);
				scanf("%c", &ch);
				if(ch == 'y')
				{
					printf("\nEnter New Number : ");
					scanf("%d", &n);
					c = c / n;
					printf("New Result is : %d", c);
				}
				else if(ch == 'n')
				{
					printf("Bye Bye");
				}


		       }
		       while(ch == 'y');
		       break;
		     }
	      case 5:
	       {
			table();
			break;
		   }
	      case 6: {
			table2();
			break;
		      }
	      case 7: {
			table3();
			break;
		      }

	      };

}
//calculator by tejgrover in c
int main()
{
     clrscr();
     cal();
     getch();
     return 0;
}

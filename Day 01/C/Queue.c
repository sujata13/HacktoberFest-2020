#include <stdio.h>
#include<stdlib.h>
#define MAX 100

int queue_array[MAX];
int rear = -1;
int front = -1;

void insert()
{int item;
 if(rear == MAX - 1)
    printf("\nQueue Overflow ");
 else
    {if (front == -1)
     front = 0;
     printf("\nInset the element in queue:");
	 scanf("%d", &item);
	 rear = rear + 1;
	 queue_array[rear] = item;
    }
}

void del()
{if(front == -1 || front > rear)
   {printf("\nQueue Underflow ");
	return;}
 else
   {printf("\nElement deleted from queue is : %d", queue_array[front]);
	front = front + 1;
   }
}

void display()
{int i;
 if (front == -1)
    printf("\nQueue is empty");
 else
   {printf("\nQueue is:");
	for (i = front; i <= rear; i++)
	    printf("%d ", queue_array[i]);
		printf("\n");
   }
}

int main()
{int choice;
 while(1)
      {printf("\n1.Insert element to queue ");
	   printf("\n2.Delete element from queue ");
	   printf("\n3.Display all elements of queue ");
	   printf("\n4.Quit ");
	   printf("\nEnter your choice : ");
	   scanf("%d", &choice);
	   switch(choice)
	   	     {case 1: insert(); break;
			  case 2: del(); break;
			  case 3: display(); break;
			  case 4: exit(1);
			  default: printf("\nWrong choice ");
			 }
	  }
 return 0;
}

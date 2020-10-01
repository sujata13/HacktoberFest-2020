#include<stdio.h>
#include<stdlib.h>
struct arrayqueue
{
    int rear,front;
    int capacity;
    int *array;
};
struct arrayqueue* createqueue()
{
   struct arrayqueue *t;
   t=(struct arrayqueue* )malloc(sizeof(struct arrayqueue));
   printf("Enter the capacity of queue:");
   scanf("%d",&t->capacity);
   t->rear=-1;
   t->front=-1;
   t->array=malloc(sizeof(int)*(t->capacity));
   return t;
}
void insertelement(struct arrayqueue *r)
{
    int n;
    printf("Enter an element:");
    scanf("%d",&n);
    if((r->rear==(r->capacity-1))&&(r->front==0))
        printf("\nOVERFLOW");
    else if((r->rear==(r->capacity-1))&&(r->front!=0))
    {
         r->rear=0;
         r->array[r->rear]=n;
    }
    else if((r->rear==-1)&&(r->front==-1))
    {
        r->rear=r->front=0;
        r->array[r->rear]=n;
    }
    else
    {
        r->rear=r->rear+1;
        r->array[r->rear]=n;
    }

}
void deleteelement(struct arrayqueue *r)
{
    int data;
    if(r->front==-1)
        printf("UNDERFLOW.");
    else if(r->rear==r->front)
    {
        data=r->array[r->front];
        r->front=-1;
        r->rear=-1;
        printf("The deleted element is %d",data);
    }
    else if(r->front==(r->capacity-1))
    {
        data=r->array[r->front];
        r->front=0;
        printf("The deleted element is %d",data);
    }
    else
    {
        data=r->array[r->front];
        r->front=r->front+1;
        printf("The deleted element is %d",data);
    }
}
void peek(struct arrayqueue *r)
{
    int data;
    if(r->front==-1)
        printf("Queue is empty");
    else
    {
        data=r->array[r->front];
        printf("The peeked element is %d",data);
    }
}
void displayqueue(struct arrayqueue *r)
{
    int i;
    if(r->front==-1)
        printf("Queue is empty.");
    else
    {
        if(r->front<r->rear)
        {
            for(i=r->front;i<=r->rear;i++)
                printf("%d ",r->array[i]);
        }
        else if(r->front==r->rear)
            printf("%d ",r->front);
        else
        {
            for(i=r->front;i<r->capacity;i++)
                printf("%d ",r->array[i]);
            for(i=0;i<=r->rear;i++)
            {
                printf("%d ",r->array[i]);
            }
        }
    }
}
int menu()
{
    int n;
    printf("\n1. Insert an element.");
    printf("\n2. Delete an element.");
    printf("\n3. peek an element.");
    printf("\n4. display the queue.");
    printf("\n5. Exit");
    printf("\nEnter your choice:");
    scanf("%d",&n);
    return n;
}
void main()
{
    struct arrayqueue *temp;
    temp=createqueue();
    while(1)
    {
     switch(menu())
     {
     case 1:
         insertelement(temp);
         break;
     case 2:
        deleteelement(temp);
        break;
     case 3:
        peek(temp);
        break;
     case 4:
        displayqueue(temp);
        break;
     case 5:
        exit(0);
        break;
     default:
        printf("Enter again");
     }
    }
}

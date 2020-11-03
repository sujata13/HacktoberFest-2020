#include<stdio.h>
#include<stdlib.h>
struct arrayqueue
{
    int front,rear;
    int *array;
    int capacity;
};
struct arrayqueue* createqueue()
{
    struct arrayqueue *t;
    t=malloc(sizeof(struct arrayqueue));
    printf("Enter the size of array:");
    scanf("%d",&t->capacity);
    t->array=malloc(sizeof(int)*t->capacity);
    t->rear=-1;
    t->front=-1;
    return t;
}
void insertelement(struct arrayqueue *r)
{
    int n;
    printf("Enter the element to enter in queue:");
    scanf("%d",&n);
    if(r->front==r->rear)
    {
        if(r->front==-1)
        {
            r->rear=0;
            r->front=0;
            r->array[r->rear]=n;
            printf("ELEMENT ADDED SUCESSFULLY!");
        }
        else
        {
            if(r->rear==r->capacity-1)
            {
                r->rear=0;
            }
            else
            {
                r->rear=r->rear+1;
            }
            r->array[r->rear]=n;
            printf("ELEMENT ADDED SUCESSFULLY!");
        }
    }
    else if((r->rear==(r->capacity-1))&&(r->front==0)||(r->front==r->rear+1))
    {
        printf("ELEMENT CANNOT BE ADDED!");
    }
    else
    {
         if(r->rear==r->capacity-1)
            r->rear=0;
         else
            r->rear=r->rear+1;
         r->array[r->rear]=n;
         printf("ELEMENT ADDED SUCESSFULLY!");
    }
}
void deleteelement(struct arrayqueue *r)
{
    int data;
    if((r->rear==-1)&&(r->front==-1))
        printf("QUEUE IS EMPTY");
    else if(r->rear==r->front)
    {
        data=r->array[r->front];
        r->rear=-1;
        r->front=-1;
        printf("THE DELETED ELEMENT IS %d",data);
    }
    else if(r->front==r->capacity-1)
    {
        data=r->array[r->front];
        r->front=0;
        printf("THE DELETED ELEMENT IS %d",data);
    }
    else
    {
        data=r->array[r->front];
        r->front++;
        printf("THE DELETED ELEMENT IS %d",data);
    }
}
void peek(struct arrayqueue *r)
{
    int data;
    if((r->rear==-1)&&(r->front==-1))
        printf("QUEUE IS EMPTY!");
    else
    {
        data=r->array[r->rear];
        printf("THE PEEKED VALUE IS %d",data);
    }
}
void displayqueue(struct arrayqueue *r)
{
    int i;
    if((r->front<=r->rear)&&(r->front!=-1))
    {
        for(i=r->front;i<=r->rear;i++)
        {
            printf("%d ",r->array[i]);
        }
    }
    else if((r->rear==-1)&&(r->front==-1))
        printf("QUEUE IS EMPTY!");
    else
    {
        for(i=r->front;i<r->capacity;i++)
            printf("%d ",r->array[i]);
        for(i=0;i<=r->rear;i++)
            printf("%d ",r->array[i]);
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

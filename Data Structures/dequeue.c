#include<stdio.h>
#include<stdlib.h>
struct dequeue
{
    int rear,front;
    int *array;
    int capacity;
};
struct dequeue* createdequeue()
{
    struct dequeue *t;
    t=malloc(sizeof(struct dequeue));
    printf("Enter the size of array:");
    scanf("%d",&t->capacity);
    t->array=malloc(sizeof(int)*(t->capacity));
    t->rear=-1;
    t->front=-1;
    return t;
}
void insert_left(struct dequeue *r)
{
    int n;
    printf("ENTER AN ELEMENT TO INSERT AT LEFT.");
    scanf("%d",&n);
    if(r->rear==r->front)
    {
        if(r->front==-1)
        {
            r->rear=0;
            r->front=0;
        }
        else
        {
            r->front--;
        }
        r->array[r->front]=n;
        printf("ELEMENT ADDED SUCESSFULLY!");
    }
    else if(r->front==0)
    {
        if(r->rear!=(r->capacity-1))
        {
            r->front=r->capacity-1;
            r->array[r->front]=n;
            printf("ELEMENT ADDED SUCESSFULLY!");
        }
        else
            printf("ELEMENT CANNOT BE ADDED!");
    }
    else if((r->rear==(r->capacity-1)&&(r->front==0))||(r->front==r->rear+1))
    {
        printf("ELEMENT CANNOT BE ADDED!");
    }
    else
    {
        r->front--;
        r->array[r->front]=n;
        printf("ELEMENT ADDED SUCESSFULLY!");
    }
}
void insert_right(struct dequeue *r)
{
    int k;
    printf("ENTER ELEMENT TO INSERT AT RIGHT.");
    scanf("%d",&k);
    if(r->rear==r->front)
    {
        if(r->front==-1)
        {
            r->rear=0;
            r->front=0;
        }
        else
        {
            if(r->rear==(r->capacity-1))
                r->rear=0;
            else
                r->rear++;
        }
        r->array[r->rear]=k;
        printf("ELEMENT ADDED SUCESSFULLY!");
    }
    else if(((r->rear==r->capacity-1)&&(r->front==0))||(r->front==r->rear+1))
        printf("ELEMENT CANNOT BE ADDED!");
    else
    {
        if(r->rear==(r->capacity-1))
            r->rear=0;
        else
            r->rear++;
        r->array[r->rear]=k;
        printf("ELEMENT ADDED SUCESSFULLY!");
    }
}
void delete_left(struct dequeue *r)
{
    if(r->rear==r->front)
    {
        if(r->front==-1)
            printf("ELEMENT CANNOT BE DELETED!");
        else
        {
            r->rear=-1;
            r->front=-1;
            printf("ELEMENT DELETED!");
        }
    }
    else
    {
        if(r->front==(r->capacity-1))
            r->front=0;
        else
            r->front++;
        printf("ELEMENT DELETED!");
    }
}
void delete_right(struct dequeue *r)
{
    if(r->rear==r->front)
    {
        if(r->front==-1)
            printf("ELEMENT CANNOT BE DELETED!");
        else
        {
            r->rear=-1;
            r->front=-1;
            printf("ELEMENT DELETED!");
        }
    }
    else if(r->rear==0)
    {
        r->rear=r->capacity-1;
        printf("ELEMENT DELETED!");
    }
    else
    {
        r->rear--;
        printf("ELEMENT DELETED!");
    }
}
void display_dequeue(struct dequeue *r)
{
    int i;
    if(r->front==-1&&r->rear==-1)
        printf("QUEUE IS EMPTY");
    else{
        if(r->front<=r->rear)
        {
            for(i=r->front;i<=r->rear;i++)
                printf("%d ",r->array[i]);
        }
        else
        {
            for(i=r->front;i<r->capacity;i++)
                printf("%d ",r->array[i]);
            for(i=0;i<=r->rear;i++)
                printf("%d ",r->array[i]);
        }
    }
}
int menu()
{
    int n;
    printf("\n1. Insert an element from left.");
    printf("\n2. Insert an element from right.");
    printf("\n3. Delete an element from left.");
    printf("\n4. Delete an element from right.");
    printf("\n5. display the queue.");
    printf("\n6. Exit");
    printf("\nEnter your choice:");
    scanf("%d",&n);
    return n;
}
void main()
{
    struct dequeue *temp;
    temp=createdequeue();
    while(1)
    {
     switch(menu())
     {
     case 1:
         insert_left(temp);
         break;
     case 2:
        insert_right(temp);
        break;
     case 3:
        delete_left(temp);
        break;
     case 4:
        delete_right(temp);
        break;
     case 5:
        display_dequeue(temp);
        break;
     case 6:
        exit(0);
        break;
     default:
        printf("Enter again");
     }
    }
}

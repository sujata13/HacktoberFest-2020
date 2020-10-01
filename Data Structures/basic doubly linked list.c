#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *prev,*next;
};
struct node *START=NULL;
struct node* createnode()
{
     struct node *t;
     t=(struct node*)malloc(sizeof(struct node));
     return(t);
}
void insertnodeb()
{
     struct node *r;
     r=createnode();
     r->prev=NULL;
     r->next=NULL;
     printf("Enter a number");
     scanf("%d",&r->info);
    if(START==NULL)
    {
        START=r;
    }
    else
    {
        struct node *temp;
        temp=START;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        r->prev=temp;
        temp->next=r;
    }
}
void insertnodef()
{
    struct node *r;
    r=createnode();
    r->prev=NULL;
    printf("Enter a number");
    scanf("%d",&r->info);
    if(START==NULL)
    {
        r->next=NULL;
        START=r;
    }
    else
    {
        struct node *t;
        START->prev=r;
        r->next=START;
        START=r;
    }
}
void insertnodeafternode()
{
    int n;
    printf("Enter the element after which you want to enter node.\n");
    scanf("%d",&n);
    struct node *t,*r;
    r=createnode();
    printf("Enter the element you want to enter.");
    scanf("%d",&r->info);
    t=START;
    while(t->info!=n)
    {
        t=t->next;
    }
    r->prev=t;
    r->next=t->next;
    t->next=r;
    t->next->prev=r;
}
void insertnodebeforenode()
{
    int n;
    struct node *t,*temp,*r;
    t=createnode();
    printf("Enter a node before which you want to enter node.");
    scanf("%d",&n);
    printf("Enter the number you want to enter.");
    scanf("%d",&t->info);
    temp=START;
    while(temp->info!=n)
    {
        temp=temp->next;
    }
    r=temp->prev;
    t->prev=r;
    t->next=r->next;
    temp->prev=t;
    r->next=t;
}
void deletenodeb()
{
    if(START==NULL)
        printf("List is empty");
    else
    {
        struct node *t;
        t=START;
        while(t->next!=NULL)
        {
            t=t->next;
        }
        if(t->next==t->prev)
            START=NULL;
        else
        {
            t->prev->next=NULL;
        }

    }
}
void deletenodef()
{
    struct node *t;
    if(START==NULL)
        printf("The list is empty");
    else
    {
        if(START->next!=NULL)
        {
            START->next->prev=NULL;
            START=START->next;
        }
        else
        {
            START=NULL;
        }
    }
}
void deletenodeafternode()
{
    int n;
    printf("Enter a element after which you want to delete node.\n");
    scanf("%d",&n);
    struct node *t,*temp;
    t=START;
    while(t->info!=n)
    {
        t=t->next;
    }
    temp=t->next;
    if(temp!=NULL)
    {
        temp->next->prev=t;
        t->next=temp->next;
    }
    else
        printf("End of the list.");
}
void deletenodebeforenode()
{
   struct node *t,*r,*temp;
   int n;
   printf("Enter a node before which you want to delete node.");
   scanf("%d",&n);
   t=START;
   while(t->info!=n)
   {
       t=t->next;
   }
   r=t->prev;
   temp=r->prev;
   if(r->prev!=NULL)
   {
        temp->next=r->next;
        t->prev=r->prev;
   }
   else
   {
       START=r->next;
       t->prev=NULL;
   }
}
void countnode()
{
    if(START==NULL)
        printf("\n0");
    else
    {
        int co=0;
        struct node *t;
        t=START;
        while(t!=NULL)
        {
            co++;
            t=t->next;
        }
        printf("\n%d",co);
    }
}
void viewlist()
{
    if(START==NULL)
        printf("The list is empty");
    else
    {
        struct node *t;
        t=START;
        while(t!=NULL)
        {
            printf("%d ",t->info);
            t=t->next;
        }
    }
}
void sortlist()
{
    struct node *i,*j,*t;
    int ch,temp;
    t=START;
    for(i=START;i!=NULL;i=i->next)
    {
        for(j=i->next;j!=NULL;j=j->next)
        {
            if(j->info < i->info)
            {
                temp=j->info;
                j->info=i->info;
                i->info=temp;
            }
        }
    }
}
int menu()
{
    int n;
    printf("\n1. Insert element at back.");
    printf("\n2. Insert element at front.");
    printf("\n3. Insert node after a node.");
    printf("\n4. Insert node before node.");
    printf("\n5. Delete element from back.");
    printf("\n6. Delete element from front.");
    printf("\n7. Delete element after a node.");
    printf("\n8. Delete node before a node.");
    printf("\n9. View List");
    printf("\n10.Sort list");
    printf("\n11. Count nodes");
    printf("\n12. Exit");
    printf("\nEnter your choice.");
    scanf("%d",&n);
    return(n);
}
void main()
{
    while(1)
    {
        switch(menu())
        {
        case 1:
            insertnodeb();
            break;
        case 2:
            insertnodef();
            break;
        case 3:
            insertnodeafternode();
            break;
        case 4:
            insertnodebeforenode();
            break;
        case 5:
            deletenodeb();
            break;
        case 6:
            deletenodef();
            break;
        case 7:
            deletenodeafternode();
            break;
        case 8:
            deletenodebeforenode();
            break;
        case 9:
            viewlist();
            break;
        case 10:
            sortlist();
            break;
        case 11:
            countnode();
            break;
        case 12:
            exit(0);
            break;
        default:
            printf("\nEnter again.");
        }
    }
}

#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *link;
};
struct node *START=NULL;
struct node* createnode()
{
   struct node *n;
   n=(struct node*)malloc(sizeof(struct node));
   return(n);
}
void insertnodeb()
{
    struct node *t,*temp;
    temp=createnode();
    printf("Enter a number");
    scanf("%d",&temp->info);
    if(START==NULL)
        START=temp;
    else
    {
        t=START;
        while(t->link!=START)
        {
            t=t->link;
        }
        t->link=temp;
    }
    temp->link=START;
}
void insertnodef()
{
    struct node *n;
    n=createnode();
    printf("Enter a number");
    scanf("%d",&n->info);
    if(START!=NULL)
    {
        struct node *ptr;
        ptr=START;
        while(ptr->link!=START)
            ptr=ptr->link;
        ptr->link=n;
        n->link=START;
        START=n;
    }
    else
    {
        START=n;
        n->link=START;
    }
}
void deletenodef()
{
    if(START==NULL)
        printf("List is Empty.");
    else
    {
        struct node *ptr;
        ptr=START;
        while(ptr->link!=START)
        {
            ptr=ptr->link;
        }
        START=START->link;
        ptr->link=START;
    }
}
void deletenodeb()
{
    if(START==NULL)
        printf("List is empty");
    else
    {
        struct node *t,*r;
        t=START;
        r=START;
        while(t->link!=START)
        {
            r=t;
            t=t->link;
        }
        r->link=START;
    }
}
void viewlist()
{
    if(START==NULL)
        printf("Linked list is empty");
    else
    {
        struct node *ptr;
        ptr=START;
        printf("The linked list is: ");
        while(ptr->link!=START)
        {
            printf("%d - ",ptr->info);
            ptr=ptr->link;
        }
        printf("%d\n",ptr->info);
    }
}
void addnodeafternode()
{
    int n,h;
    printf("Enter number after which you want to enter node.");
    scanf("%d",&n);
    printf("\nEnter the number you want to enter.");
    scanf("%d",&h);
    struct node *temp;
    struct node *r;
    temp=createnode();
    temp->info=h;
    r=START;
    while(r->info!=n)
    {
        r=r->link;
    }
    temp->link=r->link;
    r->link=temp;
}
void addnodebeforenode()
{
    int n,h;
    printf("Enter a number before which you want to enter node.");
    scanf("%d",&n);
    printf("Enter the number you want to enter.");
    scanf("%d",&h);
    struct node *r,*t,*temp;
    temp=createnode();
    temp->info=h;
    if(n!=START->info)
    {
        t=START;
        r=START;
        while(t->info!=n)
        {
            r=t;
            t=t->link;
        }
        temp->link=t;
        r->link=temp;
    }
    else
    {
        temp->link=START;
        struct node *ptr;
        ptr=START;
        while(ptr->link!=START)
        {
            ptr=ptr->link;
        }
        ptr->link=temp;
        START=temp;
    }
}
void deletenodeafternode()
{
    int n;
    printf("Enter a number after which you want to delete node.");
    scanf("%d",&n);
    struct node *t,*temp,*r;
    t=START;
    r=START;
    while(t->info!=n)
    {
        r=t;
        t=t->link;
    }
    temp=t->link;
    t->link=temp->link;
}
int numberofnodes()
{
    struct node *temp,*t;
    int co=1;
    temp=START;
    while(temp->link!=START)
    {
        co++;
        temp=temp->link;
    }
    return(co);
}
void sortlist()
{
    struct node *i,*j;
    int ch,temp;
    temp=START;
    ch=numberofnodes();
    for(i=START;i!=START;i=i->link)
    {
        for(j=i->link;j!=START;j=j->link)
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
    printf("\n3. Insert element after a given node.");
    printf("\n4. Insert element before a given node.");
    printf("\n5. Delete element from front.");
    printf("\n6. Delete element from back.");
    printf("\n7. Delete element after a given node.");
    printf("\n8. count the number of elements.");
    printf("\n9.sort the list.");
    printf("\n10. View list.");
    printf("\n11. exit.");
    printf("\nMake your choice.");
    scanf("%d",&n);
    return n;
}
void main()
{
    int h;
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
            addnodeafternode();
            break;
        case 4:
            addnodebeforenode();
            break;
        case 5:
            deletenodef();
            break;
        case 6:
            deletenodeb();
            break;
        case 7:
            deletenodeafternode();
            break;
        case 8:
            h=numberofnodes();
            printf("%d",h);
            break;
        case 10:
            viewlist();
            break;
        case 9:
            sortlist();
            break;
        case 11:
            exit(0);
            break;
        default:
            printf("\nEnter again.");
        }
    }
}


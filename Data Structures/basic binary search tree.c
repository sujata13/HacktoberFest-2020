#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *ROOT;
void inittree()
{
    ROOT=NULL;
}

struct node* createnode(int key)
{
    struct node *t;
    t=malloc(sizeof(struct node));
    t->data=key;
    t->left=NULL;
    t->right=NULL;
    return t;
}
struct node* insertnode(int key,struct node *t)
{
    struct node *tmp;
    if(t==NULL)
    {
        tmp=createnode(key);
        return tmp;
    }
    if(t->data > key)
        t->left=insertnode(key,t->left);
    else if(t->data < key)
        t->right=insertnode(key,t->right);
}
void insertkey()
{
    int h;
    printf("enter the key you want to insert:");
    scanf("%d",&h);
    ROOT=insertnode(h,ROOT);
}

void printTree(struct node *t,int spaces)
{
    if(ROOT==NULL)
        printf("TREE IS EMPTY.\n");
    if(t==NULL)
        return ;
    spaces=spaces+10;
    printTree(t->right,spaces);
    printf("\n");
    for(int i=spaces;i>10;i--)
        printf(" ");
    printf("%d",t->data);
    printTree(t->left,spaces);
}
void printT(struct node *t)
{
    printTree(t,0);
}

int graftReplacementKey(struct node *t)
{
    struct node *parent;
    while(t->right!=NULL)
    {
        parent=t;
        t=t->right;
    }
    int k=t->data;
    parent->right=t->left;
    free(t);
    return k;
}
struct node* deletenode(int key,struct node *t)
{
    if(t==NULL)
        return t;
    if(t->data > key)
    {
        t->left=deletenode(key,t->left);
        return t;
    }
    else if(t->data < key)
    {
        t->right=deletenode(key,t->right);
        return t;
    }
    else
    {
        struct node *tmp;
        if(t->left==NULL)
        {
            tmp=t->right;
            free(t);
            return tmp;
        }
        else if(t->right==NULL)
        {
            tmp=t->left;
            free(t);
            return tmp;
        }
        else
        {
            t->data=graftReplacementKey(t->left);
            return t;
        }
    }
}

void deletekey()
{
    int h;
    printf("enter key you want to delete.");
    scanf("%d",&h);
    ROOT=deletenode(h,ROOT);
}
void find(int key,struct node *t)
{
    if(t==NULL)
        printf("TREE DOES NOT CONTAIN THIS VALUE.\n");
    else
    {
        if(t->data > key)
            find(key,t->left);
        else if(t->data < key)
            find(key,t->right);
        else
            printf("VALUE FOUND!\n");
    }
}
int height(struct node *t)
{
    int lh,rh;
    if(t==NULL)
        return 0;
    else
    {
        lh=height(t->left);
        rh=height(t->right);
        if(lh > rh)
            return (lh+1);
        else
            return (rh+1);
    }
}
void hg()
{
    int k;
    k=height(ROOT);
    printf("THE HEIGHT OF THE TREE IS %d\n",k);
}
int totalnodes(struct node *t)
{
    int ln,rn;
    if(t==NULL)
        return 0;
    ln=totalnodes(t->left);
    rn=totalnodes(t->right);
    return (ln+rn+1);
}
int totalintnodes(struct node *t)
{
    if(t==NULL || (t->left==NULL && t->right==NULL))
        return 0;
    return (totalintnodes(t->left)+totalintnodes(t->right)+1);
}
int totalextnodes(struct node *t)
{
    if(t==NULL)
        return 0;
    else if(t->left==NULL && t->right==NULL)
        return 1;
    else
        return (totalextnodes(t->left)+totalextnodes(t->right));
}
void main()
{
    int k;
    inittree();
    int h;
    while(1)
    {
        printf("\n1. INSERT AN ELEMENT IN A TREE.\n");
        printf("2. DELETE AN ELEMENT FROM A TREE.\n");
        printf("3. PRINT THE TREE.\n");
        printf("4. FIND A VALUE.\n");
        printf("5. FIND THE HEIGHT OF THE TREE.\n");
        printf("6. FIND THE TOTAL NODES IN THE TREE.\n");
        printf("7. FIND THE TOTAL INTERNAL NODES IN THE TREE.\n");
        printf("8. FIND THE TOTAL EXTERNAL NODES IN THE TREE.\n");
        printf("9. EXIT.\n");
        scanf("%d",&h);
        switch(h)
        {
        case 1:
            insertkey();
            break;
        case 2:
            deletekey();
            break;
        case 3:
            printT(ROOT);
            break;
        case 4:
            printf("ENTER A VALUE TO FIND IN TREE.\n");
            scanf("%d",&k);
            find(k,ROOT);
            break;
        case 5:
            hg();
            break;
        case 6:
            k=totalnodes(ROOT);
            printf("THE TOTAL NODES IN THE TREE ARE %d",k);
            break;
        case 7:
            k=totalintnodes(ROOT);
            printf("THE TOTAL INTERNAL NODES INTHE TREE ARE %d\n",k);
            break;
        case 8:
            k=totalextnodes(ROOT);
            printf("TOTAL EXTERNAL NODES IN THE TREE ARE %d\n",k);
            break;
        case 9:
            exit(0);
            break;
        default:
            printf("ENTER AGAIN\n");
            break;
        }
    }
}

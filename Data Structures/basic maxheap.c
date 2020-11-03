#include<stdio.h>

int heapsize=0;
int arr_heap[10];

void swap(int *a,int *b)
{
    int *t;
    t=*a;
    *a=*b;
    *b=t;
}
int getrightchild(int i)
{
    if((2*i+1)>=1 && (2*i+1)<heapsize)
        return (2*i+1);
}
int getleftchild(int i)
{
    if((2*i)>=1 && (2*i)<heapsize)
        return 2*i;
}
int getparent(int i)
{
    if(i>=1 && i<heapsize)
        return i/2;
}
void max_heapify(int i)
{
    int largest=i;
    int leftchild=getleftchild(i);
    int rightchild=getrightchild(i);
    if(leftchild>=1 && leftchild<=heapsize)
    {
        if(arr_heap[leftchild]>arr_heap[largest])
            largest=leftchild;
    }
    else
        return;
    if(rightchild>=1 && rightchild<=heapsize)
    {
        if(arr_heap[rightchild]>arr_heap[largest])
            largest=rightchild;
    }
    else
        return;
    if(largest!=i)
    {
        swap(&arr_heap[largest],&arr_heap[i]);
        max_heapify(largest);
    }
}
void insert(int key)
{
    heapsize++;
    arr_heap[heapsize]=key;
    int i=heapsize;
    while(i>=1 && arr_heap[i]>arr_heap[getparent(i)])
    {
        swap(&arr_heap[i],&arr_heap[getparent(i)]);
        i=getparent(i);
    }
}
void deletekey()
{
    arr_heap[1]=arr_heap[heapsize];
    heapsize--;
    max_heapify(1);
}
void print_heap()
{
    int i;
    for(i=1;i<=heapsize;i++)
        printf("%d ",arr_heap[i]);
    printf("\n");
}
void main()
{
  insert(20);
  insert(15);
  insert(8);
  insert(10);
  insert(5);
  insert(7);
  insert(6);
  insert(2);
  insert(9);
  insert(1);

  print_heap();
  deletekey();
  print_heap();
  deletekey();
  print_heap();

}

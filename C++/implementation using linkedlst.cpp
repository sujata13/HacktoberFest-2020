#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node* link;
};
struct Node* top=NULL;

void push(int x)
{
	Node* newnode=(Node*)malloc(sizeof(struct Node));
	newnode->data=x;
	newnode->link=top;
	top=newnode;
}
void pop()
{
	Node* temp;
	
	
	
		temp=top;
		top=top->link;
		free(temp);
	
}
bool Isempty()
{
	if(top==NULL)
	return 0;
	else
	return 1;
}
void show()
{
	
		while(top!=NULL)
		{
			cout<<top->data<<" "<<endl;
			top=top->link;
		}
	
}
int main()
{
	push(10);
	push(20);
	push(30);
	push(40);
	push(50);
	push(60);
	show();
	pop();
	pop();
	show();
	
	
}

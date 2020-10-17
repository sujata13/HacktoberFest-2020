#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

#define MAX 500

char stack[MAX];
int t= -1;

void push(char ele)
{stack[++t] = ele;
}

char pop()
{return stack[t--];
}

int palind(char str[])
{int length = strlen(str);
 int i, mid = length / 2;

 for(i = 0; i < mid; i++) 
    push(str[i]);

 if(length % 2 != 0) 
    i++;

 while (str[i] != '\0')
    {char ele = pop();
	 if (ele != str[i])
        return 0;
     i++;
    }
 return 1;
}

int main()
{char str[MAX];

 printf("Enter a String of your choice:");
 gets(str);

 if(palind(str))
   printf("Yes");
 else 
   printf("No");
    
 return 0;
}

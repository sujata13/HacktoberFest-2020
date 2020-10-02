#include<stdio.h>
int main ()
{
  int flag = 0;
  char ch1[20], ch2[20];
  char *ptr1, *ptr2;
  ptr1 = ch1;
  ptr2 = ch2;
  printf ("\nEnter string-1\n");
  scanf ("%s", ch1);
  printf ("\nEnter string-2\n");
  scanf ("%s", ch2);
  printf ("\n\nStr 1 = %s \n", ch1);
  printf ("\n\nStr 2 = %s \n", ch2);
  while (*(ptr1) != '\0')
    {
      if (*(ptr1) != *(ptr2))
	{
	  flag = 1;
	  break;
	}
      ptr1++;
      ptr2++;
    }
  if (flag == 0)
    {
      printf ("\n Strings are EQUAL \n");
    }
  else
    {
      printf ("\n String are NOT EQUAL \n");
    }
  return 0;
}

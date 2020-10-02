/* When you are using this program kindly change the .java file to quicksorts.java then your program will run successfully. Happy coding*/


import java.io.*;
import java.util.*;
public class quicksorts{
void quicksort(int a[],int low,int high)
 {
   int pivot,i,j,temp;
   if(low<high)
   {
   pivot=low;
   i=low;
   j=high;
   while(i<j)
    {
      while(a[i]<=a[pivot] && i<=high)
      {
      i++;
      }
      while(a[j]>a[pivot] && j>=low)
      {
      j--;
      }
      if(i<j)
      {
      temp=a[i];
      a[i]=a[j];
      a[j]=temp;
      }
    }
    temp=a[j];
    a[j]=a[pivot];
    a[pivot]=temp;
    quicksort(a,low,j-1);
    quicksort(a,j+1,high);
    }
 }
public static void main(String args[])
{
int a[] = new int[50];
int n,i,t;
Scanner sc = new Scanner(System.in);
System.out.println("Enter the test cases:");
t = sc.nextInt();
while(t>0){
System.out.println("enter number of elemnts that u want to store:");
n = sc.nextInt();
System.out.println("enter the element:");
for(i=0;i<n;i++)
{
a[i] = sc.nextInt();
}
quicksorts obj = new quicksorts();
obj.quicksort(a,0,n-1);

System.out.println("elments after sorting:");
for(i=0;i<n;i++)
{
System.out.println("\t"+a[i]);
}
t--;
}
}
}
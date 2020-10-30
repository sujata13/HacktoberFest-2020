#include<iostream>
using namespace std;
int main(){
char arr[100];
cin.getline(arr,100);
int n = strlen(arr);
int start = 0;
int end = n-1;
while(start<end){
     char temp = arr[start];
     arr[start] = arr[end];
     arr[end] = temp;
     start++;
     end--;
}
cout<<arr<<endl;
}
/* another way to reverse a string would be to use the arr.reverse() function available in the C++ STL class. */
/* editing just to check how to create a PR */

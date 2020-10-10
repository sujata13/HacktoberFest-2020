#include<stdio.h>
int max(int arr[],int n)
{
    int maximum=arr[0];
    for(int i=1;i<n;i++)
        {
            if(arr[i]>maximum)
                maximum=arr[i];
        }
    return maximum;
}
void countsort(int arr[],int n,int place)
{
    int temp[n];
    int count[10];
    for(int i=0;i<10;i++)
        count[i]=0;
    for(int i=0;i<n;i++)
        count[(arr[i]/place)%10]++;
    for(int i=1;i<10;i++)
        count[i] += count[i-1];
    for(int i=n-1;i>=0;i--)
        temp[--count [ (arr[i] / place) % 10]] = arr[i];
    for(int i=0;i<n;i++)
        arr[i]=temp[i];
}
void radixsort(int arr[],int n)
{
    int maximum=max(arr,n);
    int place;
    for(place = 1 ; maximum/place > 0 ; place = place * 10 )
        countsort(arr,n,place);
}
int main()
{
    int n;
    printf("ENTER THE NUMBERS WHICH U WANT TO SORT : ");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    radixsort(arr,n);
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
}
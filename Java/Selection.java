package com.company;

public class Selection
{
    void SelectionSort(int arr[] , int n)
    {
        //minimum number is selected and moved in front
        for (int i=0 ; i<n-1 ; i++)
        {
            int min = i;
            for (int j=i+1 ; j<n  ; j++)
            {
                if (arr[j] < arr[min])
                    min = j;
            }
          int temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }
    }
    void print(int arr[] , int n)
    {
        for (int i=0 ; i<n ; i++)
            System.out.print(arr[i] + " ");

    }

    public static void main(String[] args) {
        int arr[]= {20, 35, -15, 7, 550, 1, -22 };
        int n= arr.length;
        Selection obj = new Selection();
        obj.SelectionSort(arr,n);
        System.out.println("Sorted Array");
        obj.print(arr,n);
    }
}

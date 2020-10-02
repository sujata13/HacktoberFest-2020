    
try:
# Python program forBubble Sort 
  
    def bubbleSort(arr): 
        length_of_arr = len(arr) 
      
        # Traverse through all array elements 
        for i in range(length_of_arr): 
      
            # Last i elements are already in place 
            for j in range(0, length_of_arr-i-1): 
      
                # traverse the array from 0 to n-i-1 
                # Swap if the element found is greater 
                if(arr[j] > arr[j+1]):
                    temp=arr[j]
                    arr[j]=arr[j+1]
                    arr[j+1]=temp

    n=int(input("Enter length of arr:"))
    arr=list(map(int,input().strip().split()))[:n]
    bubbleSort(arr) 
      
    print ("Sorted array is:") 
    for i in range(len(arr)): 
        print(arr[i],end=" ")
    print()
            
except:
    pass
    
"""
Enter length of arr:5
3 5 10 8 33
Sorted array is:
3 5 8 10 33 

"""
